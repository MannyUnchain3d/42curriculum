/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:48:21 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 05:44:47 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.h"

int	main(void) {
	ClapTrap	clap1("Ryu");
	ClapTrap	clap2(clap1);
	
	std::cout << std::endl;
	
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;
	clap1.attack("Bison");
	clap1.takeDamage(8);
	clap1.beRepaired(5);
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;

	std::cout << std::endl;

	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;
	clap2.takeDamage(10);
	clap2.beRepaired(5);
	std::cout << RED "/ * ------------------------------------------- */" NC << std::endl;

	std::cout << std::endl;

	return (0);
}