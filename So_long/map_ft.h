/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:16:02 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/19 18:41:54 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FT_H
# define MAP_FT_H
# include "so_long.h"

char	*ft_get_map(char *f_name, int *colect);
int		ft_valid_all_side(char **map);
int		ft_valid_map(char *map_s);
int		ft_look_side(char **map, int *size_x, int *size_y);

#endif 
