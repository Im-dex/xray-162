#ifndef xrMemory_POOLh
#define xrMemory_POOLh
#pragma once

class xrMemory;

class	MEMPOOL
{
#ifdef DEBUG_MEMORY_MANAGER
	friend class xrMemory;
#endif // DEBUG_MEMORY_MANAGER
private:
	std::recursive_mutex	cs;
	u32					s_sector;		// large-memory sector size
	u32					s_element;		// element size, for example 32
	u32					s_count;		// element count = [s_sector/s_element]
	u32					s_offset;		// header size
	u32					block_count;	// block count
	u8*					list;
private:
	ICF void**			access			(void* P)	{ return (void**) ((void*)(P));	}
	void				block_create	();
public:
	void				_initialize		(u32 _element, u32 _sector, u32 _header);
	
	ICF u32				get_block_count	()	{ return block_count; }
	ICF u32				get_element		()	{ return s_element; }

	ICF void*			create			()
	{
        std::lock_guard<decltype(cs)> lock(cs);
		if (0==list)	block_create();

		void* E			= list;
		list			= (u8*)*access(list);
		return			E;
	}
	ICF void			destroy			(void* &P)
	{
        std::lock_guard<decltype(cs)> lock(cs);
		*access(P)		= list;
		list			= (u8*)P;
	}
};
#endif
