#include "ASpell.hpp"

    std::string ASpell::getName() const
    {return (_name);}

    std::string ASpell::getEffects() const
    {return (_effects);}

    ASpell::ASpell(std::string const &name, std::string const &effects): _name(name), _effects(effects)
    {}
    
    ASpell::ASpell()
    {}

    ASpell::ASpell(ASpell const &other)
    {
        *this = other; 
    }

    ASpell &ASpell::operator=(ASpell const &other)
    {
        _name = other.getName();
        _effects = other.getEffects();
        return (*this);
    }

    ASpell::~ASpell()
    {}

    void ASpell::launch(ATarget const &target) const
    { target.getHitBySpell(*this); }