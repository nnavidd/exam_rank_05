#include "./ASpell.hpp"
#include "./ATarget.hpp"

ASpell::~ASpell() {}

ASpell::ASpell( ASpell const & other ): _name(other._name), _effects(other._effects) {}

ASpell::ASpell(std::string name, std::string effect):_name(name), _effects(effect) {}

ASpell const & ASpell::operator=( ASpell const & other ) {
	if (this == &other)
		return *this;
	_name = other._name;
	_effects = other._effects;
	return *this;
}

std::string const & ASpell::getName() const {
	return _name;
}

std::string const & ASpell::getEffects() const {
	return _effects;
}

void ASpell::launch( ATarget const & other ) const {
	other.getHitBySpell(*this);
}



