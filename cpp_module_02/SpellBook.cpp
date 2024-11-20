#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	if (!_spells.empty()) {
		for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it)
			delete it->second;
	}
	_spells.clear();
	std::cout << "----------------->this is inside the deconstructor of SpellBook" << std::endl;
}

void	SpellBook::spellsCopy(std::map<std::string, ASpell *> const & other) {
	for (std::map<std::string, ASpell*>::const_iterator it = other.begin(); it != other.end(); ++it)
		_spells[it->first] = it->second->clone();
}

SpellBook::SpellBook( SpellBook const & other) {
	spellsCopy(other._spells);
}

SpellBook & SpellBook::operator=( SpellBook const & other) {
	if (this != &other) {
		for (std::map<std::string, ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
			delete it->second;
		_spells.clear();
		spellsCopy(other._spells);
	}
	return *this;
}


void SpellBook::learnSpell(ASpell* newSpell) {
	if (newSpell && _spells.find(newSpell->getName()) == _spells.end())
		_spells[newSpell->getName()] = newSpell->clone();
}

void SpellBook::forgetSpell(std::string const & spellName) {
	if (_spells.find(spellName) != _spells.end()) {
		std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
		delete it->second;
		_spells.erase(it);
	}

}

ASpell* SpellBook::createSpell(std::string const & spellName) {
	if (_spells.find(spellName) != _spells.end()) {

		return _spells[spellName]->clone();
	}
	return NULL;
}	
