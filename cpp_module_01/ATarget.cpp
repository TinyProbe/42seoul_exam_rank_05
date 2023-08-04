#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() :
	type() {}
ATarget::ATarget(ATarget const &rhs) { *this = rhs; }
ATarget::ATarget(std::string const &type) :
	type(type) {}
ATarget::~ATarget() {}
ATarget &ATarget::operator=(ATarget const &rhs) {
	if (this == &rhs) { return *this; }
	type = rhs.type;
	return *this;
}

std::string const &ATarget::getType() const { return type; }
void ATarget::getHitBySpell(ASpell const &spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}

