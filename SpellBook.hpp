#ifndef SPELLBOOK_H
#define	SPELLBOOK_H

#include <vector>
#include "ASpell.hpp"

class SpellBook
{

private:
	std::vector<ASpell *> arr;

	SpellBook(const SpellBook &other);

public:
	SpellBook();
	~SpellBook();
	SpellBook& operator=(const SpellBook &other);

	void learnSpell(ASpell *spell);
	std::vector<ASpell *> getBook();
	void forgetSpell(std::string const &spell_name);
	ASpell *createSpell(std::string const &spell_name);
};

#endif