#pragma once

////////////////////////////////////////////////////////////////////////
const double FEQ_EPS = 1e-6;
const double FEQ_EPS2 = 1e-12;
inline bool FEQ(double a, double b, double e = FEQ_EPS) { return xr::abs(a - b) < e; }
inline bool FEQ2(double a, double b, double e = FEQ_EPS2) { return xr::abs(a - b) < e; }
////////////////////////////////////////////////////////////////////////
