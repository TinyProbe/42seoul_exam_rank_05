#pragma once
#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

class ATarget;
class ASpell {
    std::string name;
    std::string effects;

public:
    ASpell();
    ASpell(ASpell const &rhs);
    ASpell(std::string const &name, std::string const &effects);
    virtual ~ASpell();
    virtual ASpell &operator=(ASpell const &rhs);

    virtual std::string const &getName() const;
    virtual std::string const &getEffects() const;

    virtual void launch(ATarget const &targ) const;

    virtual ASpell *clone() const = 0;

};

#endif

