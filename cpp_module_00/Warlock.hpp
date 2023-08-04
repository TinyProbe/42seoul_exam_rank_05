#pragma once
#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>

class Warlock {
	std::string name;
	std::string title;

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

};

#endif

