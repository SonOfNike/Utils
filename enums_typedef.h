#pragma once

#include <cstdint>

enum class exchange {NYSE = 1, NASD, ARCA, BATS, EDGX, EDGA};

enum class side {BUY, SELL, NONE};

typedef int64_t Price;
typedef int32_t Shares;
typedef uint64_t Timestamp;
typedef int32_t OrderId;
typedef int32_t SymbolId;