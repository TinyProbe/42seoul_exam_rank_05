#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() :
    targs() {}
TargetGenerator::~TargetGenerator() {
    for (std::unordered_map<std::string, ATarget *>::iterator it = targs.begin();
        it != targs.end(); ++it) { delete it->second; }
}

void TargetGenerator::learnTargetType(ATarget *targ) {
    std::unordered_map<std::string, ATarget *>::iterator it = targs.find(targ->getType());
    if (it != targs.end()) {
        delete it->second;
        it->second = targ->clone();
    } else {
        targs[targ->getType()] = targ->clone();
    }
}
void TargetGenerator::forgetTargetType(const std::string &name) {
    std::unordered_map<std::string, ATarget *>::iterator it = targs.find(name);
    if (it != targs.end()) {
        delete it->second;
        targs.erase(it);
    }
}
ATarget *TargetGenerator::createTarget(const std::string &name) {
    std::unordered_map<std::string, ATarget *>::iterator it = targs.find(name);
    if (it != targs.end())
        return it->second;
    return NULL;
}

