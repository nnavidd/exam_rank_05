#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>

class ASpell;
class ATarget;

class Warlock {
    private:
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell *> _spells;
        Warlock & operator=(Warlock const & other);
        Warlock(Warlock const & other);
        Warlock();
        
    public:
        Warlock(std::string const & name, std::string const & title);
        ~Warlock();
        std::string const & getName(void) const;
        std::string const & getTitle(void) const;
        void setTitle(std::string const & title);
        void introduce() const;

        void learnSpell(ASpell const * newSpell);
        void forgetSpell(std::string const & spellName);
        void launchSpell(std::string const & newSpell, ATarget const & target);

/*
* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
* forgetSpell, takes a string corresponding a to a spell's name, and makes the
  Warlock forget it. If it's not a known spell, does nothing.
* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.
*/

};

#endif