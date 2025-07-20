#pragma once

#include "enums_typedef.h"
#include <unordered_map>
#include <string_view>
#include <string>

class SymbolIDManager {
private:
    std::unordered_map<SymbolId ,std::string> id_to_string;

    SymbolId next_id = 0;

    static SymbolIDManager* uniqueInstance;
    SymbolIDManager(){;}

public:
    std::unordered_map<std::string, SymbolId> string_to_id;

    static SymbolIDManager* getInstance();
    void startUp();
    void shutDown();
    SymbolId getID(std::string _ticker);
    SymbolId getID(std::string_view _ticker);
    std::string getTicker(SymbolId _sym_id);
};