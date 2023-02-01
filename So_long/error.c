/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:10:53 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/01 09:08:51 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_error(const char *message, int error)
{
	if (error)
		printf("Error!\n");
	ft_printf("%s\n", message);
	exit(0);
}

int	ft_exit(t_main *game, const char *message, int error)
{
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->win_p);
	ft_free_all(game);
	ft_error(message, error);
	return (0);
}

int	ft_escape(t_main *game)
{
	return (ft_exit(game, "Goodbye!", 0));
}
