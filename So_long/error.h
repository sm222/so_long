/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:49:27 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/10 12:29:04 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "so_long.h"

void	ft_error(const char *message);
void	ft_bad_map(char **map, const char *msg);

#endif // ERROR_H
