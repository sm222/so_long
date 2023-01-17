/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:23:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/17 17:27:58 by anboisve         ###   ########.fr       */
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

int	test_key(int key, t_main *game)
{
	if (key == 53)
	{
		if (game->map_p)
			ft_ft_double_sfree((void **)game->map_p);
		mlx_destroy_window(game->mlx, game->win_p);
		exit (0);
	}
	if (key == 13 && game->player_p)
	{
		mlx_destroy_image(game->mlx, game->player_p);
		game->player_p = NULL;
	}
	else
		printf("\n%d", key);
	return (0);
}

int	ft_exit(t_main *game)
{
	if (game->map_p)
		ft_ft_double_sfree((void **)game->map_p);
	mlx_destroy_window(game->mlx, game->win_p);
	exit(0);
	return (0);
}

void	ft_start_game(t_main *data, int ac, char **av)
{
	data->map_p = NULL;
	data->valid_map = NULL;
	if (ac != 2)
		data->valid_map = ft_get_map("map.ber", &data->colect);
	else
		data->valid_map = ft_get_map(av[1], &data->colect);
	data->map_p = ft_split(data->valid_map, '\n');
	if (data->valid_map)
		data->valid_map = ft_safe_free(data->valid_map);
	if (!ft_look_side(data->map_p, &data->m_x, &data->m_y))
		ft_error("bad map");
}

int	main(int ac, char **av)
{
	t_main	game;
	int		i;

	i = 0;
	ft_start_game(&game, ac, av);
	ft_make_image(&game, "player.xpm");
	game.mlx = mlx_init();
	game.win_p = mlx_new_window(game.mlx, game.m_x * PIC_S,
			game.m_y * PIC_S, "so_long");
	mlx_key_hook(game.win_p, test_key, &game);
	mlx_hook(game.win_p, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
