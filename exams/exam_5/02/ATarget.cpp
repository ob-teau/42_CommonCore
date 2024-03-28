#include "ATarget.hpp"

    std::string const &ATarget::getType() const
    {return (_type);}

    ATarget::ATarget(std::string const &type): _type(type)
    {}
    
    ATarget::ATarget()
    {}

    ATarget::ATarget(ATarget const &other)
    {
        *this = other; 
    }

    ATarget &ATarget::operator=(ATarget const &other)
    {
        _type = other.getType();
        return (*this);
    }

    ATarget::~ATarget()
    {}

    void ATarget::getHitBySpell(ASpell const &spell) const
    { std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl; }