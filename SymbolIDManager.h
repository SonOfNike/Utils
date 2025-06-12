#pragma once

#include "enums_typedef.h"
#include <unordered_map>
#include <string_view>

class SymbolIDManager {
private:
    std::unordered_map<std::string_view, SymbolId> string_to_id;
    std::unordered_map<SymbolId ,std::string_view> id_to_string;

    SymbolId next_id = 0;

    static SymbolIDManager* uniqueInstance;
    SymbolIDManager(){;}

public:
    static SymbolIDManager* getInstance();
    void startUp();
    void shutDown();
    SymbolId getID(std::string_view _ticker);
    std::string_view getTicker(SymbolId _sym_id);
};