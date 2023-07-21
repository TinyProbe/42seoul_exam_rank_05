#pragma once
#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <map>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
	std::string name;
	std::string title;
	std::unordered_map<std::string, ASpell *> list;

private:
	Warlock();
	Warlock(Warlock const &rhs);
	Warlock &operator=(Warlock const &rhs);

public:
	Warlock(std::string const &name, std::string const &title);
	virtual ~Warlock();

	virtual std::string const &getName() const;
	virtual std::string const &getTitle() const;

	virtual void setTitle(std::string const &title);

	virtual void introduce() const;

	virtual void learnSpell(ASpell *spell);
	virtual void forgetSpell(std::string const &name);
	virtual void launchSpell(std::string const &name, ATarget const &targ);

};

#endif

