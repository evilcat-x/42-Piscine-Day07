/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:02:49 by seli              #+#    #+#             */
/*   Updated: 2018/09/26 18:27:42 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str);

char			*ft_strdup(char *src)
{
	char			*dst;
	unsigned int	srclen;
	unsigned int	i;

	i = 0;
	srclen = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * (srclen + 1));
	while (i < srclen)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return i;
}
