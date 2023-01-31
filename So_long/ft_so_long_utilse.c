/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utilse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:17:16 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/31 13:31:43 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_image(t_main *info)
{
	int	i;

	if (info->img_player)
		mlx_destroy_image(info->mlx, info->img_player);
	if (info->m_p->img_exit)
		mlx_destroy_image(info->mlx, info->m_p->img_exit);
	if (info->m_p->img_flore)
		mlx_destroy_image(info->mlx, info->m_p->img_flore);
	i = 6;
	while (i--)
		if (info->m_p->img_col[i])
			mlx_destroy_image(info->mlx, info->m_p->img_col[i]);
	i = 3;
	while (i--)
		if (info->m_p->img_wall[i])
			mlx_destroy_image(info->mlx, info->m_p->img_wall[i]);
}

void	ft_free_all(t_main *info)
{
	if (info->m_p->map_p)
		ft_ft_double_sfree((void **)info->m_p->map_p);
	ft_safe_free(info->m_p->valid_map);
	ft_safe_free(info->m_p->tmp);
	ft_safe_free(info->err_msg);
	ft_safe_free(info->m_p->s);
	ft_safe_free(info->s);
	ft_free_image(info);
}

int	new_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_put_tile(t_main *info, int x, int y, void *img)
{
	mlx_put_image_to_window(info->mlx, info->win_p, img,
		x * PIC_S, y * PIC_S);
}
