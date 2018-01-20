#pragma once

#include "light.h"

class light_Package {
public:
    std::vector<light*> v_point;
    std::vector<light*> v_spot;
    std::vector<light*> v_shadowed;

public:
    void clear();
    void sort();
};
