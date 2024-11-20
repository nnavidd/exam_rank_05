#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include <map>

class ASpell;

class ATarget {
    protected:
        std::string _type;
        ATarget();
        ATarget(ATarget const & other);
        ATarget & operator=(ATarget const & other);
    public:
        virtual ~ATarget();
        ATarget(std::string const & type);
        std::string const & getType() const;
        virtual ATarget * clone() const = 0;
        void getHitBySpell(ASpell const & spell) const;
};


#endif