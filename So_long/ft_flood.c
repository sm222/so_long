/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:44:17 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/07 10:13:27 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_flood *data, int x, int y)
{
	if (data->map[y][x] == '2' || data->map[y][x] == '1'
	|| data->map[y][x] == 'c' || data->map[y][x] == 'e')
		return ;
	if (data->map[y][x] == 'C')
	{
		data->find++;
		data->map[y][x] = 'c';
	}
	else if (data->map[y][x] == '0')
		data->map[y][x] = '2';
	else if (data->map[y][x] == 'E')
	{
		data->map[y][x] = 'e';
		data->exit = 1;
	}
	fill(data, x, y + 1);
	fill(data, x, y - 1);
	fill(data, x + 1, y);
	fill(data, x - 1, y);
}

int	ft_playable(t_main *info)
{
	t_flood	data;

	data.exit = 0;
	data.find = 0;
	info->m_p->exit_swich = 0;
	data.map = ft_cpy_double_char(info->m_p->map_p);
	if (!data.map)
		ft_exit(info, ft_combine(ERR_MALLOC "ft_playable"), 1);
	fill(&data, info->player_x / PIC_S, info->player_y / PIC_S);
	ft_ft_double_sfree((void **)data.map);
	if (data.find != info->m_p->collect || data.exit == 0)
		ft_exit(info, ft_combine("not playable"), 1);
	return (0);
}
