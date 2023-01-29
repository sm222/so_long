/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 09:01:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/13 18:20:17 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (++i < n)
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
	return (NULL);
}
