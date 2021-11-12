#include "ASpell.hpp"

ASpell::ASpell(const std::string& name_, const std::string& effects_)
{
	name = name_;
	effects = effects_;
}

ASpell::ASpell (const ASpell &other)
{
	name = other.getName();
	effects = other.getEffects();
}

ASpell& ASpell::operator=(const ASpell &other)
{
	name = other.getName();
	effects = other.getEffects();
	return *this;
}

std::string ASpell::getName() const { return name; }
std::string ASpell::getEffects() const { return effects; }

void	ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}

ASpell::~ASpell() {};