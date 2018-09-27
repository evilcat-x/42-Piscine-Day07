/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:21:22 by seli              #+#    #+#             */
/*   Updated: 2018/09/26 18:35:00 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

char	*ft_concat_params(int argc, char **argv)
{
	char	*head;
	char	*str;
	int		i_argc;
	int		i_builder;
	int		total;

	i_argc = 0;
	total = 0;
	while (i_argc < argc)
		total += ft_strlen(argv[i_argc++]);
	head = (char *)malloc(sizeof(char) * (total + i_argc));
	i_argc = -1;
	i_builder = 0;
	while (++i_argc < argc)
	{
		str = argv[i_argc];
		while (*str)
			head[i_builder++] = *str++;
		head[i_builder++] = '\n';
	}
	head[i_builder] = 0;
	return (head);
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
