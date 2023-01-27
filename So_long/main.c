/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:23:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/27 14:56:07 by anboisve         ###   ########.fr       */
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

int	ft_exit(t_main *game)
{
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->win_p);
	if (game->m_p)
		ft_clean_map(game->m_p);
	if (game->s)
		free(game->s);
	exit(0);
	return (0);
}

int	player_input(int key, t_main *game)
{
	if (key == 53)
		ft_exit(game);
	if (key == 13 || key == 126)
		move_player(game, 0, -1);
	if (key == 1 || key == 125)
		move_player(game, 0, 1);
	if (key == 2 || key == 124)
		move_player(game, 1, 0);
	if (key == 0 || key == 123)
		move_player(game, -1, 0);
	return (0);
}

void	ft_start_game(int ac, char **av, t_map *map)
{
	map->valid_map = NULL;
	map->map_p = NULL;
	if (ac != 2)
		map->valid_map = ft_get_map(D_MAP, &map->collect);
	else
		map->valid_map = ft_get_map(av[1], &map->collect);
	map->map_p = ft_split(map->valid_map, '\n');
	if (map->valid_map)
		map->valid_map = ft_safe_free(map->valid_map);
	if (!ft_look_side(map->map_p, &map->m_x, &map->m_y))
		ft_error("bad map");
}

int	main(int ac, char **av)
{
	t_main		game;
	t_map		map;

	game.m_p = &map;
	game.move = 0;
	game.frame = 0;
	ft_start_game(ac, av, &map);
	set_plaer_cord(&game);
	ft_playable(&game);
	game.mlx = mlx_init();
	ft_make_image(&map, &game);
	game.win_p = mlx_new_window(game.mlx, map.m_x * PIC_S,
			map.m_y * PIC_S, "so_long");
	mlx_loop_hook(game.mlx, print_map, &game);
	mlx_hook(game.win_p, 02, 0L, player_input, &game);
	mlx_hook(game.win_p, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx);
	system("leaks checker");
	return (0);
}
