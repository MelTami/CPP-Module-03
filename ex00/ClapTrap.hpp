/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:40:58 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/14 17:35:07 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include "colors.hpp"

class ClapTrap
{
private:
    std::string     name;
    std::string     color;
    unsigned int    hitpoints;
    unsigned int    energypoints;
    unsigned int    attackdamage;
public:
    ClapTrap();
    ClapTrap( const std::string name );
    ClapTrap(const std::string &name, const std::string &color, unsigned int const hp, unsigned int const ep, unsigned int const ad);
	ClapTrap( ClapTrap const &copy );
    ~ClapTrap();

    ClapTrap		&operator=( ClapTrap const &copy );
    void            attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

    int getHitPoints(void) const;
	int getenergypoints(void) const;
	int getattackdamage(void) const;
	void sethitpoints(unsigned int const hp);
	void setenergypoints(unsigned int const ep);
	void setattackdamage(unsigned int const ad);

	std::string getName(void) const;
	void setName(const std::string &name);

    bool isDead(void);

	std::ostream&operator<<(std::ostream& os);
};



#endif