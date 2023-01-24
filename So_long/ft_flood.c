/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:44:17 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/24 11:07:59 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill(t_map *map, int x, int y)
{
	int	find;

	find = 0;
	if (map->map_p[y] && (x > 0 && x < map->m_x) && (y > 0 && y < map->m_y))
	{
		if (map->map_p[y][x] == '2' || map->map_p[y][x] == '1'
		|| map->map_p[y][x] == '3' || map->map_p[y][x] == 'e')
			return (0);
		if (map->map_p[y][x] == 'C')
		{
			find++;
			map->map_p[y][x] = '3';
		}
		else if (map->map_p[y][x] == '0')
			map->map_p[y][x] = '2';
		else if (map->map_p[y][x] == 'E')
		{
			map->map_p[y][x] = 'e';
			map->exit_swich = 1;
		}
		find += fill(map, x, y + 1) + fill(map, x, y - 1)
			+ fill(map, x - 1, y) + fill(map, x + 1, y);
		return (find);
	}
	return (0);
}

int	ft_playable(t_main *info)
{
	info->m_p->exit_swich = 0;
	if (fill(info->m_p, info->player_x / PIC_S, info->player_y / PIC_S)
		!= info->m_p->collect || info->m_p->exit_swich == 0)
	{
		ft_ft_double_sfree((void *)info->m_p->map_p);
		ft_error("not playable");
	}
	return (0);
}
