/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:19:59 by anboisve          #+#    #+#             */
/*   Updated: 2024/02/06 08:55:24 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if (((char *)s)[i] == (char)c)
			return (((char *)s) + i);
		i--;
	}
	return (NULL);
}
