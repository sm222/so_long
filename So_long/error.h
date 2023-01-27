/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:49:27 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/27 10:32:50 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "so_long.h"

//			Define			//

# define ERR_MALLOC "fail to mallorc in : "

//			ft			//

void	ft_error(const char *message);
void	ft_bad_map(char **map, const char *msg);

#endif // ERROR_H
