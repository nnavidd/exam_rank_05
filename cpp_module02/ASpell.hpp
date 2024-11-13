#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell {
	protected:
		std::string _name;
		std::string _effects;
	public:
		virtual ~ASpell();
		ASpell( ASpell const & );
		ASpell const & operator=( ASpell const & );	
		std::string const & getName() const;
		std::string const & getEffects() const;
		virtual ASpell * clone() const = 0;
		ASpell(std::string name, std::string effect);
		void launch( ATarget const & ) const;
		
};

#endif