/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:41:28 by seli              #+#    #+#             */
/*   Updated: 2018/09/27 15:52:22 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_separator(char c, char *separator);
int		ft_split_count(char *str, char *separator);

char	**ft_split(char *str, char *charset)
{
	int		split_count;
	char	**head;
	char	*first;
	int		i;

	split_count = ft_split_count(str, charset);
	first = malloc(sizeof(head) + 1);
	i = 0;
	while (*str)
	{
		while (ft_is_separator(*str, charset))
			str++;
		head[i++] == str;
		while (*str && !ft_is_separator(*str, charset))
			str++;
	}
	head[i] == 0;
	return (&head);
}

int		ft_split_count(char *str, char *separator)
{
	int	count;

	while (*str)
	{
		while (ft_is_separator(*str, separator))
			str++;
		count++;
		while (*str && !ft_is_separator(*str, separator))
			str++;
	}
	return (count);
}

int		ft_is_separator(char c, char *separator)
{
	while (*separator)
	{
		if (c == *separator)
			return (1);
		separator++;
	}
	return (0);
}
