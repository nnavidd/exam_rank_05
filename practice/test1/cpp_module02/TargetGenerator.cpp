#include "ATarget.hpp"
#include "TargetGenerator.hpp"

        TargetGenerator::TargetGenerator(TargetGenerator const & other) {
            *this = other;
        }
        TargetGenerator & TargetGenerator::operator=(TargetGenerator const & other) {
            if (this != &other)
                *this = other;
            return *this;
        }
        TargetGenerator::TargetGenerator() {}
        TargetGenerator::~TargetGenerator() {
            if (!_targets.empty()) {
                for(std::map<std::string, ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it)
                    delete it->second;
                _targets.clear();
            }
        }
        void TargetGenerator::learnTargetType(ATarget const * newTarget) {
            if (_targets.find(newTarget->getType()) == _targets.end())
                _targets[newTarget->getType()] = newTarget->clone();
        }
        void TargetGenerator::forgetTargetType(std::string const & targetName) {
            if (_targets.find(targetName) != _targets.end()) {
                delete _targets[targetName];
                _targets.erase(_targets.find(targetName));
            }
        }
        ATarget * TargetGenerator::createTarget(std::string const & targetName) {
            if (_targets.find(targetName) != _targets.end())
                return _targets[targetName]->clone();
            return NULL;
        }