/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:44:12 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/31 17:41:30 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_arg(va_list list, char type)
{
	if (type == 's')
		return (va_arg(list, char *));
	else if (type == 'd')
		return (ft_itoa(va_arg(list, int)));
	else if (type == '%')
		return (ft_strdup("%"));
	return (NULL);
}

static char	*ft_add_str(va_list list, char type, char *s)
{
	char	*t;

	t = add_arg(list, type);
	s = ft_strfjoin(s, t);
	ft_safe_free(t);
	return (s);
}

char	*ft_combine(char *s, ...)
{
	size_t	i;
	char	*new;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	new = ft_calloc(1, sizeof(char));
	while (s[i])
	{
		if (s[i] != '%')
		{
			new = ft_realloc(new, ft_strlen(new) + 1, sizeof(char));
			if (!new)
				return (NULL);
			new[i] = s[i];
			i++;
		}
		else
		{
			new = ft_add_str(arg, s[++i], new);
			i++;
		}
	}
	return (new);
}
