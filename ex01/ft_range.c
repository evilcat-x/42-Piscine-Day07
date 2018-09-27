/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:26:26 by seli              #+#    #+#             */
/*   Updated: 2018/09/26 18:16:49 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *head;
	int	i;

	if (min >= max)
		return ((void *)0);
	head = (int *)malloc(sizeof(int) * (max - min));
	if (!head)
		return ((void *)0);
	i = 0;
	while (min + i < max)
	{
		head[i] = min + i;
		i++;
	}
	return (head);
}
