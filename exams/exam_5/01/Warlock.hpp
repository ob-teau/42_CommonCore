#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock 
{
	public:
		std::string const &getName() const;
		std::string const &getTitle() const;
		void setTitle(std::string const &title);
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &name);
		void launchSpell(std::string const &name, ATarget const &target);

	private:
		std::map <std::string, ASpell *> spells;
		std::string _name;
		std::string _title;
		Warlock &operator=(Warlock const &other);
		Warlock(Warlock const &other);
		Warlock();
	


};
