#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) :
	name(name),
	title(title),
	list()
{
    std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
    std::cout << name << ": My job here is done!\n";
	for (std::unordered_map<std::string, ASpell *>::iterator it = list.begin();
		it != list.end(); ++it) { delete it->second; }
    list.clear();
}

std::string const &Warlock::getName() const { return name; }
std::string const &Warlock::getTitle() const { return title; }

void Warlock::setTitle(std::string const &title) { this->title = title; }

void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!\n";
}

void Warlock::learnSpell(ASpell *spell) {
	if (spell == NULL) { return; }
	std::unordered_map<std::string, ASpell *>::iterator it = list.begin();
	if (it != list.end()) {
		delete it->second;
		it->second = spell->clone();
	} else {
		list[spell->getName()] = spell->clone();
	}
}
void Warlock::forgetSpell(std::string const &name) {
	std::unordered_map<std::string, ASpell *>::iterator it = list.find(name);
	if (it != list.end()) {
		delete it->second;
		list.erase(it);
	}
}
void Warlock::launchSpell(std::string const &name, ATarget const &targ) {
	std::unordered_map<std::string, ASpell *>::iterator it = list.find(name);
	if (it != list.end()) {
		it->second->launch(targ);
	}
}
