/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:41:02 by mvavasso          #+#    #+#             */
/*   Updated: 2024/03/14 22:19:59 by mvavasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	//name, color name, hp, energy, attack damage
	std::cout << COLOR_BHWHITE << "CONSTRUCTORS" << COLOR_RESET << std::endl;
	ScavTrap Doo("Doo", COLOR_HRED);
	ScavTrap Loo("Loo", COLOR_HGREEN);
	ScavTrap Boo("Boo", COLOR_HCYAN);
	ScavTrap Foo("Foo", COLOR_HMAGENTA);
	ScavTrap Goo("Goo", COLOR_HYELLOW);
	ScavTrap Clone(Doo);

	FragTrap Duu("Duu", COLOR_BHRED);
	FragTrap Luu("Luu", COLOR_BHGREEN);
	FragTrap Buu("Buu", COLOR_BHCYAN);
	FragTrap Fuu("Fuu", COLOR_BHMAGENTA);
	FragTrap Guu("Guu", COLOR_BHYELLOW);

	std::cout << std::endl << COLOR_BHWHITE << "THE FIGHT" << COLOR_RESET << std::endl;
	//Kill
	Goo.attack(Loo.getName());
	Loo.takeDamage(ATTACK_POINTS);
	Goo.attack(Loo.getName());
	Loo.takeDamage(ATTACK_POINTS);
	Foo.attack(Loo.getName());
	Loo.takeDamage(ATTACK_POINTS);
	Foo.attack(Loo.getName());
	Loo.takeDamage(ATTACK_POINTS);
	Doo.attack(Loo.getName());
	Loo.takeDamage(ATTACK_POINTS);

	Guu.attack(Luu.getName());
	Luu.takeDamage(ATTACK_POINTS);
	Guu.attack(Luu.getName());
	Luu.takeDamage(ATTACK_POINTS);
	Fuu.attack(Luu.getName());
	Luu.takeDamage(ATTACK_POINTS);
	Fuu.attack(Luu.getName());
	Luu.takeDamage(ATTACK_POINTS);
	Duu.attack(Luu.getName());
	Luu.takeDamage(ATTACK_POINTS);


	//No Energy Points
	Goo.attack(Foo.getName());
	Foo.takeDamage(ATTACK_POINTS);
	Goo.beRepaired(10);

	//Attack
	Doo.attack(Boo.getName());

	//Take no damage
	Boo.takeDamage(0);

	//Player is Dead (no side effects)
	Loo.attack(Goo.getName());
	Loo.takeDamage(ATTACK_POINTS);
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

	//High Five Guys
	std::cout << std::endl << COLOR_BHWHITE << "HIGH FIVE GUYS" << COLOR_RESET << std::endl;
	Luu.highFiveGuys();
	Buu.highFiveGuys();

	//Destructors are in reverse order. Example:
	// Type1 Object1;
	// Type2 Object2(Object1);
	std::cout << std::endl << COLOR_BHWHITE << "DESTRUCTORS" << COLOR_RESET;

	return 0;
}