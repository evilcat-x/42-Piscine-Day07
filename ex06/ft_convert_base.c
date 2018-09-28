/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:22:05 by seli              #+#    #+#             */
/*   Updated: 2018/09/27 20:14:15 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_size(char *base);
long	ft_atoi(char *str, char *base, int base_size);
int		ft_in_base(char *str, char *base);
int		ft_len(long nb, long base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	result;
	long	divisor;
	char	*str;
	int		i;
	int		base_size;

	base_size = ft_base_size(base_to);
	if (base_size <= 1 || !nbr)
		return (0);
	divisor = 1;
	result = ft_atoi(nbr, base_from, ft_base_size(base_from));
	str = (char *)malloc(sizeof(char) * (ft_len(result, base_size) + 1));
	i = 0;
	if (result < 0)
		str[i++] = '-';
	result = result < 0 ? -result : result;
	while (result > divisor * base_size)
		divisor *= base_size;
	while (divisor != 0)
	{
		str[i++] = base_to[(result / divisor) % base_size];
		divisor /= base_size;
	}
	str[i] = 0;
	return (str);
}

int		ft_len(long nb, long base)
{
	int		len;
	long	divisor;

	len = 1;
	divisor = base;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb >= divisor)
	{
		divisor *= base;
		len++;
	}
	return (len);
}

long	ft_atoi(char *str, char *base, int base_size)
{
	long	result;
	long	prev_result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign = *str++ == '-' ? -1 : 1;
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (result);
		if (ft_in_base(str, base) < 0)
			return (0);
		prev_result = result;
		result = result * base_size + ft_in_base(str, base) * sign;
		if (result / base_size != prev_result)
			return (sign == 1 ? -1 : 0);
		str++;
	}
	return (result);
}

int		ft_in_base(char *str, char *base)
{
	int	n;

	n = 0;
	while (*base)
	{
		if (*str == *base++)
			return (n);
		n++;
	}
	return (-1);
}

int		ft_base_size(char *base)
{
	int		base_size;
	char	*head;

	if (!base)
		return (0);
	base_size = 0;
	while (*base)
	{
		head = base;
		while (*++head)
		{
			if (*head == *base)
				return (0);
		}
		if (*base == '+' || *base == '-')
			return (0);
		base_size++;
		base++;
	}
	return (base_size);
}
