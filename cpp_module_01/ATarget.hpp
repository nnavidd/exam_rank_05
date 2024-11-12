#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget {
	protected:
		std::string _type;
	public:
		virtual ~ATarget();
		ATarget( ATarget const & );
		ATarget const & operator=( ATarget const & );	
		std::string const & getType() const;
		virtual ATarget * clone() const = 0;
		ATarget(std::string type);
		void getHitBySpell( ASpell const & ) const;
};

#endif