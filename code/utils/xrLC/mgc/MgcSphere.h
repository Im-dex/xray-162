// Magic Software, Inc.
// http://www.magic-software.com
// Copyright (c) 2000-2002.  All Rights Reserved
//
// Source code from Magic Software is supplied under the terms of a license
// agreement and may not be copied or disclosed except in accordance with the
// terms of that agreement.  The various license agreements may be found at
// the Magic Software web site.  This file is subject to the license
//
// FREE SOURCE CODE
// http://www.magic-software.com/License/free.pdf

#ifndef MGCSPHERE_H
#define MGCSPHERE_H

#include "MgcVector3.h"

namespace Mgc {

class Sphere {
public:
    Sphere() {}

    Vector3& Center() { return m_kCenter; }
    const Vector3& Center() const { return m_kCenter; }

    Real& Radius() { return m_fRadius; }
    const Real& Radius() const { return m_fRadius; }

protected:
    Vector3 m_kCenter;
    Real m_fRadius;
};

} // namespace Mgc

#endif
