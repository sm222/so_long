/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:35 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/29 17:59:22 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_map(t_main *game, char *map_s)
{
	t_valid_map	var;

	var.colect = 0;
	var.player = 0;
	var.i = -1;
	var.e = 0;
	while (map_s && map_s[++var.i])
	{
		if (map_s[var.i] == 'C')
			var.colect++;
		if (map_s[var.i] == 'P')
			var.player++;
		if (map_s[var.i] == 'E')
			var.e++;
		if (map_s[var.i] != '1' && map_s[var.i] \
		!= '0' && map_s[var.i] != '\n')
		{
			var.invalid[0] = map_s[var.i];
			ft_exit(game, "is a invalid caracter", 1);
		}
	}
	if (var.colect == 0 || var.player != 1 || var.e != 1)
		ft_exit(game, "not ", 1);
	return (var.colect);
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
		ft_exit(info, ERR_CANT_OPEN, 1);
	*colect = ft_valid_map(info, data.new);
	if (*colect > 0 && data.new)
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
			ft_exit(game, "map is not valid", 1);
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
		ft_exit(game, ERR_BIG_MAP, 1);
	}
	y--;
	while (--x)
		if (game->m_p->map_p[y][x] != '1')
			return (0);
	return (1);
}
