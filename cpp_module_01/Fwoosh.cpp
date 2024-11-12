#include "./Fwoosh.hpp"


Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {
	 std::cout << "Fwoosh destructor called" << std::endl;
}

ASpell * Fwoosh::clone() const {
	return new Fwoosh(*this);
}