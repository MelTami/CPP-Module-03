/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:40:58 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/15 15:52:05 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include "colors.hpp"

# define ATTACK_POINTS_F 30
# define HIT_POINTS_F 100
# define ENERGY_POINTS_F 100

# define ATTACK_POINTS_S 20
# define HIT_POINTS_S 100
# define ENERGY_POINTS_S 50

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap( const std::string name );
    ClapTrap(const std::string &name, const std::string &color);
	ClapTrap( ClapTrap const &copy );
    ~ClapTrap();

    ClapTrap		&operator=( ClapTrap const &copy );
    void            attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

    int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;
	void setHitPoints(unsigned int const hp);
	void setEnergyPoints(unsigned int const ep);
	void setAttackDamage(unsigned int const ad);

	std::string getName(void) const;
	void setName(const std::string &name);

    bool isDead(void);

protected:
    std::string     name;
    std::string     color;
    unsigned int    hitpoints;
    unsigned int    energypoints;
    unsigned int    attackdamage;
};

#endif