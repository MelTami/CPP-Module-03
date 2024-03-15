/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:16 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/15 15:50:51 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "[ScavTrap] Default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap()
{
    std::cout << "[ScavTrap] constructor of" << name <<  "has been called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &_name, const std::string &_color) : ClapTrap()
{
    name = _name;
	color = _color;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "[ScavTrap] " << color << name << COLOR_RESET
	<< " has joined the game" << "(HP: " << hitpoints
	<< " | Energy: " << energypoints << " | Attack: "
	<< attackdamage << ")" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap()
{
	*this = copy;
}

ScavTrap&ScavTrap::operator=(const ScavTrap &copy)
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

void ScavTrap::attack(const std::string &target)
{
	if (isDead())
		return ;

	if (energypoints == 0)
	{
		std::cout << "[ScavTrap] " << color << name
		<< COLOR_RESET << " has no energy points to attack " << target
		<< std::endl;
		return ;
	}
	std::cout << "[ScavTrap] " << color << name <<
	COLOR_RESET << " attacks " << target << ", causing " << attackdamage
	<< " points of damage." << std::endl;

	energypoints--;
}

void ScavTrap::guardGate(void)
{
	if (isDead())
		return ;

	std::cout << "[ScavTrap] " << color << name
	<< COLOR_RESET << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	static int newline = 0;

	if (newline == 0)
	{
		std::cout << std::endl;
		newline++;
	}
	std::cout << "[ScavTrap] " << color << name << COLOR_RESET;
	if (isDead())
		std::cout << " is dead";
	else
		std::cout << " has left the game";
	std::cout << std::endl;
}