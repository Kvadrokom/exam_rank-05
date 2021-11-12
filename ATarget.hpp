#ifndef ATARGET_H
#define	ATARGET_H
class ASpell;
#include "ASpell.hpp"

class ATarget
{
private:
	std::string type;

public:
	ATarget(const std::string& type);
	ATarget(const ATarget &other);
	ATarget &operator=(const ATarget &other);
	virtual ~ATarget();

	const std::string &getType() const;
	virtual ATarget *clone() = 0;
	void 	getHitBySpell(const ASpell &spell) const;
	
};

#endif