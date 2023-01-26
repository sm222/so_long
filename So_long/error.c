/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:10:53 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/26 17:29:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_error(const char *message)
{
	printf("Error!\n");
	printf("%s\n", message);
	exit(0);
}

void	ft_bad_map(char **map, const char *msg)
{
	ft_ft_double_sfree((void **)map);
	ft_error(msg);
}
