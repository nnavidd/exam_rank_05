#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"


        Warlock::Warlock() {}
        Warlock & Warlock::operator=(Warlock const & other) {
            if (this != &other) {
                _name = other._name;
                _title = other._title;
            }
            return *this;
        }

        Warlock::Warlock(Warlock const & other) : _name(other._name), _title(other._title) {}
        
        Warlock::Warlock(std::string const & name, std::string const & title) : _name(name), _title(title) {
            std::cout << _name <<": This looks like another boring day." << std::endl;
        }

        Warlock::~Warlock() {
            std::cout << _name<<": My job here is done!" << std::endl;
        }


        std::string const & Warlock::getName(void) const {
            return _name;
        }

        std::string const & Warlock::getTitle(void) const {
            return _title;
        }
        void Warlock::setTitle(std::string const & title) {
            _title = title;
        }

        void Warlock::introduce() const {
           std::cout << _name << ": I am "<< _name<<", "<< _title<< "!" << std::endl;
        }

        
        void Warlock::learnSpell(ASpell const * newSpell) {
            _spells.learnSpell(newSpell);
        }

        void Warlock::forgetSpell(std::string const & spellName) {
            _spells.forgetSpell(spellName);
        }

        void Warlock::launchSpell(std::string const & newSpell, ATarget const & target) {
            ASpell *tmp = _spells.creatSpell(newSpell);
            if (tmp) {
                tmp->launch(target);
                delete tmp;
            }
        }