#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>

class ASpell;

class SpellBook {
    private:
        std::map<std::string, ASpell *> _spells;
        SpellBook(SpellBook const & other);
        SpellBook & operator=(SpellBook const & other);
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell const * newSpell);
        void forgetSpell(std::string const & spellName);
        ASpell * creatSpell(std::string const & spellName);
};

/*
* void learnSpell(ASpell*), that COPIES a spell in the book
* void forgetSpell(string const &), that deletes a spell from the book, except
  if it isn't there
* ASpell* createSpell(string const &), that receives a string corresponding to
  the name of a spell, creates it, and returns it.
*/

#endif