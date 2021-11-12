#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) : type(type){};

ATarget::ATarget(const ATarget &other) { type = other.getType(); }

ATarget &ATarget::operator=(const ATarget &other)
{
	type = other.getType();
	return *this;
}

ATarget::~ATarget(){};

const std::string &ATarget::getType() const { return type; }

void 	ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!\n";
}