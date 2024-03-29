/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:41:02 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/14 19:19:12 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
	//name, color name, hp, energy, attack damage
	std::cout << COLOR_BHWHITE << "CONSTRUCTORS" << COLOR_RESET << std::endl;
	ScavTrap Doo("Doo", COLOR_BHRED);
	ScavTrap Loo("Loo", COLOR_BHGREEN);
	ScavTrap Boo("Boo", COLOR_BHCYAN);
	ScavTrap Foo("Foo", COLOR_BHMAGENTA);
	ScavTrap Goo("Goo", COLOR_BHYELLOW);
	ScavTrap Clone(Doo);

	std::cout << std::endl << COLOR_BHWHITE << "THE FIGHT" << COLOR_RESET << std::endl;
	//Kill
	Goo.attack(Loo.getName());
	Loo.takeDamage(20);
	Goo.attack(Loo.getName());
	Loo.takeDamage(20);
	Foo.attack(Loo.getName());
	Loo.takeDamage(20);
	Foo.attack(Loo.getName());
	Loo.takeDamage(20);
	Doo.attack(Loo.getName());
	Loo.takeDamage(20);


	//No Energy Points
	Goo.attack(Foo.getName());
	Foo.takeDamage(20);
	Goo.beRepaired(10);

	//Attack
	Doo.attack(Boo.getName());

	//Take no damage
	Boo.takeDamage(0);

	//Player is Dead (no side effects)
	Loo.attack(Goo.getName());
	Loo.takeDamage(20);
	Loo.beRepaired(6);

	//Heal
	Foo.beRepaired(10);

	//Guard Gate
	std::cout << std::endl << COLOR_BHWHITE << "GATE GUARDS" << COLOR_RESET << std::endl;
	Foo.guardGate();
	Doo.guardGate();
	Loo.guardGate();
	Clone.setName("Doo \"copy\" clone");
	Clone.guardGate();
	Clone = Goo;
	Clone.setName("Goo \"copy assignment\" clone");
	Clone.guardGate();

	//Destructors are in reverse order. Example:
	// Type1 Object1;
	// Type2 Object2(Object1);
	std::cout << std::endl << COLOR_BHWHITE << "DESTRUCTORS" << COLOR_RESET;

	return 0;
}