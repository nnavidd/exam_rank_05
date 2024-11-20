#include "SpellBook.hpp"
#include "ASpell.hpp"

        SpellBook::SpellBook(SpellBook const & other) {
            *this = other;
        }
        SpellBook & SpellBook::operator=(SpellBook const & other) {
            if(this != &other)
                *this = other;
            return *this;
        }
        SpellBook::SpellBook() {}
        SpellBook::~SpellBook() {
            if (!_spells.empty()) {
                for (std::map<std::string, ASpell *>::iterator it = _spells.begin(); it != _spells.end(); ++it)
                    delete it->second;
                _spells.clear();
            }
        }
        void SpellBook::learnSpell(ASpell const * newSpell) {
            if (_spells.find(newSpell->getName()) == _spells.end())
                _spells[newSpell->getName()] = newSpell->clone();
        }
        void SpellBook::forgetSpell(std::string const & spellName) {
            if (_spells.find(spellName) != _spells.end()) {
                delete _spells[spellName];
                _spells.erase(_spells.find(spellName));
            }
        }
        ASpell * SpellBook::creatSpell(std::string const & spellName) {
            if (_spells.find(spellName) != _spells.end())
                return _spells[spellName]->clone();
            return NULL;
        }