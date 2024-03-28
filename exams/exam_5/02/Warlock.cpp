#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

std::string const & Warlock::getName() const
{ return (_name); }

std::string const & Warlock::getTitle() const
{ return (_title); }

void Warlock::setTitle(std::string const &title)
{ _title = title; }

Warlock::Warlock(std::string const &name, std::string const &title): _name(name), _title(title)
{ std::cout << _name << ": This looks like another boring day." <<std::endl; }

Warlock::~Warlock()
{ std::cout << _name << ": My job here is done!" << std::endl;}

void Warlock::introduce() const
{ std::cout << _name << ": I am "  << _name << ", " << _title << "!" << std::endl; }

void Warlock::learnSpell(ASpell *spell)
{ spells.learnSpell(spell); }

void Warlock::forgetSpell(std::string const &name)
{ spells.forgetSpell(name); }

void Warlock::launchSpell(std::string const &name, ATarget const &target)
{
        if (spells.createSpell(name) != NULL)
                {spells.createSpell(name)->launch(target);}
}
