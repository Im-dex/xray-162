#pragma once

#include <utility>

#define IMDEX_FWD(value) std::forward<decltype(value)>(value)
