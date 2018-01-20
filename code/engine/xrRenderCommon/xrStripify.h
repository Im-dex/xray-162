#pragma once

void xrStripify(std::vector<u16>& indices, std::vector<u16>& perturb, int iCacheSize,
                int iMinStripLength);
int xrSimulate(std::vector<u16>& indices, int iCacheSize);
