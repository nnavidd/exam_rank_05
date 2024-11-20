#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>


class Warlock {
    private:
        std::string _name;
        std::string _title;
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


};

#endif