#include <iostream>
#include <string>

class Warlock 
{
	public:
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		void introduce() const;

	private:
		std::string _name;
		std::string _title;
		Warlock &operator=(Warlock const &other);
		Warlock(Warlock const &other);
		Warlock();
	


};
