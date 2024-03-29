/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:32:18 by etetopat          #+#    #+#             */
/*   Updated: 2023/11/09 22:11:47 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_valid_character(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
				|| data->map[i][j] == '\r' || data->map[i][j] == '\v'
				|| data->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("01NSWE", map_tab[i][j])))
				return (err_msg(data->map_info.path, ERR_MAP_CHAR, FAILURE));
			if (ft_strchr("NSWE", map_tab[i][j]) && data->player.dir != '0')
				return (err_msg(data->map_info.path, ERR_PLAYER_MAX, FAILURE));
			if (ft_strchr("NSWE", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_valid_position(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (i <= 0 || j <= 0 || !map_tab[i] || !map_tab[i - 1]
		|| !map_tab[i + 1] || map_tab[i][j] == '\0'
		|| map_tab[i - 1][j] == '\0' || map_tab[i + 1][j] == '\0'
		|| map_tab[i][j + 1] == '\0' || map_tab[i][j - 1] == '\0')
		return (FAILURE);
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| is_whitespace(map_tab[i - 1][j]) == SUCCESS
		|| is_whitespace(map_tab[i + 1][j]) == SUCCESS
		|| is_whitespace(map_tab[i][j - 1]) == SUCCESS
		|| is_whitespace(map_tab[i][j + 1]) == SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

static int	check_player_position(t_data *data, char **map_tab)
{
	static int	found_player = 0;
	static int	i = -1;
	int			j;

	if (data->player.dir == '0')
		return (err_msg(data->map_info.path, ERR_PLAYER_DIR, FAILURE));
	while (map_tab[++i])
	{
		j = -1;
		while (map_tab[i][++j])
		{
			if (ft_strchr("NSWE", map_tab[i][j]))
			{
				if (found_player)
					return (err_msg(data->map_info.path, ERR_PLAYER_MAX, 1));
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
				found_player = 1;
			}
		}
	}
	if (check_valid_position(data, map_tab) == FAILURE)
		return (err_msg(data->map_info.path, ERR_PLAYER_POS, FAILURE));
	return (SUCCESS);
}

static int	check_map_position(t_map_info *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data, char **map_tab)
{
	if (!data->map)
		return (err_msg(data->map_info.path, ERR_MAP_MISSING, FAILURE));
	if (check_valid_character(data, map_tab) == FAILURE)
		return (FAILURE);
	if (data->map_info.height < 3)
		return (err_msg(data->map_info.path, ERR_MAP_SMALL, FAILURE));
	if (check_map_position(&data->map_info) == FAILURE)
		return (err_msg(data->map_info.path, ERR_MAP_POS, FAILURE));
	if (check_map_fah(data, map_tab) == FAILURE)
		return (err_msg(data->map_info.path, ERR_MAP_BORDERS, FAILURE));
	if (check_player_position(data, map_tab) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
