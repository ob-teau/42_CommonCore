#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget *target)
{ targets[target->getType()] = target; }

void TargetGenerator::forgetTargetType(std::string const &type)
{ if (targets.find(type) == targets.end())
        { return; }
        targets.erase(targets.find(type));  }

ATarget* TargetGenerator::createTarget(std::string const &type)
{ if (targets.find(type) != targets.end())
    {return (targets[type]);}
    else
        { return (NULL);} }