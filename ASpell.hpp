#ifndef ASpell_H
#define	ASpell_H

#include <string>
#include <iostream>
class ATarget;
#include "ATarget.hpp"

class ASpell
{
protected:
	std::string	name;
	std::string	effects;
public:
	ASpell(const std::string& name_, const std::string& effects_);
	ASpell (const ASpell &other);
	ASpell &operator=(const ASpell &other);

	std::string getName() const;
	std::string getEffects() const;
	virtual ASpell *clone() = 0;
	void	launch(const ATarget& target) const;
	virtual ~ASpell();
};


#endif