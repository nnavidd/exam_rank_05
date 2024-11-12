#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

/*
* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
* forgetSpell, takes a string corresponding a to a spell's name, and makes the
  Warlock forget it. If it's not a known spell, does nothing.
* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.
*/

class ASpell;
class ATarget;

class Warlock {
	private:
		std::string _name;
		std::string _title;
		std::map<std::string, ASpell *> spells;

		Warlock();
		Warlock( Warlock const & );
		Warlock & operator=( Warlock const & );
	
	public:
		~Warlock();
		Warlock(std::string const & name, std::string const & title);
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const & title);
		void introduce() const;

		void learnSpell( ASpell * spell );
		void forgetSpell( std::string const & spellName);
		void launchSpell( std::string const & spellName, ATarget const & tar );
};


#endif