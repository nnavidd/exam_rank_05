#include "ASpell.hpp"
#include "ATarget.hpp"

        ASpell::ASpell() {}
        ASpell::ASpell(ASpell const & other) {
            *this = other;
        }
        ASpell & ASpell::operator=(ASpell const & other) {
            if (this != &other)
                *this = other;
            return *this;
        }
        ASpell::~ASpell() {}
        ASpell::ASpell(std::string const & name, std::string const & effects) :_name(name), _effects(effects) {}
        std::string const & ASpell::getName() const {
            return _name;
        }
        std::string const & ASpell::getEffects() const {
            return _effects;
        }
        void ASpell::launch(ATarget const & target) {
            target.getHitBySpell(*this);
        }