#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) :
    name(name),
    title(title),
    book()
{
    std::cout << name << ": This looks like another boring day.\n";
}
Warlock::~Warlock() {
    std::cout << name << ": My job here is done!\n";
}

std::string const &Warlock::getName() const { return name; }
std::string const &Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const &title) { this->title = title; }

void Warlock::introduce() const {
    std::cout << name << ": I am " << name << ", " << title << "!\n";
}

void Warlock::learnSpell(ASpell *spell) { book.learnSpell(spell); }
void Warlock::forgetSpell(std::string const &name) { book.forgetSpell(name); }
void Warlock::launchSpell(std::string const &name, ATarget const &targ) {
    ASpell *tmp = book.createSpell(name);
    if (tmp != NULL) { tmp->launch(targ); }
}

