/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:32:07 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/08 18:14:57 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		n;

	if (!s)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (((char *)s)[i] == (unsigned char)c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}
