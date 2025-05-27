#pragma once

enum class exchange {NYSE = 1, NASD, ARCA, BATS, EDGX, EDGA};

enum class side {BUY, SELL, NONE};

typedef int Price;
typedef int Shares;
typedef int Timestamp;
typedef int OrderId;