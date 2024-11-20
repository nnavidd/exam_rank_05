#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "SpellBook.hpp"

class ASpell;
class ATarget;

class Warlock {
    private:
        std::string _name;
        std::string _title;
        SpellBook _spells;
        Warlock(Warlock const &);
        Warlock & operator=(Warlock const &);
        Warlock(void);
    public:
        Warlock(std::string const & name, std::string const &title);
        ~Warlock();
        std::string const & getName(void) const;
        std::string const & getTitle(void) const;
        void setTitle(std::string const & title);
        void introduce() const;
        void learnSpell(ASpell const * newSpell) ;
        void forgetSpell(std::string const & spellName);
        void launchSpell(std::string const & spellName, ATarget const & tar);

};

/*
* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
* forgetSpell, takes a string corresponding a to a spell's name, and makes the
  Warlock forget it. If it's not a known spell, does nothing.
* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.
*/

#endif 