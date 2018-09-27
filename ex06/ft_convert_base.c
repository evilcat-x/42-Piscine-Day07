/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:22:05 by seli              #+#    #+#             */
/*   Updated: 2018/09/27 15:53:55 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	ft_convert_char(char c, char *from, char *to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbrlen;
	char	*dst;
	int		i;

	i = 0;
	nbrlen = ft_strlen(nbr);
	dst = (char *)malloc(sizeof(char) * (nbrlen + 1));
	if (!dst)
		return ((void *)0);
	while (nbr[i])
	{
		dst[i] = ft_convert_char(nbr[i], base_from, base_to);
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	ft_convert_char(char c, char *from, char *to)
{
	while (*from)
	{
		if (c == *from)
			return (*to);
		from++;
		to++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
