/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:35 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/26 17:36:21 by anboisve         ###   ########.fr       */
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

char	*ft_get_map(char *f_name, int *colect)
{
	char	*tmp;
	char	*new;
	int		fd;

	tmp = "so_long";
	new = NULL;
	ft_look_name(f_name);
	fd = open(f_name, O_RDONLY);
	if (fd >= 0)
	{
		while (tmp)
		{
			tmp = get_next_line(fd);
			new = ft_strfjoin(new, tmp);
			if (tmp)
				free(tmp);
		}
		close(fd);
	}
	else
		ft_error("can't open file");
	*colect = ft_valid_map(new);
	if (*colect > 0)
		return (new);
	return (ft_safe_free(new), NULL);
}

int	ft_look_side(char **map, int *size_x, int *size_y)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	*size_y = 1;
	*size_x = ft_strlen(map[i]);
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else
			return (0);
		(*size_y)++;
	}
	return (ft_valid_all_side(map));
}

int	ft_valid_all_side(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (map[0][x])
		if (map[0][x++] != '1')
			return (0);
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (0);
		y++;
	}
	if (x > 51 || y > 26)
		ft_bad_map(map, "map is too big, need to be, x < 51, y < 26");
	y--;
	while (--x)
		if (map[y][x] != '1')
			return (0);
	return (1);
}

void	ft_clean_map(t_map *map)
{
	map->map_p = (char **)ft_ft_double_sfree((void **)map->map_p);
}
