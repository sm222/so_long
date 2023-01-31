/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:16 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/11 09:05:32 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_of_unb(unsigned long long nb, int base)
{
	int	size;

	size = 0;
	while (nb)
	{
		size++;
		nb /= base;
	}
	return (size);
}

char	*ft_ulltoa(unsigned long long nb, int base)
{
	char		*result;
	int			i;

	i = ft_size_of_unb(nb, base);
	if (nb == 0)
		i++;
	result = ft_calloc(i + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (i--)
	{
		result[i] = HEX_TABLE[nb % base];
		nb /= base;
	}
	return (result);
}
