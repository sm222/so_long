/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:23:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/20 12:56:36 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	look for a file name that end with '.ber'
		start form the end and return the addres in s
		and use strncmp to see if the name match.
*/
void	ft_look_name(char *file)
{
	char	*s;

	s = ft_strrchr(file, '.');
	if (!s || ft_strncmp(s, ".ber", ft_strlen(s) + 1) != 0)
		ft_error("bad file name");
}

void	move_player(t_main *game, int new_x, int new_y)
{
	if (game->player_y + new_y > 0 && game->player_y
		/ PIC_S + new_y < game->m_p->m_y)
	{
		if (game->m_p->map_p[game->player_y / PIC_S + new_y]
			[game->player_x / PIC_S + new_x] != '1')
		{
			game->player_x += new_x * PIC_S;
			game->player_y += new_y * PIC_S;
		}
	}
}

int	test_key(int key, t_main *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win_p);
		exit (0);
	}
	if (key == 13)
		move_player(game, 0, -1);
	if (key == 1)
		move_player(game, 0, 1);
	if (key == 2)
		move_player(game, 1, 0);
	if (key == 0)
		move_player(game, -1, 0);
	return (0);
}

int	ft_exit(t_main *game)
{
	mlx_destroy_window(game->mlx, game->win_p);
	exit(0);
	return (0);
}

void	ft_start_game(int ac, char **av, t_map *map)
{
	map->valid_map = NULL;
	map->map_p = NULL;
	if (ac != 2)
		map->valid_map = ft_get_map("map.ber", &map->collect);
	else
		map->valid_map = ft_get_map(av[1], &map->collect);
	map->map_p = ft_split(map->valid_map, '\n');
	if (map->valid_map)
		map->valid_map = ft_safe_free(map->valid_map);
	if (!ft_look_side(map->map_p, &map->m_x, &map->m_y))
		ft_error("bad map");
}

void	set_plaer_cord(t_main *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->m_p->map_p[y])
	{
		x = 0;
		while (game->m_p->map_p[y][x])
		{
			if (game->m_p->map_p[y][x] == 'P')
			{
				game->player_x = x * PIC_S;
				game->player_y = y * PIC_S;
			}
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_main		game;
	t_map		map;

	game.m_p = &map;
	ft_start_game(ac, av, &map);
	set_plaer_cord(&game);
	game.mlx = mlx_init();
	ft_make_image(&map, &game);
	game.win_p = mlx_new_window(game.mlx, map.m_x * PIC_S,
			map.m_y * PIC_S, "so_long");
	mlx_loop_hook(game.mlx, print_map, &game);
	mlx_key_hook(game.win_p, test_key, &game);
	mlx_hook(game.win_p, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
