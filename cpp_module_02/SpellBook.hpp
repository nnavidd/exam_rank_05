#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
/*
* void learnSpell(ASpell*), that COPIES a spell in the book
* void forgetSpell(string const &), that deletes a spell from the book, except
  if it isn't there
* ASpell* createSpell(string const &), that receives a string corresponding to
  the name of a spell, creates it, and returns it.
*/


class SpellBook {
	private:
		std::map<std::string, ASpell*> _spells;
		void spellsCopy(std::map<std::string, ASpell *> const & spells);
		SpellBook( SpellBook const &);
		SpellBook & operator=( SpellBook const &);
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};

#endif