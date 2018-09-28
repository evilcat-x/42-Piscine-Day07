/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:35:50 by seli              #+#    #+#             */
/*   Updated: 2018/09/27 19:12:57 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_word_cout(char *str);
int		ft_word_len(char *str);
char	*ft_copy_string(char *str, int n);

char	**ft_split_whitespaces(char *str)
{
	char	**head;
	int		p;
	int		i;
	int		word_len;

	i = 0;
	p = 0;
	head = (char **)malloc(sizeof(str) * (ft_word_cout(str) + 1));
	if (!head)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (!*str)
			break ;
		word_len = ft_word_len(&str[i]);
		head[p++] = ft_copy_string(&str[i], word_len);
		i += word_len;
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

int		ft_word_cout(char *str)
{
	int		i;
	int		ptr;

	i = 0;
	ptr = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		ptr++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	return (ptr);
}

int		ft_word_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}
