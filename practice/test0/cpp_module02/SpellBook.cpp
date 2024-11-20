#include "SpellBook.hpp"
#include "ASpell.hpp"


        SpellBook::SpellBook(SpellBook const & other) {
            *this = other;
        }
        SpellBook & SpellBook::operator=(SpellBook const & other) {
            if (this != &other)
                *this = other;
            return *this;
        }

        SpellBook::SpellBook() {}
        SpellBook::~SpellBook() {
            for (std::map<std::string, ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
                delete it->second;
            _spells.clear();
        }

        void SpellBook::learnSpell(ASpell const * newSpell) {
            if (_spells.find(newSpell->getName()) == _spells.end())
                _spells[newSpell->getName()] = newSpell->clone();
        }

        void SpellBook::forgetSpell(std::string const & newSpell) {
            if (_spells.find(newSpell) != _spells.end()) {
                delete _spells[newSpell];
                _spells.erase(_spells.find(newSpell));
            }
        }

        ASpell * SpellBook::creatSpell(std::string const & newSpell) {
            if (_spells.find(newSpell) != _spells.end())
                return _spells[newSpell]->clone();
            return NULL;
        }