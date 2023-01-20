/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:19:42 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/20 12:49:41 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
# include "error.h"
# include "map_ft.h"

# define PIC_S 50
# define IMAGE_FLORE "image/pink2.xpm"
# define IMAGE_WALL "image/wall.xpm"
# define IMAGE_PLAYER "image/player.xpm"

void	ft_look_name(char *file);

typedef struct s_map
{
	char	*s;
	char	*tmp;
	int		fd;
	int		m_x;
	int		m_y;
	int		collect;
	char	**map_p;
	char	*valid_map;
	void	*flore;
	void	*wall;
}	t_map;

typedef struct s_main
{
	void		*mlx;
	void		*win_p;
	void		*player_p;
	int			player_x;
	int			player_y;
	int			player_1;
	int			player_2;
	int			player_3;
	int			player_4;
	int			player_5;
	int			player_6;
	int			player_7;
	t_map		*m_p;
}	t_main;

void	ft_make_image(t_map *map, t_main *game);
int		print_map(t_main *info);

#endif

//https://github.com/Diego-Luna/42-Projects/blob/c04f26189422c2ff18bea20e155f2e16a5162adb/so_long/libs/so_long.h