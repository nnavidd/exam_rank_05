#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"


class TargetGenerator {
	private:
		std::map<std::string, ATarget*> _targets;
		void targetsCopy(std::map<std::string, ATarget *> const & targets);
		TargetGenerator( TargetGenerator const &);
		TargetGenerator & operator=( TargetGenerator const &);
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};

#endif