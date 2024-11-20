#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	if (!_targets.empty()) {
		for (std::map<std::string, ATarget*>::iterator it = _targets.begin(); it != _targets.end(); ++it)
			delete it->second;
	}
	_targets.clear();
}

void	TargetGenerator::targetsCopy(std::map<std::string, ATarget *> const & other) {
	for (std::map<std::string, ATarget*>::const_iterator it = other.begin(); it != other.end(); ++it)
		_targets[it->first] = it->second->clone();
}

TargetGenerator::TargetGenerator( TargetGenerator const & other) {
	targetsCopy(other._targets);
}

TargetGenerator & TargetGenerator::operator=( TargetGenerator const & other) {
	if (this != &other) {
		for (std::map<std::string, ATarget *>::iterator it = _targets.begin(); it != _targets.end(); ++it)
			delete it->second;
		_targets.clear();
		targetsCopy(other._targets);
	}
	return *this;
}


void TargetGenerator::learnTargetType(ATarget* newTarget) {
	if (newTarget && _targets.find(newTarget->getType()) == _targets.end())
		_targets[newTarget->getType()] = newTarget->clone();
		// _targets[newTarget->getType()] = newTarget;
}

void TargetGenerator::forgetTargetType(std::string const & targetName) {
	if (_targets.find(targetName) != _targets.end()) {
		std::map<std::string, ATarget*>::iterator it = _targets.find(targetName);
		delete it->second;
		_targets.erase(it);
	}

}

ATarget* TargetGenerator::createTarget(std::string const & targetName) {
	ATarget *tmp = NULL;
	if (_targets.find(targetName) != _targets.end())
		tmp = _targets[targetName];
	return tmp;
}	
