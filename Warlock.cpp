#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title):
				name(name), title(title) 
{
	std::cout << name << ": This looks like another boring day.\n";
	book = new SpellBook();
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!\n";
	delete book;
};

std::string const &Warlock::getName() const { return name; }
std::string const &Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const &title) { this->title = title; }

void Warlock::introduce() const
{
	std::cout << name << ": I am "  << name << ", " << title << "!\n";
}

void	Warlock::learnSpell(ASpell* spell)
{
	book->learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spell_name)
{
	book->forgetSpell(spell_name);
}

void	Warlock::launchSpell(std::string spell_name, ATarget& target)
{
	for (size_t i = 0; i < book->getBook().size(); i++)
	{
		if ((book->getBook())[i]->getName() == spell_name)
		{			
			(book->getBook())[i]->launch(target);
			return;
		}
	}	
}