#pragma once
#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{

public:
    std::string getName() const;
    std::string getEffects() const;
    virtual ASpell *clone() const = 0;
    ASpell(std::string const &name, std::string const &effects);
    ASpell();
    ASpell(ASpell const &other);
    ASpell &operator=(ASpell const &other);
    virtual ~ASpell();
    void launch(ATarget const &target) const;

protected:
    std::string _name;
    std::string _effects;

private : 


};
