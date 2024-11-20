#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
#include <map>

class ATarget;

class ASpell {
    protected:
        std::string _name;
        std::string _effects;
        ASpell();
        ASpell(ASpell const & other);
        ASpell & operator=(ASpell const & other);
    public:
        virtual ~ASpell();
        ASpell(std::string const & name, std::string const & effects);
        std::string const & getName() const;
        std::string const & getEffects() const;
        virtual ASpell * clone() const = 0;
        void launch(ATarget const & target);
};


#endif