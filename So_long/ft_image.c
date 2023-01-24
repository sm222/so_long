/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:47 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/24 11:08:18 by anboisve         ###   ########.fr       */
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
	map->img_col[0] = mlx_xpm_file_to_image(game->mlx, IMAGE_V1, &x, &y);
	map->img_col[1] = mlx_xpm_file_to_image(game->mlx, IMAGE_V2, &x, &y);
	map->img_col[2] = mlx_xpm_file_to_image(game->mlx, IMAGE_V3, &x, &y);
	map->img_col[3] = mlx_xpm_file_to_image(game->mlx, IMAGE_V4, &x, &y);
	map->img_col[4] = mlx_xpm_file_to_image(game->mlx, IMAGE_V5, &x, &y);
	map->img_col[5] = mlx_xpm_file_to_image(game->mlx, IMAGE_V6, &x, &y);
	map->img_exit = mlx_xpm_file_to_image(game->mlx, "image/pink3.xpm", &x, &y);
}

void	ft_put_tile(t_main *info, int x, int y, void *img)
{
	mlx_put_image_to_window(info->mlx, info->win_p, img,
		x * PIC_S, y * PIC_S);
}

void	print_other(t_main *info)
{
	int	x;
	int	y;

	if (info->frame > 59)
		info->frame = 0;
	y = 0;
	while (info->m_p->map_p[y])
	{
		x = 0;
		while (info->m_p->map_p[y][x])
		{
			if (info->m_p->map_p[y][x] == '3')
				ft_put_tile(info, x, y, info->m_p->img_col[info->frame / 10]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win_p, info->img_player,
		info->player_x, info->player_y);
	info->frame += 5;
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
			else if (info->m_p->map_p[y][x] == 'e')
				ft_put_tile(info, x, y, info->m_p->img_exit);
			else
				ft_put_tile(info, x, y, info->m_p->img_flore);
			x++;
		}
		y++;
	}
	print_other(info);
	return (0);
}
