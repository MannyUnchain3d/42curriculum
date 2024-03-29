/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:47:49 by etetopat          #+#    #+#             */
/*   Updated: 2023/07/25 19:34:59 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
	std::cout << RED "/ ------------------ Dog Basic ------------------ /" NC << std::endl;
	std::cout << BLUE "Original:" NC << std::endl;
	Dog	basic;
	std::cout << std::endl;
	std::cout << BLUE "Deep Copy:" NC << std::endl;
	Dog	tmp = basic;

	std::cout << std::endl;

	std::cout << RED "/ ----------- Animal Deep Assignation ----------- /" NC<< std::endl;
	const Animal*	animal[6];

	for(int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			animal[i] = new Dog();
			std::cout << std::endl;
		} else {
			animal[i] = new Cat();
			std::cout << std::endl;
		}
	}

	for(int i = 0; i < 6; i++) {
		std::cout << YELLOW << animal[i]->getType() << " " NC << std::endl;
		animal[i]->makeSound();
		delete animal[i];
		std::cout << std::endl;
	}
	
	return 0;
}