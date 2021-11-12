#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){};

TargetGenerator::~TargetGenerator()
{
	std::vector<ATarget *>::iterator it_begin = arr.begin();
	std::vector<ATarget *>::iterator it_end = arr.end();
	for (; it_begin != it_end; it_begin++)
		delete *it_begin;
	arr.clear();
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator &other)
{
	std::vector<ATarget *>::iterator it_begin = arr.begin();
	std::vector<ATarget *>::iterator it_end = arr.end();
	for (; it_begin != it_end; it_begin++)
		delete *it_begin;
	arr.clear();
	for (size_t i = 0; i < other.arr.size(); i++)
	{
		arr.push_back(other.arr[i]);
	}
	return *this;
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	std::vector<ATarget *>::iterator it_begin = arr.begin();
	std::vector<ATarget *>::iterator it_end = arr.end();
	if (target)
	{
		for (; it_begin != it_end; it_begin++)
		{
			if ((*it_begin)->getType() == target->getType())
				return;
		}
		arr.push_back(target->clone());
	}
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
	std::vector<ATarget *>::iterator it_begin = arr.begin();
	std::vector<ATarget *>::iterator it_end = arr.end();
	for (; it_begin != it_end; it_begin++)
	{
		if ((*it_begin)->getType() == type)
		{
			delete *it_begin;
			arr.erase(it_begin);
			return;
		}
	}
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
	std::vector<ATarget *>::iterator it_begin = arr.begin();
	std::vector<ATarget *>::iterator it_end = arr.end();
	for (; it_begin != it_end; it_begin++)
	{
		if ((*it_begin)->getType() == target)
			return ((*it_begin)->clone());
	}
	return NULL;
}
