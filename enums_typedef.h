#pragma once

enum exchange {NYSE = 1, NASD, ARCA, BATS, EDGX, EDGA};

enum side {BUY, SELL, NONE};

typedef int Price;
typedef int Shares;
typedef int Timestamp;
typedef int OrderId;