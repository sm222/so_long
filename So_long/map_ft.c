/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:35 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/11 17:59:54 by anboisve         ###   ########.fr       */
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
	if (colect > 0 && player == 1 && e == 0)
		return (0);
	return (colect);
}

char	*ft_get_map(char *f_name, int *colect)
{
	t_get_map	map_i;

	map_i.tmp = "so_long";
	map_i.s = NULL;
	ft_look_name(f_name);
	map_i.fd = open(f_name, O_RDONLY);
	if (map_i.fd >= 0)
	{
		while (map_i.tmp)
		{
			map_i.tmp = get_next_line(map_i.fd);
			map_i.s = ft_strfjoin(map_i.s, map_i.tmp);
			if (map_i.tmp)
				free(map_i.tmp);
		}
		close(map_i.fd);
	}
	else
		ft_error("can't open file");
	*colect = ft_valid_map(map_i.s);
	if (*colect > 0)
		return (map_i.s);
	return (ft_safe_free(map_i.s));
}

int	ft_look_side(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_valid_side_up_down(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][x])
		if (map[0][x++] != '1')
			return (0);
	return (1);
}
