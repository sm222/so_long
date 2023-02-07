/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:19:42 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/07 11:25:47 by anboisve         ###   ########.fr       */
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
# include "lib_ft/libft.h"
# include "error.h"

//			Define			//

# define PIC_S 50
# define D_MAP "maps/map.ber"

# ifndef NAME
#  define NAME "NO NAME"
# endif

//		art		//

//	vinyl	//
# define IMAGE_V1 "image/vinyl1.xpm"
# define IMAGE_V2 "image/vinyl2.xpm"
# define IMAGE_V3 "image/vinyl3.xpm"
# define IMAGE_V4 "image/vinyl4.xpm"
# define IMAGE_V5 "image/vinyl5.xpm"
# define IMAGE_V6 "image/vinyl6.xpm"

//	prop	//
# define IMAGE_EXIT "image/exit.xpm"
# define IMAGE_WALL "image/wall1.xpm"
# define IMAGE_WALL1 "image/wall2.xpm"
# define IMAGE_WALL2 "image/wall3.xpm"

//	player	//
# define IMAGE_PLY "image/player.xpm"
# define IMAGE_PLY2 "image/player2.xpm"

//	other	//
# define IMAGE_FLORE "image/flore.xpm"

//			struct			//

typedef struct s_map
{
	char	*s;
	char	*tmp;
	int		fd;
	int		m_x;
	int		m_y;
	int		collect;
	int		exit_swich;
	char	**map_p;
	char	*valid_map;
	void	*img_flore;
	void	*img_wall[3];
	void	*img_col[6];
	void	*img_exit;
}	t_map;

typedef struct s_get_map
{
	char	*tmp;
	char	*new;
	int		fd;
}	t_get_map;

typedef struct s_valid_map
{
	int		player;
	int		colect;
	int		e;
	size_t	i;
	char	invalid[1];
}	t_valid_map;

typedef struct s_flood
{
	int		find;
	int		exit;
	char	**map;
}	t_flood;

typedef struct s_main
{
	void		*mlx;
	void		*win_p;
	void		*img_player[2];
	int			p_dir;
	int			player_x;
	int			player_y;
	size_t		move;
	int			frame;
	char		*s;
	t_map		*m_p;
}	t_main;

//			ft			//

// pre-game
void	ft_look_name(char *file);
int		ft_playable(t_main *info);
void	set_plaer_cord(t_main *game);
int		ft_valid_all_side(t_main *game);
int		ft_valid_map(t_main *game, char *map_s);
void	ft_make_image(t_map *map, t_main *game);
void	ft_setup(t_main *info, int ac, char **av);
void	ft_start_game(int ac, char **av, t_main *info);
char	*ft_get_map(char *f_name, int *colect, t_main *info);
int		ft_look_side(t_main *game, int *size_x, int *size_y);

// game logic
int		print_map(t_main *info);
void	ft_clean_map(t_map *map);
void	move_player(t_main *game, int new_x, int new_y);
int		ft_exit(t_main *game, char *f_message, int error);
void	ft_put_tile(t_main *info, int x, int y, void *img);

// other 
int		ft_escape(t_main *game);
void	ft_free_all(t_main *info);
void	ft_free_image(t_main *info);
int		new_trgb(int t, int r, int g, int b);

//export MallocStackLogging=0
#endif
