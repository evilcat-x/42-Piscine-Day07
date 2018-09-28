/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:41:28 by seli              #+#    #+#             */
/*   Updated: 2018/09/27 19:10:28 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_separator(char c, char *separator);
int		ft_split_count(char *str, char *separator);
int		ft_word_len(char *str, char *separator);
char	*ft_copy_string(char *str, int n);

char	**ft_split(char *str, char *charset)
{
	char	**head;
	int		i;
	int		p;
	int		word_len;

	p = 0;
	head = (char **)malloc(sizeof(str) * (ft_split_count(str, charset) + 1));
	if (!head)
		return (0);
	while (*str)
	{
		while (ft_is_separator(*str, charset))
			str++;
		word_len = ft_word_len(str, charset);
		head[p++] = ft_copy_string(str, word_len);
		str += word_len;
	}
	head[p] = 0;
	return (head);
}

char	*ft_copy_string(char *str, int n)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

int		ft_word_len(char *str, char *separator)
{
	int i;

	i = 0;
	while (str[i] && !ft_is_separator(str[i], separator))
		i++;
	return (i);
}

int		ft_split_count(char *str, char *separator)
{
	int	count;

	count = 0;
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
