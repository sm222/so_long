/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:23:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/04 18:14:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*g_img;
mlx_image_t	*g_img2;
mlx_image_t	*g_player;

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
		g_player->instances[0].y -= 50;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx, MLX_KEY_S))
		g_player->instances[0].y += 50;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_A))
		g_player->instances[0].x -= 50;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		g_player->instances[0].x += 50;
}

void	ft_putbackground(mlx_t	*mlx, int size_x, int size_y)
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
				mlx_image_to_window(mlx, g_img, x, y);
			else if (y % 100 == 0)
				mlx_image_to_window(mlx, g_img, x, y + IMAGE_SIZE);
			y += IMAGE_SIZE;
		}
		x += IMAGE_SIZE;
	}
}

int	main(void)
{
	mlx_t	*mlx;
	t_index	index;
	int		x;
	int		y;
	
	x = 50;
	y = 10;
	index.x[0] = 50;
	index.y[0] = 50;
	mlx = mlx_init(x * IMAGE_SIZE, y * IMAGE_SIZE, "test", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_player = make_image("player.xpm42", mlx);
	g_img = make_image("pink.xpm42", mlx);
	g_img2 = make_image("black.xpm42", mlx);
	ft_putbackground(mlx, x, y);
	mlx_image_to_window(mlx, g_player, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	//mlx_key_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
