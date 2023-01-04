/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:19:42 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/04 18:22:16 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define IMAGE_SIZE 50

typedef struct s_data
{
	mlx_t		mlx;
	mlx_image_t	*player;
	mlx_image_t	*ground;
	mlx_image_t	*wall;

}	t_data;

#endif // SO_LONG_H
