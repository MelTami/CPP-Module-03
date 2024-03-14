/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:41:02 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/14 17:39:13 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    //name, color name, hp, energy, attack damage
	std::cout << COLOR_BHWHITE << "CONSTRUCTORS" << COLOR_RESET << std::endl;
	ClapTrap Foo("Foo", COLOR_BHYELLOW, 30, 2, 8);
	ClapTrap Boo("Boo", COLOR_BHRED, 26, 6, 10);
	ClapTrap Goo("Goo", COLOR_BHCYAN, 20, 8, 7);
	ClapTrap Doo("Doo", COLOR_BHMAGENTA, 18, 4, 6);
	ClapTrap Loo("Loo", COLOR_BHGREEN, 14, 10, 4);

	std::cout << std::endl << COLOR_BHWHITE << "THE FIGHT" << COLOR_RESET << std::endl;
	//KILL
	Doo.attack(Loo.getName());
	Loo.takeDamage(6);
	Foo.attack(Loo.getName());
	Loo.takeDamage(8);

	//NO ENERGY POINTS
	Foo.attack(Doo.getName());
    Doo.takeDamage(8);
	Foo.beRepaired(6);

	//ATTACK
	Boo.attack(Goo.getName());

	//TAKE NO DAMAGE
	Goo.takeDamage(0);

	//PLAYER IS DEAD (no side effects)
	Loo.attack(Foo.getName());
	Loo.takeDamage(4);
	Loo.beRepaired(6);

	//HEAL
	Doo.beRepaired(4);

	std::cout << std::endl << COLOR_BHWHITE << "DESTRUCTORS" << COLOR_RESET;

	return 0;
}