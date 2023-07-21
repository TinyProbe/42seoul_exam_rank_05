#pragma once
#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>
#include "ASpell.hpp"

class SpellBook {
    std::unordered_map<std::string, ASpell *> list;

private:
    SpellBook(SpellBook const &rhs);
    SpellBook &operator=(SpellBook const &rhs);

public:
    SpellBook();
    virtual ~SpellBook();

    virtual void learnSpell(ASpell *spell);
    virtual void forgetSpell(std::string const &name);
    virtual ASpell *createSpell(std::string const &name);

};

#endif

