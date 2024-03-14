/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:41:02 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/14 20:53:07 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    //name, color name, hp, energy, attack damage
	std::cout << COLOR_BHWHITE << "CONSTRUCTORS" << COLOR_RESET << std::endl;
	ClapTrap Foo("Foo", COLOR_BHYELLOW);
	ClapTrap Boo("Boo", COLOR_BHRED);
	ClapTrap Goo("Goo", COLOR_BHCYAN);
	ClapTrap Doo("Doo", COLOR_BHMAGENTA);
	ClapTrap Loo("Loo", COLOR_BHGREEN);

	std::cout << std::endl << COLOR_BHWHITE << "THE FIGHT" << COLOR_RESET << std::endl;
	//KILL
	Doo.attack(Loo.getName());
	Loo.takeDamage(0);
	Foo.attack(Loo.getName());
	Loo.takeDamage(0);

	//NO ENERGY POINTS
	Foo.attack(Doo.getName());
    Doo.takeDamage(0);
	Foo.beRepaired(2);

	//ATTACK
	Boo.attack(Goo.getName());

	//TAKE NO DAMAGE
	Goo.takeDamage(0);

	//PLAYER IS DEAD (no side effects)
	Loo.attack(Foo.getName());
	Loo.takeDamage(0);
	Loo.beRepaired(6);

	//HEAL
	Doo.beRepaired(4);

	std::cout << std::endl << COLOR_BHWHITE << "DESTRUCTORS" << COLOR_RESET;

	return 0;
}