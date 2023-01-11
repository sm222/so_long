/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:10:53 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/10 10:50:02 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_error(const char *message)
{
	printf("Error!\n");
	printf("%s\n", message);
	exit(-1);
}

void	ft_bad_map(char **map, const char *msg)
{
	size_t	i;

	i = 0;
	while (map[i])
		free(map[i]);
	free(map);
	ft_error(msg);
}
