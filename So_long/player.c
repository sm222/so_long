/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:53:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/07 10:29:41 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_plaer_cord(t_main *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->m_p->map_p[y])
	{
		x = 0;
		while (game->m_p->map_p[y][x])
		{
			if (game->m_p->map_p[y][x] == 'P')
			{
				game->player_x = x * PIC_S;
				game->player_y = y * PIC_S;
			}
			x++;
		}
		y++;
	}
}

void	move_player(t_main *game, int new_x, int new_y)
{
	if (game->player_y + new_y > 0 && game->player_y
		/ PIC_S + new_y < game->m_p->m_y)
	{
		if (game->m_p->map_p[game->player_y / PIC_S + new_y]
			[game->player_x / PIC_S + new_x] != '1')
		{
			game->player_x += new_x * PIC_S;
			game->player_y += new_y * PIC_S;
			game->move++;
			ft_printf("move %u\n", game->move);
			if (game->m_p->map_p[game->player_y / PIC_S]
				[game->player_x / PIC_S] == 'C')
			{
				game->m_p->map_p[game->player_y / PIC_S]
				[game->player_x / PIC_S] = '0';
				game->m_p->collect--;
			}
			if (game->m_p->map_p[game->player_y / PIC_S]
				[game->player_x / PIC_S] == 'E'
				&& game->m_p->collect <= 0)
				ft_exit(game, ft_combine(NAME GG), 0);
		}
	}
}
