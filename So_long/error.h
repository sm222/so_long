/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:49:27 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/29 16:52:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "so_long.h"

//			Define			//

# define ERR_ARGS "too neany args"
# define ERR_MLX "fail to create mlx"
# define ERR_CANT_OPEN "can't open map"
# define ERR_MALLOC "fail to mallorc in : "
# define ERR_MLX_WIN "fail to create mlx window"
# define ERR_BIG_MAP "map is too big, need to be smaller that x 51 y 26"
# define GG " you won!!!"

//			ft			//

void	ft_error(const char *message, int error);

#endif // ERROR_H
