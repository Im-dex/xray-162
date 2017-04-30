#ifndef TRAFFIC_OPTIMIZATION_INCLUDED
#define TRAFFIC_OPTIMIZATION_INCLUDED

#include "../xrCore/lzo_compressor.h"

namespace compression
{


struct lzo_dictionary_buffer
{
	lzo_bytep	data;
	lzo_uint	size;
}; //struct lzo_dictionary_buffer

void init_lzo	(u8* & dest_wm, u8* & wm_buffer, lzo_dictionary_buffer & dest_dict);
void deinit_lzo	(u8* & src_wm_buffer, lzo_dictionary_buffer & src_dict);

} //namespace compression

enum enum_traffic_optimization
{
	eto_none				=	0,
	eto_lzo_compression		=	1 << 1,
	eto_last_change			=	1 << 2,
};//enum enum_traffic_optimization

extern u32	g_sv_traffic_optimization_level;

#endif//#ifndef TRAFFIC_OPTIMIZATION_INCLUDED