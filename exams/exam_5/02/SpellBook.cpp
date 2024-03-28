#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

void SpellBook::learnSpell(ASpell *spell)
{ spells[spell->getName()] = spell->clone(); }

void SpellBook::forgetSpell(std::string const &name)
{ if (spells.find(name) == spells.end())
        { return; }
        spells.erase(spells.find(name)); }

ASpell* SpellBook::createSpell(std::string const &name)
{ if (spells.find(name) != spells.end())
    {return (spells[name]);}
    else
        { return (NULL);} }