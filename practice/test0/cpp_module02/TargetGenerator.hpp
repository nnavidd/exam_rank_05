#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <map>


class ATarget;

class TargetGenerator {
    private:
        std::map<std::string, ATarget *> _targets;
        TargetGenerator(TargetGenerator const & other);
        TargetGenerator & operator=(TargetGenerator const & other);
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget * const newTarget);
        void forgetTargetType(std::string const & newTarget);
        ATarget * createTarget(std::string const & newTarget);

};

/*
* void learnTargetType(ATarget*), teaches a target to the generator

* void forgetTargetType(string const &), that makes the generator forget a
  target type if it's known

* ATarget* createTarget(string const &), that creates a target of the
  specified type
*/
#endif