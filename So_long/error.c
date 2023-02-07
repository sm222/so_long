/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:10:53 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/07 09:30:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_error(char *f_message, int error)
{
	if (error)
		printf("Error!\n");
	if (f_message)
		ft_printf("%s\n", f_message);
	else
		ft_printf("fail malloc in ft_combine");
	ft_safe_free(f_message);
	exit(0);
}

int	ft_exit(t_main *game, char *f_message, int error)
{
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->win_p);
	ft_free_all(game);
	ft_error(f_message, error);
	return (0);
}

int	ft_escape(t_main *game)
{
	char	*s;

	s = ft_combine("goodbye!");
	return (ft_exit(game, s, 0));
}
