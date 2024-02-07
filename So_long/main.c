/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:23:33 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/06 21:37:07 by anboisve         ###   ########.fr       */
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
	char	*tmp;
	char	*s;

	tmp = ft_strrchr(file, '.');
	if (!tmp || ft_strncmp(tmp, ".ber", ft_strlen(tmp) + 1) != 0)
	{
		s = ft_combine("bad file name");
		ft_error(s, 1);
	}
}

/*
	set all value to null
*/
void	ft_null(t_main *game)
{
	int	i;

	game->move = 0;
	game->frame = 0;
	game->p_dir = 0;
	game->s = NULL;
	game->mlx = NULL;
	game->win_p = NULL;
	game->m_p->s = NULL;
	game->m_p->tmp = NULL;
	game->img_player[0] = NULL;
	game->img_player[1] = NULL;
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
	if (key == 53 || key == 65307)
		ft_exit(game, ft_combine("Goodbye!"), 0);
	if (key == 'w' || key == 126)
		move_player(game, 0, -1);
	if (key == 's' || key == 125)
		move_player(game, 0, 1);
	if (key == 2 || key == 'd')
	{
		move_player(game, 1, 0);
		game->p_dir = 0;
	}
	if (key == 0 || key == 'a')
	{
		move_player(game, -1, 0);
		game->p_dir = 1;
	}
	return (0);
}

/*
	start by seting all to NULL
	get the map information and do the parsing
*/
void	ft_start_game(int ac, char **av, t_main *info)
{
	ft_null(info);
	if (ac == 1)
		info->m_p->valid_map = ft_get_map(D_MAP, &info->m_p->collect, info);
	else if (ac == 2)
		info->m_p->valid_map = ft_get_map(av[1], &info->m_p->collect, info);
	else
		ft_exit(info, ft_combine(ERR_ARGS), 1);
	if (!info->m_p->valid_map)
		ft_exit(info, ft_combine(ERR_MALLOC"ft_get_map"), 1);
	info->m_p->map_p = ft_split(info->m_p->valid_map, '\n');
	if (!info->m_p->map_p)
		ft_exit(info, ft_combine(ERR_MALLOC "ft_split"), 1);
	if (info->m_p->valid_map)
		info->m_p->valid_map = ft_safe_free(info->m_p->valid_map);
	ft_look_side(info, &info->m_p->m_x, &info->m_p->m_y);
}

int	main(int ac, char **av)
{
	t_main		game;
	t_map		map;

	game.m_p = &map;
	ft_setup(&game, ac, av);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_exit(&game, ft_combine(ERR_MLX), 1);
	ft_make_image(&map, &game);
	game.win_p = mlx_new_window(game.mlx, map.m_x * PIC_S, \
	map.m_y * PIC_S, "so_long");
	if (!game.win_p)
		ft_exit(&game, ft_combine(ERR_MLX_WIN), 1);
	mlx_do_key_autorepeaton(game.mlx);
	mlx_loop_hook(game.mlx, print_map, &game);
	mlx_key_hook(game.win_p, &player_input, &game);
	mlx_hook(game.win_p, 17, 0, ft_escape, &game);
	mlx_loop(game.mlx);
	return (0);
}
