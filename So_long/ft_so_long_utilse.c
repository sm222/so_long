/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utilse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:17:16 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/27 10:43:58 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_clean_map(t_map *map)
{
	map->map_p = (char **)ft_ft_double_sfree((void **)map->map_p);
}

void	ft_put_tile(t_main *info, int x, int y, void *img)
{
	mlx_put_image_to_window(info->mlx, info->win_p, img,
		x * PIC_S, y * PIC_S);
}
