#pragma once

#include <cstdint>

enum class exchange {NYSE = 1, NASD, ARCA, BATS, EDGX, EDGA};

enum class order_type {VISIBLEARCA, VISIBLENYSE, HIDDENNASD, NONE};

enum class side {BUY, SELL, NONE};

typedef int64_t Price;
typedef int32_t Shares;
typedef uint64_t Timestamp;
typedef int64_t MyOrderId;
typedef int16_t SymbolId;