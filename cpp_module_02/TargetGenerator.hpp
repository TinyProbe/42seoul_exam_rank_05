#pragma once
#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <unordered_map>
#include "ATarget.hpp"

class TargetGenerator {
    std::unordered_map<std::string, ATarget *> targs;

private:
    TargetGenerator(TargetGenerator const &rhs);
    TargetGenerator &operator=(TargetGenerator const &rhs);

public:
    TargetGenerator();
    virtual ~TargetGenerator();

    virtual void learnTargetType(ATarget *targ);
    virtual void forgetTargetType(std::string const &name);
    virtual ATarget *createTarget(std::string const &name);

};

#endif

