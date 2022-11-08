/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:50:58 by etetopat          #+#    #+#             */
/*   Updated: 2022/08/30 13:52:41 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_memcmp compares the first n bytes of the memory areas
	s1 and s2. The bytes are interpreted as unsigned char.

	RETURN VALUE :
	An integer less than, equal to, or greater than zero if the first
	n bytes of s1 is found to be less than, equal to, or greater than the 
	first n bytes of s2. Zero if n is equal to zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;

	if (n == 0)
		return (0);
	str1 = (const char *)s1;
	str2 = (const char *)s2;
	i = 0;
	while ((i < n - 1) && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}