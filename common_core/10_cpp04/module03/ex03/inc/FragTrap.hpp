/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:16:42 by Manny             #+#    #+#             */
/*   Updated: 2023/07/21 12:36:40 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const& rhs);
		~FragTrap(void);
		
		FragTrap&	operator=(FragTrap const& rhs);

		void	highFivesGuys(void);

	protected:
		FragTrap(void);

		unsigned int	_fragHp;
		unsigned int	_fragHpMax;
		unsigned int	_fragEp;
		unsigned int	_fragAd;
};

#endif