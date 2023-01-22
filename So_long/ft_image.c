/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:47 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/22 17:54:32 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_image(t_map *map, t_main *game)
{
	int		x;
	int		y;

	game->img_player = mlx_xpm_file_to_image(game->mlx, IMAGE_PLAYER, &x, &y);
	map->img_flore = mlx_xpm_file_to_image(game->mlx, IMAGE_FLORE, &x, &y);
	map->img_wall = mlx_xpm_file_to_image(game->mlx, IMAGE_WALL, &x, &y);
	map->img_col = mlx_xpm_file_to_image(game->mlx, "image/pink.xpm", &x, &y);
	map->img_exit = mlx_xpm_file_to_image(game->mlx, "image/pink3.xpm", &x, &y);
}

void	ft_put_tile(t_main *info, int x, int y, void *img)
{
	mlx_put_image_to_window(info->mlx, info->win_p, img,
		x * PIC_S, y * PIC_S);
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
				ft_put_tile(info, x, y, info->m_p->img_wall);
			else if (info->m_p->map_p[y][x] == 'C')
				ft_put_tile(info, x, y, info->m_p->img_col);
			else if (info->m_p->map_p[y][x] == 'E')
				ft_put_tile(info, x, y, info->m_p->img_exit);
			else
				ft_put_tile(info, x, y, info->m_p->img_flore);
			x++;
		}
		y++;
	}
	return (mlx_put_image_to_window(info->mlx, info->win_p, info->img_player,
			info->player_x, info->player_y));
}
