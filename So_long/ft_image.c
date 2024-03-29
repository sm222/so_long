/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:47 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/06 21:34:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	add at the image to the structs
*/

void	ft_make_image(t_map *map, t_main *game)
{
	int		x;
	int		y;

	game->img_player[0] = mlx_xpm_file_to_image(game->mlx, IMAGE_PLY, &x, &y);
	game->img_player[1] = mlx_xpm_file_to_image(game->mlx, IMAGE_PLY2, &x, &y);
	map->img_flore = mlx_xpm_file_to_image(game->mlx, IMAGE_FLORE, &x, &y);
	map->img_wall[0] = mlx_xpm_file_to_image(game->mlx, IMAGE_WALL, &x, &y);
	map->img_wall[1] = mlx_xpm_file_to_image(game->mlx, IMAGE_WALL1, &x, &y);
	map->img_wall[2] = mlx_xpm_file_to_image(game->mlx, IMAGE_WALL2, &x, &y);
	map->img_col[0] = mlx_xpm_file_to_image(game->mlx, IMAGE_V1, &x, &y);
	map->img_col[1] = mlx_xpm_file_to_image(game->mlx, IMAGE_V2, &x, &y);
	map->img_col[2] = mlx_xpm_file_to_image(game->mlx, IMAGE_V3, &x, &y);
	map->img_col[3] = mlx_xpm_file_to_image(game->mlx, IMAGE_V4, &x, &y);
	map->img_col[4] = mlx_xpm_file_to_image(game->mlx, IMAGE_V5, &x, &y);
	map->img_col[5] = mlx_xpm_file_to_image(game->mlx, IMAGE_V6, &x, &y);
	map->img_exit = mlx_xpm_file_to_image(game->mlx, IMAGE_EXIT, &x, &y);
}

void	put_text_window(t_main *info)
{
	char	*new;
	int		color;

	color = new_trgb(255, NAME[1] * 2, NAME[2] * 2, NAME[0] * 2);
	new = ft_combine("move = %S", ft_itoa(info->move));
	mlx_string_put(info->mlx, info->win_p, info->player_x - 15,
		info->player_y - 20, color, NAME);
	color = new_trgb(255, 0, 255, 200);
	mlx_string_put(info->mlx, info->win_p, info->m_p->m_x * PIC_S \
	/ 2 - 30, 10, color, new);
	if (info->s)
		info->s = ft_safe_free(info->s);
	if (new)
		new = ft_safe_free(new);
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
			if (info->m_p->map_p[y][x] == 'C')
				ft_put_tile(info, x, y, info->m_p->img_col[info->frame / 10]);
			else if (info->m_p->map_p[y][x] == 'E')
				ft_put_tile(info, x, y, info->m_p->img_exit);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win_p, \
	info->img_player[info->p_dir], info->player_x, info->player_y);
	put_text_window(info);
	info->frame += 11;
}

int	print_map(t_main *info)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(info->mlx, info->win_p);
	while (info->m_p->map_p[++y])
	{
		x = -1;
		while (info->m_p->map_p[y][++x])
		{
			if (info->m_p->map_p[y][x] == '1')
			{
				if (y == 0 || y + 1 == info->m_p->m_y)
					ft_put_tile(info, x, y, info->m_p->img_wall[2]);
				else if (x == 0 || x + 1 == info->m_p->m_x)
					ft_put_tile(info, x, y, info->m_p->img_wall[1]);
				else
					ft_put_tile(info, x, y, info->m_p->img_wall[0]);
			}
			else
				ft_put_tile(info, x, y, info->m_p->img_flore);
		}
	}
	print_other(info);
	return (0);
}
