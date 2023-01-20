/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:47 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/19 18:53:48 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_image(t_map *map, t_main *game, char *name)
{
	int		x;
	int		y;

	game->player_p = mlx_xpm_file_to_image(game->mlx, name, &x, &y);
	map->flore = mlx_xpm_file_to_image(game->mlx, "pink2.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &x, &y);
}

void	print_map(t_map *map, t_main *info)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_p[y])
	{
		x = 0;
		while (map->map_p[y][x])
		{
			if (map->map_p[y][x] == '1')
				mlx_put_image_to_window(info->mlx, info->win_p, map->wall,
					x * PIC_S, y * PIC_S);
			else
				mlx_put_image_to_window(info->mlx, info->win_p, map->flore,
					x * PIC_S, y * PIC_S);
			x++;
		}
		y++;
	}
}
