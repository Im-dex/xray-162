#pragma once


typedef shared_str INFO_DATA;
using KNOWN_INFO_VECTOR = xr_vector<INFO_DATA>;

class CFindByIDPred
{
public:
	CFindByIDPred(shared_str element_to_find) {element = element_to_find;}
	IC bool operator () (const INFO_DATA& data) const {return data == element;}
private:
	shared_str element;
};
