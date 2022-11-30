/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dground <dground@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:51:39 by dground           #+#    #+#             */
/*   Updated: 2022/05/13 12:41:46 by dground          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	params_init(t_game *game)
{
	game->steps = 0;
	game->exit = FALSE;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		disp_error_exit(ARGS_ERR);
	params_init(&game);
	map_init(argv[1], &game.map);
	game.mlx.ptr = mlx_init();
	game.mlx.win = mlx_new_window(game.mlx.ptr, game.map.width * CELL_SIZE,
			game.map.height * CELL_SIZE, "so_long");
	mlx_hook(game.mlx.win, 17, 0, game_close, (void *)&game);
	mlx_hook(game.mlx.win, 2, 0, game_action, (void *)&game);
	img_init(&(game.mlx), &(game.map.img));
	img_to_win(&game);
	mlx_loop(game.mlx.ptr);
	return (0);
}
