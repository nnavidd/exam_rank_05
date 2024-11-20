#include "ASpell.hpp"
#include "ATarget.hpp"

        ATarget::ATarget() {}
        ATarget::ATarget(ATarget const & other) {
            *this = other;
        }
        ATarget & ATarget::operator=(ATarget const & other) {
            if (this != &other)
                *this = other;
            return *this;
        }
        ATarget::~ATarget() {}
        ATarget::ATarget(std::string const & type) : _type(type) {}
        std::string const & ATarget::getType() const {
            return _type;
        }
        void ATarget::getHitBySpell(ASpell const & spell) const {
            std::cout << _type<< " has been "<< spell.getEffects() << "!" << std::endl;
        }