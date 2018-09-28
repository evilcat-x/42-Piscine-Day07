/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:35:50 by seli              #+#    #+#             */
/*   Updated: 2018/09/27 17:36:41 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_word_cout(char *str);

char	**ft_split_whitespaces(char *str)
{
	char	**head;
	int		p;
	int		i;

	i = 0;
	p = 0;
	head = (char **)malloc(sizeof(str) * (ft_word_cout(str) + 1));
	if (!head)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		head[p++] = &str[i];
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	head[p] = 0;
	return (head);
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
