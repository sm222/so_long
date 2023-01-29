/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:35 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/29 11:34:29 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_map(char *map_s)
{
	int		player;
	int		colect;
	int		e;
	size_t	i;

	colect = 0;
	player = 0;
	i = 0;
	e = 0;
	while (map_s && map_s[i])
	{
		if (map_s[i] == 'C')
			colect++;
		else if (map_s[i] == 'P')
			player++;
		else if (map_s[i] == 'E')
			e++;
		else if (map_s[i] != '1' && map_s[i] != '0' && map_s[i] != '\n')
			return (-1);
		i++;
	}
	if (colect == 0 || player != 1 || e != 1)
		return (0);
	return (colect);
}

char	*ft_get_map(char *f_name, int *colect, t_main *info)
{
	t_get_map	data;

	data.tmp = "so_long";
	data.new = NULL;
	ft_look_name(f_name);
	data.fd = open(f_name, O_RDONLY);
	if (data.fd >= 0)
	{
		while (data.tmp)
		{
			data.tmp = get_next_line(data.fd);
			data.new = ft_strfjoin(data.new, data.tmp);
			if (data.tmp)
				ft_safe_free(data.tmp);
		}
		close(data.fd);
	}
	else
		ft_exit(info, "can't open map", 1);
	*colect = ft_valid_map(data.new);
	if (*colect > 0)
		return (data.new);
	return (data.new = ft_safe_free(data.new), NULL);
}

int	ft_look_side(t_main *game, int *size_x, int *size_y)
{
	int	i;

	if (!game->m_p->map_p)
		return (0);
	i = 0;
	*size_y = 1;
	*size_x = ft_strlen(game->m_p->map_p[i]);
	while (game->m_p->map_p[i] && game->m_p->map_p[i + 1])
	{
		if (ft_strlen(game->m_p->map_p[i]) \
		== ft_strlen(game->m_p->map_p[i + 1]))
			i++;
		else
			return (0);
		(*size_y)++;
	}
	return (ft_valid_all_side(game));
}

int	ft_valid_all_side(t_main *game)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (game->m_p->map_p[0][x])
		if (game->m_p->map_p[0][x++] != '1')
			return (0);
	while (game->m_p->map_p[y])
	{
		if (game->m_p->map_p[y][0] != '1' || game->m_p->map_p[y][x - 1] != '1')
			return (0);
		y++;
	}
	if (x > 51 || y > 26)
	{
		ft_exit(game, "map is too big, need to be smaller that x 51 y 26", 1);
	}
	y--;
	while (--x)
		if (game->m_p->map_p[y][x] != '1')
			return (0);
	return (1);
}
