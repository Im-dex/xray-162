#pragma once

#include "ode/include/ode/common.h"
#include "ode/include/ode/mass.h"
#include "ode/include/ode/objects.h"

inline bool dV_valid(const dReal* v) { return xr::valid(v[0]) && xr::valid(v[1]) && xr::valid(v[2]); }

inline bool dM_valid(const dReal* m) {
    return xr::valid(m[0]) && xr::valid(m[1]) && xr::valid(m[2]) && xr::valid(m[4]) && xr::valid(m[5]) &&
           xr::valid(m[6]) && xr::valid(m[8]) && xr::valid(m[9]) && xr::valid(m[10]);
}

inline bool dV4_valid(const dReal* v4) {
    return xr::valid(v4[0]) && xr::valid(v4[1]) && xr::valid(v4[2]) && xr::valid(v4[3]);
}
inline bool dQ_valid(const dReal* q) { return dV4_valid(q); }
inline bool dMass_valide(const dMass* m) { return xr::valid(m->mass) && dV_valid(m->c) && dM_valid(m->I); }
inline bool dBodyStateValide(const dBodyID body) {
    return dM_valid(dBodyGetRotation(body)) && dV_valid(dBodyGetPosition(body)) &&
           dV_valid(dBodyGetLinearVel(body)) && dV_valid(dBodyGetAngularVel(body)) &&
           dV_valid(dBodyGetTorque(body)) && dV_valid(dBodyGetForce(body));
}