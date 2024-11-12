#include "./ATarget.hpp"
#include "./ASpell.hpp"

ATarget::~ATarget() {}

ATarget::ATarget(std::string type):_type(type) {}

ATarget::ATarget( ATarget const & other ): _type(other._type) {}


ATarget const & ATarget::operator=( ATarget const & other ) {
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

std::string const & ATarget::getType() const {
	return _type;
}

void ATarget::getHitBySpell( ASpell const & other ) const {
	std::cout << _type << " has been " << other.getEffects() << "!" << std::endl;
}


