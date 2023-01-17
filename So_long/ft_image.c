/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:43:47 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:20 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_image(t_main *game, char *name)
{
	int		x;
	int		y;

	game->player_p = mlx_xpm_file_to_image(game->mlx, name, &x, &y);
}
