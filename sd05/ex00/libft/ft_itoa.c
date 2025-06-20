/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by tfalchi           #+#    #+#             */
/*   Updated: 2025/01/10 11:21:11 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_number(int num_len, long b)
{
	long	i;
	char	*array;
	char	c;

	i = 0;
	array = (char *)ft_calloc(sizeof(char), (num_len + 1));
	if (array == NULL)
		return (NULL);
	if (b < 0)
	{
		array[0] = '-';
		b = -b;
	}
	if (b == 0)
		array[0] = '0';
	while (b > 0)
	{
		c = (b % 10) + '0';
		array[num_len - i - 1] = c;
		b = b / 10;
		i++;
	}
	array[num_len] = '\0';
	return (array);
}

static int	ft_check_len(long n)
{
	long		i;
	size_t		num;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		num = n;
		i++;
	}
	else
		num = n;
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		num_len;
	long	a;
	char	*number;

	a = n;
	num_len = ft_check_len(a);
	number = make_number(num_len, a);
	return (number);
}
