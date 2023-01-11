/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:23:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/11 17:25:20 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_look_name(char *file)
{
	char	*s;

	s = ft_strrchr(file, '.');
	if (!s || ft_strncmp(s, ".ber", ft_strlen(s) + 1) != 0)
		ft_error("bad file name");
}

int	main(int ac, char **av)
{
	char	*map;
	char	**new_map;
	int		i;
	int		colect;

	i = 0;
	new_map = NULL;
	if (ac == 2)
		map = ft_get_map(av[1], &colect);
	else
		map = ft_get_map("map.ber", &colect);
	if (map != NULL)
		new_map = ft_split(map, '\n');
	if (new_map != NULL)
		while (new_map[i])
			printf("%s\n", new_map[i++]);
	if (ft_look_side(new_map))
		printf("\ngood\n");
	else
		printf("\nbad\n");
}

/*
mlx_image_t	*make_image(char *path, mlx_t *mlx)
{
	mlx_image_t	*image;
	xpm_t		*xpm;

	xpm = mlx_load_xpm42(path);
	image = mlx_texture_to_image(mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	return (image);
}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx, MLX_KEY_W))
		data->player->instances[0].y -= 50;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		data->player->instances[0].y += 50;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		data->player->instances[0].x -= 50;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		data->player->instances[0].x += 50;
}

void	ft_putbackground(t_data	*data, int size_x, int size_y)
{
	int	y;
	int	x;

	x = 0;
	while (x < size_x * 50)
	{
		y = 0;
		while (y < size_y * 50)
		{
			if (y % 100 == 0 && x % 100 == 0)
				mlx_image_to_window(data->mlx, data->wall, x, y);
			else if (y % 100 == 0)
				mlx_image_to_window(data->mlx, data->wall, x, y + IMAGE_SIZE);
			y += IMAGE_SIZE;
		}
		x += IMAGE_SIZE;
	}
}

int	main(void)
{
	int		x;
	int		y;
	mlx_t	*mlx;
	t_data	data;

	x = 50;
	y = 10;
	data.mlx = mlx_init();
	data.game = mlx_new_winow(x * IMAGE_SIZE, y * IMAGE_SIZE, "test", false);
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.player = make_image("player.xpm42", data.mlx);
	data.ground = make_image("pink.xpm42", data.mlx);
	ft_putbackground(&data, x, y);
	mlx_image_to_window(data.mlx, data.player, 0, 0);
	mlx_loop_hook(data.mlx, &hook, data.mlx);
	//mlx_key_hook(mlx, hook, mlx);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
*/
