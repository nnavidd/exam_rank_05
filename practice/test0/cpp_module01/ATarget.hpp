#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include <map>

class ASpell;

class ATarget {
    protected:
        std::string _type;

    public:
    ATarget(std::string const & type);
    ATarget & operator=(ATarget const & other);
    ATarget(ATarget const & other);
    virtual ~ATarget();
    virtual ATarget * clone() const = 0;
    std::string const & getType() const;
    void getHitBySpell(ASpell const & spell) const;
};


#endif