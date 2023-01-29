/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:23:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/29 13:54:50 by anboisve         ###   ########.fr       */
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
		ft_error("bad file name", 1);
}

/*
	set all value to null
*/
void	ft_null(t_main *game)
{
	int	i;

	game->s = NULL;
	game->mlx = NULL;
	game->win_p = NULL;
	game->m_p->s = NULL;
	game->m_p->tmp = NULL;
	game->img_player = NULL;
	game->img_player = NULL;
	game->m_p->map_p = NULL;
	game->m_p->img_exit = NULL;
	game->m_p->valid_map = NULL;
	game->m_p->img_flore = NULL;
	i = 6;
	while (i--)
		game->m_p->img_col[i] = NULL;
	i = 3;
	while (i--)
		game->m_p->img_wall[i] = NULL;
}

/*
	get player input
		13 || 126 = up
		1  || 125 = down
		2  || 124 = rigth
		0  || 123 = left
*/
int	player_input(int key, t_main *game)
{
	if (key == 53)
		ft_exit(game, "goodbye!", 0);
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

/*
	start by seting all to NULL
	get the map information and do the parsing
*/
void	ft_start_game(int ac, char **av, t_main *info)
{
	ft_null(info);
	if (ac != 2)
		info->m_p->valid_map = ft_get_map(D_MAP, &info->m_p->collect, info);
	else
		info->m_p->valid_map = ft_get_map(av[1], &info->m_p->collect, info);
	if (!info->m_p->valid_map)
		ft_exit(info, ERR_MALLOC "ft_get_map", 0);
	info->m_p->map_p = ft_split(info->m_p->valid_map, '\n');
	if (!info->m_p->map_p)
		ft_exit(info, ERR_MALLOC "ft_split", 0);
	if (info->m_p->valid_map)
		info->m_p->valid_map = ft_safe_free(info->m_p->valid_map);
	if (!ft_look_side(info, &info->m_p->m_x, &info->m_p->m_y))
		ft_exit(info, "invalid map", 1);
}

int	main(int ac, char **av)
{
	t_main		game;
	t_map		map;

	game.m_p = &map;
	game.move = 0;
	game.frame = 0;
	ft_start_game(ac, av, &game);
	set_plaer_cord(&game);
	ft_playable(&game);
	game.mlx = mlx_init();
	ft_make_image(&map, &game);
	game.win_p = mlx_new_window(game.mlx, map.m_x * PIC_S, \
	map.m_y * PIC_S, "so_long");
	mlx_loop_hook(game.mlx, print_map, &game);
	mlx_hook(game.win_p, 02, 0L, player_input, &game);
	mlx_hook(game.win_p, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
