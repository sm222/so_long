/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:44:17 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/25 09:44:02 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_map *map, int x, int y, int *find)
{
	if (map->map_p[y] && (x > 0 && x < map->m_x) && (y > 0 && y < map->m_y))
	{
		if (map->map_p[y][x] == '2' || map->map_p[y][x] == '1'
		|| map->map_p[y][x] == '3' || map->map_p[y][x] == 'e')
			return ;
		if (map->map_p[y][x] == 'C')
		{
			(*find)++;
			map->map_p[y][x] = '3';
		}
		else if (map->map_p[y][x] == '0')
			map->map_p[y][x] = '2';
		else if (map->map_p[y][x] == 'E')
		{
			map->map_p[y][x] = 'e';
			map->exit_swich = 1;
		}
		fill(map, x, y + 1, find);
		fill(map, x, y - 1, find);
		fill(map, x + 1, y, find);
		fill(map, x - 1, y, find);
	}
}

int	ft_playable(t_main *info)
{
	int	find;

	info->m_p->exit_swich = 0;
	find = 0;
	fill(info->m_p, info->player_x / PIC_S, info->player_y / PIC_S, &find);
	if (find != info->m_p->collect || info->m_p->exit_swich == 0)
	{
		ft_ft_double_sfree((void *)info->m_p->map_p);
		ft_error("not playable");
	}
	return (0);
}
