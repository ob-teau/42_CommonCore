#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class SpellBook
{
    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &name);
        ASpell* createSpell(std::string const &name);
    
    private:
        std::map <std::string, ASpell*> spells;
        SpellBook(SpellBook const &other);
        SpellBook &operator=(SpellBook const &other);

};
