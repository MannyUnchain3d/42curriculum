/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:46:06 by Manny             #+#    #+#             */
/*   Updated: 2023/09/16 06:55:46 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Function to display an error message for wrong arguments. */
void	usage(void)
{
	ft_putstr_fd("\033[31mError: Wrong arguments\n\e[0m", 2);
	ft_putstr_fd("Example: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("./pipex \"hdoc\" <LIMITER> <cmd1> <cmd2> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

/* Function to open fds with the right flags. */
int	open_fd(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(argv, O_RDONLY, 0777);
	if (fd == -1)
		error(NULL, strerror(errno));
	return (fd);
}
