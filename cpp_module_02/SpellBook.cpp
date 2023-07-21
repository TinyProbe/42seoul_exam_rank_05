#include "SpellBook.hpp"

SpellBook::SpellBook() :
    list() {}

SpellBook::~SpellBook() {
    for (std::unordered_map<std::string, ASpell *>::iterator it = list.begin();
        it != list.end(); ++it) { delete it->second; }
    list.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
    if (spell == NULL) { return; }
    std::unordered_map<std::string, ASpell *>::iterator it = list.find(spell->getName());
    if (it != list.end()) {
        delete it->second;
        it->second = spell->clone();
    } else {
        list[spell->getName()] = spell->clone();
    }
}
void SpellBook::forgetSpell(std::string const &name) {
    std::unordered_map<std::string, ASpell *>::iterator it = list.find(name);
    if (it != list.end()) {
        delete it->second;
        list.erase(it);
    }
}
ASpell *SpellBook::createSpell(std::string const &name) {
    std::unordered_map<std::string, ASpell *>::iterator it = list.find(name);
    if (it != list.end())
        return it->second;
    return NULL;
}

