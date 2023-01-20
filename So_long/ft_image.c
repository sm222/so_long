/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:47 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/20 12:57:18 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_image(t_map *map, t_main *game)
{
	int		x;
	int		y;

	game->player_p = mlx_xpm_file_to_image(game->mlx, IMAGE_PLAYER, &x, &y);
	map->flore = mlx_xpm_file_to_image(game->mlx, IMAGE_FLORE, &x, &y);
	map->wall = mlx_xpm_file_to_image(game->mlx, IMAGE_WALL, &x, &y);
}

int	print_map(t_main *info)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(info->mlx, info->win_p);
	while (info->m_p->map_p[y])
	{
		x = 0;
		while (info->m_p->map_p[y][x])
		{
			if (info->m_p->map_p[y][x] == '1')
				mlx_put_image_to_window(info->mlx, info->win_p, info->m_p->wall,
					x * PIC_S, y * PIC_S);
			else
				mlx_put_image_to_window(info->mlx, info->win_p,
					info->m_p->flore, x * PIC_S, y * PIC_S);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win_p, info->player_p,
		info->player_x, info->player_y);
	return (0);
}
