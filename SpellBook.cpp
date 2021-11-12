#include "SpellBook.hpp"

SpellBook::SpellBook(){};

SpellBook::~SpellBook()
{
	std::vector<ASpell *>::iterator it_begin = arr.begin();
	std::vector<ASpell *>::iterator it_end = arr.end();
	for (; it_begin != it_end; it_begin++)
		delete *it_begin;
	arr.clear();
}

SpellBook& SpellBook::operator=(const SpellBook &other)
{
	std::vector<ASpell *>::iterator it_begin = arr.begin();
	std::vector<ASpell *>::iterator it_end = arr.end();
	for (; it_begin != it_end; it_begin++)
		delete *it_begin;
	arr.clear();
	for (size_t i = 0; i < other.arr.size(); i++)
	{
		arr.push_back(other.arr[i]);
	}
	return *this;
}

void SpellBook::learnSpell(ASpell *spell)
{
	std::vector<ASpell *>::iterator it_begin = arr.begin();
	std::vector<ASpell *>::iterator it_end = arr.end();
	if (spell)
	{
		for (; it_begin != it_end; it_begin++)
		{
			if ((*it_begin)->getName() == spell->getName())
				return;
		}
		arr.push_back(spell->clone());
	}
	
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
	std::vector<ASpell *>::iterator it_begin = arr.begin();
	std::vector<ASpell *>::iterator it_end = arr.end();
	for (; it_begin != it_end; it_begin++)
	{
		if ((*it_begin)->getName() == spell_name)
		{
			delete *it_begin;
			arr.erase(it_begin);
			return;
		}
	}
}

ASpell *SpellBook::createSpell(std::string const &spell_name)
{
	std::vector<ASpell *>::iterator it_begin = arr.begin();
	std::vector<ASpell *>::iterator it_end = arr.end();
	for (; it_begin != it_end; it_begin++)
	{
		if ((*it_begin)->getName() == spell_name)
			return ((*it_begin)->clone());
	}
	return NULL;
}

std::vector<ASpell *> SpellBook::getBook()
{
	return arr;
}