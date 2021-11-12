#ifndef TARGETGEN_H
#define	TARGETGEN_H

#include <vector>
#include "ASpell.hpp"

class TargetGenerator
{

private:
	std::vector<ATarget *> arr;

	TargetGenerator(const TargetGenerator &other);
public:
	TargetGenerator();
	~TargetGenerator();
	TargetGenerator& operator=(const TargetGenerator &other);
	void learnTargetType(ATarget *target);
	void forgetTargetType(std::string const &type);
	ATarget *createTarget(std::string const &target);
};

#endif