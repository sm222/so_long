/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:19:42 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/22 16:06:08 by anboisve         ###   ########.fr       */
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
	void	*img_flore;
	void	*img_wall;
	void	*img_col;
	void	*img_exit;
}	t_map;

typedef struct s_main
{
	void		*mlx;
	void		*win_p;
	void		*img_player;
	int			player_x;
	int			player_y;
	size_t		move;
	int			player_2;
	int			player_3;
	int			player_4;
	int			player_5;
	int			player_6;
	t_map		*m_p;
}	t_main;

// pre-game
void	ft_look_name(char *file);
void	ft_make_image(t_map *map, t_main *game);
void	set_plaer_cord(t_main *game);

int		print_map(t_main *info);
void	move_player(t_main *game, int new_x, int new_y);
void	ft_clean_map(t_map *map);
int		ft_exit(t_main *game);

#endif
