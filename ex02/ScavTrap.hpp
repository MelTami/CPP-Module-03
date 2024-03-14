/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:53:20 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/14 22:02:15 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>


class ScavTrap : public ClapTrap
{
private:
    
public:
    ScavTrap(void);
    ScavTrap(const std::string &name);
	ScavTrap(const std::string &_name, const std::string &_color);
	ScavTrap(const ScavTrap &copy);
	ScavTrap&operator=(const ScavTrap &copy);
	~ScavTrap(void);

	void attack(const std::string &target);
	void guardGate(void);
};

#endif