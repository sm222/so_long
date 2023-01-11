/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:16:02 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/11 17:25:36 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FT_H
# define MAP_FT_H
# include "so_long.h"

char	*ft_get_map(char *f_name, int *colect);
int		ft_valid_map(char *map_s);
int		ft_look_side(char **map);

#endif 
