/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:49:27 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/29 10:43:12 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "so_long.h"

//			Define			//

# define ERR_MALLOC "fail to mallorc in : "

//			ft			//

void	ft_error(const char *message, int error);

#endif // ERROR_H
