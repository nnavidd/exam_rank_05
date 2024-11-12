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
	if (!spells.empty()) {
		for (std::map<std::string, ASpell *>::iterator it = spells.begin(); it != spells.end(); ++it)
			delete it->second;
	}
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


void Warlock::learnSpell( ASpell * spell ) {
	if (spell) {
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell( std::string const & spellName) {
	if (spells.find(spellName) != spells.end()) {
		std::map<std::string, ASpell *>::iterator tmp = spells.find(spellName);
		delete tmp->second;
		spells.erase(spells.find(spellName));
	}
}

void Warlock::launchSpell( std::string const & spellName, ATarget const & tar ) {
	if (spells.find(spellName) != spells.end())
		spells[spellName]->launch(tar);
}

