#include <stdio.h>
#include <vector>
#include <algorithm>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma warning( disable: 193 128 810 )
#include "../xrcompress/lzo/lzo1x.h"
#include "../xrcompress/lzo/lzo1y.h"
#pragma warning( default: 193 128 810 )

using namespace std;


//==============================================================================

class
StopWatch  
{
public:                               
                    StopWatch()     { ::QueryPerformanceFrequency( &_freq ); }

    void            start()         { ::QueryPerformanceCounter( &_start_time ); }
    void            stop()          { ::QueryPerformanceCounter( &_stop_time ); }
    
    double          cur_time() const
                    {
                        LARGE_INTEGER   t; QueryPerformanceCounter( &t );
                        return ((t.QuadPart - _start_time.QuadPart) * 1000.0) / _freq.QuadPart; 
                    }
    double          time() const    // in milliseconds
                    { 
                        return ((_stop_time.QuadPart - _start_time.QuadPart) * 1000.0) / _freq.QuadPart; 
                    }


private:

    LARGE_INTEGER   _freq;
    LARGE_INTEGER   _start_time;
    LARGE_INTEGER   _stop_time;
};

//------------------------------------------------------------------------------

struct
BlockInfo
{
    unsigned    size;
    unsigned    count;

    float       min_time;
    float       max_time;
    float       avg_time;

    float       min_ratio;
    float       max_ratio;
    float       avg_ratio;


    float       total_time;
    float       total_ratio;


                BlockInfo( unsigned sz=0 )
                  : size(sz),
                    count(0),
                    min_time(1000.0f), max_time(0), avg_time(0),
                    min_ratio(1.0f), max_ratio(0), avg_ratio(0),
                    total_time(0),
                    total_ratio(0)
                {}

    class
    EqualSize
    {
    public:
                EqualSize( unsigned sz )            : _sz(sz) {}
        bool    operator() ( const BlockInfo& bi )  { return bi.size == this->_sz; }


    private:
    
        unsigned    _sz;
    };

    static bool GreaterSize( const BlockInfo& i1, const BlockInfo& i2 ) 
                {
                    return i1.size > i2.size;
                }
};


//------------------------------------------------------------------------------

static char*            _LZOWrkMem                  = nullptr;
static uint8_t*         _LZO_Dict                   = nullptr;
static unsigned         _LZO_Dict_Sz                = 0;
static const char*      _DefaultDictName            = "LZO.dic";

static vector<BlockInfo>    _LZO_BlockInfo;
static unsigned             _LZO_TotalUncompressed  = 0;
static unsigned             _LZO_TotalCompressed    = 0;

//------------------------------------------------------------------------------

static void
_InitLZO( const char* dic_name=_DefaultDictName )
{
    lzo_init();
    _LZOWrkMem = new char[LZO1X_999_MEM_COMPRESS+16];
    _LZOWrkMem = (char*)((unsigned int)(_LZOWrkMem+16) & (~(16-1)));

    FILE*   dic = fopen( dic_name, "rb" );

    if( dic )
    {
        fseek( dic, 0, SEEK_END );
        
        _LZO_Dict_Sz = ftell( dic );        
        _LZO_Dict    = new uint8_t[_LZO_Dict_Sz];
        
        fseek( dic, 0, SEEK_SET );
        fread( _LZO_Dict, _LZO_Dict_Sz, 1, dic );
        fclose( dic );

        printf( "using LZO-dict \"%s\"\n", dic_name );
    }
}


//------------------------------------------------------------------------------
extern void save_dictionary();

//------------------------------------------------------------------------------

static bool
_ProcessFile_LZO( const char* file_name )
{
    bool    success = false;
    FILE*   file    = fopen( file_name, "rb" );

    if( file )
    {
        // read data
        
        fseek( file, 0, SEEK_END );

        unsigned    src_size    = ftell( file );
        uint8_t*	src_data    = new uint8_t[src_size];

        fseek( file, 0, SEEK_SET );
        fread( src_data, src_size, 1, file );
        fclose( file );


        // compress it

        lzo_uint    comp_size = src_size * 4;
        uint8_t*    comp_data = new uint8_t[comp_size];

        memset( comp_data, 0xCC, comp_size );

        StopWatch   timer;

        timer.start();
        if( _LZO_Dict )
        {
            lzo1x_999_compress_dict( src_data, src_size, comp_data, &comp_size, 
                                     _LZOWrkMem, _LZO_Dict, _LZO_Dict_Sz
                                   );
        }
        else
        {
            lzo1x_999_compress( src_data, src_size, comp_data, &comp_size, _LZOWrkMem );            
        }
        timer.stop();
        printf( "LZO  :  %2.0f%% %1.5fms  %u->%u", 
                100.0f*float(comp_size)/float(src_size),
                (float)timer.time(),
                (unsigned)src_size, (unsigned)comp_size
              );

        _LZO_TotalUncompressed  += src_size;
        _LZO_TotalCompressed    += (comp_size < src_size)  ? comp_size  : src_size;


        // decompress it

        lzo_uint    uncomp_size = src_size * 4;
        uint8_t*    uncomp_data = new uint8_t[uncomp_size];

        memset( uncomp_data, 0xDD, uncomp_size );
        if( _LZO_Dict )
        {
            lzo1x_decompress_dict_safe( comp_data, comp_size, uncomp_data, &uncomp_size, 
                                        NULL, _LZO_Dict, _LZO_Dict_Sz
                                      );
        }
        else
        {
            lzo1x_decompress( comp_data, comp_size, uncomp_data, &uncomp_size, NULL );
        }


        // compare

        bool        ok      = true;
        unsigned    err_b   = 0;
        
        for( const uint8_t* s=src_data,*u=uncomp_data; s!=src_data+src_size; ++s, ++u )
        {
            if( *s != *u )
            {
                ok      = false;
                err_b   = s-src_data;
                break;
            }
        }
        if( ok )    printf( " OK\n" );
        else        printf( " ERROR (#%u  %02X != %02X)\n", err_b, src_data[err_b]&0xFF, uncomp_data[err_b]&0xFF );

        success = ok;


        // update stats

        vector<BlockInfo>::iterator i = find_if( _LZO_BlockInfo.begin(), _LZO_BlockInfo.end(), BlockInfo::EqualSize(src_size) );

        if( i == _LZO_BlockInfo.end() )
        {
            _LZO_BlockInfo.push_back( BlockInfo(src_size) );            
            i = _LZO_BlockInfo.end()-1;
        }

        ++i->count;
        i->total_time   += (float)timer.time();
        i->total_ratio  += 100.0f*float(comp_size)/float(src_size);


        // clean-up
        
        delete[] uncomp_data;
        delete[] comp_data;
        delete[] src_data;
    }     // if file open

    return success;
}


//------------------------------------------------------------------------------

static bool
_ProcessFile( const char* file_name )
{
    printf( "\n%s\n", file_name );
    return _ProcessFile_LZO( file_name );
}


//==============================================================================
//
//  entry-point here
//

int
main( int argc, char* argv[] )
{
    const char* src_name = (argc>1)  ? argv[1]  : 0;
    const char* dic_name = _DefaultDictName;

    for( int i=1; i<argc; ++i )
    {
        const char* arg = argv[i];
        
        if( arg[0] == '-'  ||  arg[0] == '/' )
        {
            if( !_strnicmp( arg+1, "dic", 3 ) ) dic_name = arg+1+3+1;
        }
    }


    if( argc > 1 )
    {
        _InitLZO( dic_name );

        WIN32_FIND_DATA     found_data;
        HANDLE              handle      = ::FindFirstFile( src_name, &found_data );


        // extract dir-part of wildcard

        char                dir[MAX_PATH]   = ".";
        const char*         end             = src_name + strlen(src_name)-1;
    
        while( end > src_name )
        {
            if( *end == '\\'  ||  *end == '/' )
                break;

            --end;
        }

        if( *end == '\\'  ||  *end == '/' )
        {
            strncpy( dir, src_name, end-src_name );
            dir[end-src_name] = '\0';
        }


        // process files
        
        if( handle != reinterpret_cast<HANDLE>(INVALID_HANDLE_VALUE) )
        {
            BOOL    rv      = TRUE;
            bool    all_ok  = true;

            while( rv )
            {
                if( !(found_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
                {
                    char    name[2048];

                    _snprintf( name, sizeof(name), "%s\\%s", dir, found_data.cFileName );
                    if( !_ProcessFile( name ) )
                    {
                        all_ok = false;
                        break;
                    }
                }

                rv = ::FindNextFile( handle, &found_data );
            }

            if( all_ok )    printf( "\nAll OK\n" );
            else            printf( "\nERROR(S) ocurred\n" );
        }
        ::FindClose( handle );


        // dump stats
        for( unsigned i=0; i<_LZO_BlockInfo.size(); ++i )
        {
            _LZO_BlockInfo[i].avg_ratio = _LZO_BlockInfo[i].total_ratio / _LZO_BlockInfo[i].count;
            _LZO_BlockInfo[i].avg_time  = _LZO_BlockInfo[i].total_time / _LZO_BlockInfo[i].count;
        }
        sort( _LZO_BlockInfo.begin(), _LZO_BlockInfo.end(), BlockInfo::GreaterSize );


        printf( "\n==========\nstats:\n" );
        for( unsigned i=0; i<_LZO_BlockInfo.size(); ++i )
        {
            printf( "LZO :  %2.1f%%  %-2.3fms\n", _LZO_BlockInfo[i].avg_ratio, _LZO_BlockInfo[i].avg_time );
        }

        printf( "\nTOTAL\n" );
        printf( "LZO  :  %2.1f%%  %u -> %u\n", 
                100.0f*float(_LZO_TotalCompressed)/float(_LZO_TotalUncompressed),
                _LZO_TotalUncompressed, _LZO_TotalCompressed
              );

    } // if( argc > 1 )

	return 0;
}

