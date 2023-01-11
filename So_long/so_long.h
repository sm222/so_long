/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:19:42 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/11 15:15:41 by anboisve         ###   ########.fr       */
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

# define IMAGE_SIZE 50

void	ft_look_name(char *file);
typedef struct s_get_map
{
	char	*s;
	char	*tmp;
	int		fd;
}	t_get_map;

#endif

//https://github.com/Diego-Luna/42-Projects/blob/c04f26189422c2ff18bea20e155f2e16a5162adb/so_long/libs/so_long.h