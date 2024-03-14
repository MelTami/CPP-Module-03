/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:40:55 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/14 21:08:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "[ClapTrap] Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name)
{
    std::cout << "[ClapTrap] constructor of" << name <<  "has been called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const std::string &color) : name(name), color(color), hitpoints(HIT_POINTS), energypoints(ENERGY_POINTS), attackdamage(ATTACK_POINTS)
{
	std::cout << "[ClapTrap] " << color << name << COLOR_RESET
	<< " has joined the game" << "(HP: " << hitpoints
	<< " | Energy: " << energypoints << " | Attack: "
	<< attackdamage << ")" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap&ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		name = copy.name;
		color = copy.color;
		hitpoints = copy.hitpoints;
		energypoints = copy.energypoints;
		attackdamage = copy.attackdamage;
	}
	return *this;
}

std::string ClapTrap::getName(void) const
{
	return name;
}

void ClapTrap::setName(const std::string &_name)
{
	name = _name;
}

void ClapTrap::attack(const std::string &target)
{
	if (isDead())
		return ;

	if (energypoints == 0)
	{
		std::cout << "[ClapTrap] " << color << name
		<< COLOR_RESET << " has no energy points to attack " << target
		<< std::endl;
		return ;
	}
	std::cout << "[ClapTrap] " << color << name <<
	COLOR_RESET << " attacks " << target << ", causing " << attackdamage
	<< " points of damage." << std::endl;

	energypoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (isDead())
		return ;

	std::cout << "[ClapTrap] " << color << name << COLOR_RESET;

	if (amount == 0)
	{
		std::cout << " hasn\'t taken any damage, chiuf!" << std::endl;
		return ;
	}

	if (amount > hitpoints)
	{
		std::cout << " has died [" << hitpoints;
		hitpoints = 0;
		std::cout << " -> " << hitpoints << " HP]" << std::endl;
		return ;
	}

	std::cout <<" has taken -" << amount << " of damage [" << hitpoints;
	
	hitpoints -= amount;
	std::cout << " -> " << hitpoints << " HP]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (isDead())
		return ;

	if (energypoints == 0)
	{
		std::cout << "[ClapTrap] " << color << name
		<< COLOR_RESET << " has no energy points to heal itself."
		<< std::endl;
		return ;
	}
	std::cout << "[ClapTrap] " << color << name << COLOR_RESET
	<< " has healed itself +" << amount << " [" << hitpoints;

	hitpoints += amount;
	std::cout << " -> " << hitpoints << " HP]" << std::endl;

	energypoints--;
}

bool ClapTrap::isDead(void)
{
	if (hitpoints == 0)
		return true;
	return false;
}

int ClapTrap::getHitPoints(void) const
{
	return hitpoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return energypoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return attackdamage;
}

void ClapTrap::setHitPoints(const unsigned int hp)
{
	hitpoints = hp;
}

void ClapTrap::setEnergyPoints(const unsigned int ep)
{
	energypoints = ep;
}

void ClapTrap::setAttackDamage(const unsigned int ad)
{
	attackdamage = ad;
}

ClapTrap::~ClapTrap(void)
{
	static int newline = 0;

	if (newline == 0)
	{
		std::cout << std::endl;
		newline++;
	}
	std::cout << "[ClapTrap] " << color << name << COLOR_RESET;
	if (isDead())
		std::cout << " is dead";
	else
		std::cout << " has left the game";
	std::cout << std::endl;
}