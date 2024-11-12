#include "./Warlock.hpp"
#include "./ASpell.hpp"
#include "./ATarget.hpp"


Warlock::Warlock() {}

Warlock::Warlock( Warlock const & obj ): _name(obj._name), _title(obj._title) {}

Warlock & Warlock::operator=( Warlock const & obj ) {
	if (this == &obj)
		return *this;
	_name = obj._name;
	_title= obj._title;
	return *this;
}

Warlock::~Warlock() {
	std::cout << _name <<": My job here is done!" << std::endl;
}

Warlock::Warlock( std::string const & name, std::string const & title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

std::string const & Warlock::getName() const {
	return _name;
}
std::string const & Warlock::getTitle() const {
	return _title;
}

void Warlock::setTitle( std::string const & title ) {
	_title = title;
}

void Warlock::introduce() const {
	std::cout << _name << ": I am "<< _name << ", " << _title << "!"<< std::endl;
}

void Warlock::learnSpell( ASpell * newSpell ) {
	_spells.learnSpell(newSpell);
}

void Warlock::forgetSpell( std::string const & spellName) {
	_spells.forgetSpell(spellName);
}

void Warlock::launchSpell( std::string const & spellName, ATarget const & tar ) {
	if (_spells.createSpell(spellName))
		_spells.createSpell(spellName)->launch(tar);
}
