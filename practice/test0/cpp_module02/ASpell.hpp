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

    public:
    ASpell(std::string const & name, std::string const & effects);
    ASpell & operator=(ASpell const & other);
    ASpell(ASpell const & other);
    virtual ~ASpell();
    virtual ASpell * clone() const = 0;
    std::string const & getName() const;
    std::string const & getEffects() const;
    void launch(ATarget const & target);
};


#endif