/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:04:33 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/15 15:50:41 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "[FragTrap] Default constructor has been called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap()
{
    std::cout << "[FragTrap] constructor of" << name <<  "has been called" << std::endl;
}

FragTrap::FragTrap(const std::string &_name, const std::string &_color) : ClapTrap()
{
    name = _name;
	color = _color;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);

	std::cout << "[FragTrap] " << color << name << COLOR_RESET
	<< " has joined the game" << "(HP: " << hitpoints
	<< " | Energy: " << energypoints << " | Attack: "
	<< attackdamage << ")" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap()
{
	*this = copy;
}

FragTrap&FragTrap::operator=(const FragTrap &copy)
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

void    FragTrap::attack(const std::string &target)
{
	if (isDead())
		return ;

	if (energypoints == 0)
	{
		std::cout << "[FragTrap] " << color << name
		<< COLOR_RESET << " has no energy points to attack " << target
		<< std::endl;
		return ;
	}
	std::cout << "[FragTrap] " << color << name <<
	COLOR_RESET << " attacks " << target << ", causing " << attackdamage
	<< " points of damage." << std::endl;

	energypoints--;
}

void    FragTrap::highFiveGuys(void)
{
    if (isDead())
	{
		std::cout << "[FragTrap] " << color << name
		<< COLOR_RESET << " may rest in peace, but no one can resist to a high five 👏"
		<< std::endl;
		return ;
	}

	std::cout << "[FragTrap] " << color << name << COLOR_RESET
	<< " gives a high five. Who\'s joining in? 👋" << std::endl;
}

FragTrap::~FragTrap(void)
{
	static int new_line = 0;

	if (new_line == 0)
	{
		std::cout << std::endl;
		new_line++;
	}
	std::cout << "[FragTrap] " << color << name << COLOR_RESET;
	if (isDead())
		std::cout << " is dead";
	else
		std::cout << " has left the game";
	std::cout << std::endl;
}