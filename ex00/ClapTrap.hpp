/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:40:58 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/10 23:47:36 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string     name;
    int             hitpoints;
    int             energypoints;
    int             attackdamage;
public:
    ClapTrap();
    ClapTrap( std::string name );
	ClapTrap( ClapTrap const &rhs );
    ~ClapTrap();

    ClapTrap		&operator=( ClapTrap const &rhs );
    void            attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);


};



#endif