#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() :
    name(),
    effects() {}

ASpell::ASpell(ASpell const &rhs) { *this = rhs; }

ASpell::ASpell(std::string const &name, std::string const &effects) :
    name(name),
    effects(effects) {}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(ASpell const &rhs) {
    if (this == &rhs) { return *this; }
    name = rhs.name;
    effects = rhs.effects;
    return *this;
}

std::string const &ASpell::getName() const { return name; }
std::string const &ASpell::getEffects() const { return effects; }

void ASpell::launch(ATarget const &targ) const { targ.getHitBySpell(*this); }

