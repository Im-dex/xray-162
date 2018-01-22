#pragma once

// refs
struct xr_token;

XRCORE_API int _GetItemCount(LPCSTR, char separator = ',');
XRCORE_API LPSTR _GetItem(LPCSTR, int, LPSTR, u32 const dst_size, char separator = ',', LPCSTR = "",
                          bool trim = true);

template <int count>
LPSTR _GetItem(LPCSTR src, int index, char (&dst)[count], char separator = ',',
               LPCSTR def = "", bool trim = true) {
    return _GetItem(src, index, dst, count, separator, def, trim);
}

XRCORE_API LPSTR _GetItems(LPCSTR, int, int, LPSTR, char separator = ',');
XRCORE_API LPCSTR _SetPos(LPCSTR src, u32 pos, char separator = ',');
XRCORE_API LPCSTR _CopyVal(LPCSTR src, LPSTR dst, char separator = ',');
XRCORE_API LPSTR _Trim(LPSTR str);
XRCORE_API LPSTR _TrimLeft(LPSTR str);
XRCORE_API LPSTR _TrimRight(LPSTR str);
XRCORE_API LPSTR _ChangeSymbol(LPSTR name, char src, char dest);
XRCORE_API u32 _ParseItem(LPCSTR src, xr_token* token_list);
XRCORE_API u32 _ParseItem(LPSTR src, int ind, xr_token* token_list);
XRCORE_API LPSTR _ReplaceItem(LPCSTR src, int index, LPCSTR new_item, LPSTR dst, char separator);
XRCORE_API LPSTR _ReplaceItems(LPCSTR src, int idx_start, int idx_end, LPCSTR new_items, LPSTR dst,
                               char separator);
XRCORE_API void _SequenceToList(LPSTRVec& lst, LPCSTR in, char separator = ',');
XRCORE_API void _SequenceToList(SStringVec& lst, LPCSTR in, char separator = ',');

XRCORE_API std::string& _Trim(std::string& src);
XRCORE_API std::string& _TrimLeft(std::string& src);
XRCORE_API std::string& _TrimRight(std::string& src);
XRCORE_API std::string& _ChangeSymbol(std::string& name, char src, char dest);
XRCORE_API LPCSTR _CopyVal(LPCSTR src, std::string& dst, char separator = ',');
XRCORE_API LPCSTR _GetItem(LPCSTR src, int, std::string& p, char separator = ',', LPCSTR = "",
                           bool trim = true);
XRCORE_API std::string _ListToSequence(const SStringVec& lst);
