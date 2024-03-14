/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:04:36 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/14 22:18:18 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
    FragTrap(void);
    FragTrap(const std::string &name);
	FragTrap(const std::string &_name, const std::string &_color);
	FragTrap(const FragTrap &copy);
	FragTrap&operator=(const FragTrap &copy);
	~FragTrap(void);

	void attack(const std::string &target);
	void highFiveGuys(void);
};

#endif