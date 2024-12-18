#include "Warlock.hpp"

        Warlock::Warlock(Warlock const & other) {
            *this = other;
        }
        Warlock & Warlock::operator=(Warlock const & other) {
            if(this != &other)
                *this = other;
            return *this;
        }
        Warlock::Warlock(void) {}
        Warlock::Warlock(std::string const & name, std::string const &title) : _name(name), _title(title) {
            std::cout << _name<< ": This looks like another boring day." <<std::endl;
        }
        Warlock::~Warlock() {
            std::cout << _name<<": My job here is done!"<<std::endl;
        }
        std::string const & Warlock::getName(void) const {
            return _name;
        }
        std::string const & Warlock::getTitle(void) const {
            return _title;
        }
        void Warlock::setTitle(std::string const & title) {
            _title = title;
        }
        void Warlock::introduce() const {
            std::cout << _name<< ": I am "<<_name<<", "<<_title<<"!"<< std::endl;
        }