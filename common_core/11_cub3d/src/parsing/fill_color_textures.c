/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:07:04 by etetopat          #+#    #+#             */
/*   Updated: 2023/09/20 23:31:19 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	no_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (true);
		i++;
	}
	return (false);
}

static int	*copy_to_rgb_array(char **rgb_to_convert, int *rgb)
{
	int	i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || no_digit(rgb_to_convert[i]) == true)
		{
			free((void **)rgb_to_convert);
			free(rgb);
			return (0);
		}
	}
	free((void **)rgb_to_convert);
	return (rgb);
}

static int	*set_rgb_colors(char *line)
{
	char	**rgb_to_convert;
	int		*rgb;
	int		count;

	count = 0;
	rgb_to_convert = ft_split(line, ',');
	while (rgb_to_convert[count])
		count++;
	if (count != 3)
	{
		free((void **)rgb_to_convert);
		return (0);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		err_msg(NULL, ERR_MALLOC, 0);
		return (0);
	}
	return (copy_to_rgb_array(rgb_to_convert, rgb));
}

int	fill_color_textures(t_data *data, t_tex_info *tex, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (err_msg(data->map_info.path, ERR_CEILING_FLOOR, ERROR));
	if (!tex->ceiling && line[j] == 'C')
	{
		tex->ceiling = set_rgb_colors(line + j + 1);
		if (tex->ceiling == 0)
			return (err_msg(data->map_info.path, ERR_COLOR_CEILING, ERROR));
	}
	else if (!tex->floor && line[j] == 'F')
	{
		tex->floor = set_rgb_colors(line + j + 1);
		if (tex->floor == 0)
			return (err_msg(data->map_info.path, ERR_COLOR_FLOOR, ERROR));
	}
	else
		return (err_msg(data->map_info.path, ERR_CEILING_FLOOR, ERROR));
	return (SUCCESS);
}
