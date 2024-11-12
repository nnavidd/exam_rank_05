#include <iostream>
#include <string>

class Warlock {
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock( Warlock const & );
		Warlock & operator=( Warlock const & );
	
	public:
		~Warlock();
		Warlock(std::string const & name, std::string const & title);
		std::string const & getName() const;
		std::string const & getTitle() const;
		void setTitle(std::string const & title);
		void introduce() const;

};
