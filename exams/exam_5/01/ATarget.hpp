#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{

public:
    std::string const &getType() const;
    virtual ATarget *clone() const = 0;
    ATarget(std::string const &type);
    ATarget();
    ATarget(ATarget const &other);
    ATarget &operator=(ATarget const &other);
    virtual ~ATarget();
    void getHitBySpell(ASpell const &spell) const;

protected:
    std::string _type;

private:


};