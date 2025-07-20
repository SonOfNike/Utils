#include "SymbolIDManager.h"
#include "simdjson/simdjson.h"

SymbolIDManager* SymbolIDManager::uniqueInstance = nullptr;

SymbolIDManager* SymbolIDManager::getInstance(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new SymbolIDManager();
    }
    return uniqueInstance;
}

void SymbolIDManager::startUp(){
    next_id = 0;
    simdjson::dom::parser parser;
    simdjson::dom::element doc = parser.load("/home/git_repos/Utils/symbols.json");
    for(auto symbol : doc["symbols"])
    {
        string_to_id[std::string(symbol)] = next_id;
        id_to_string[next_id] = std::string(symbol);
        next_id++;
    }
}

void SymbolIDManager::shutDown(){
    
}

SymbolId SymbolIDManager::getID(std::string _ticker){
    return string_to_id[_ticker];
}

SymbolId SymbolIDManager::getID(std::string_view _ticker){
    return string_to_id[std::string(_ticker)];
}

std::string SymbolIDManager::getTicker(SymbolId _sym_id){
    return id_to_string[_sym_id];
}