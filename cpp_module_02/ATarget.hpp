#pragma once
#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

class ASpell;
class ATarget {
    std::string type;

public:
    ATarget();
    ATarget(ATarget const &rhs);
    ATarget(std::string const &type);
    virtual ~ATarget();
    virtual ATarget &operator=(ATarget const &rhs);

    virtual std::string const &getType() const;
    virtual void getHitBySpell(ASpell const &spell) const;

    virtual ATarget *clone() const = 0;

};

#endif

