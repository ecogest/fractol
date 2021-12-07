/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:56:51 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 19:50:04 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_length(int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

/*
** Convert int to string.
*/

char	*ft_itoa(int n)
{
	char	*s;
	size_t	size;
	int		i;

	size = number_length(n);
	s = (char *)malloc(sizeof(*s) * (size + 1));
	if (!s)
		return (NULL);
	s[size] = '\0';
	i = n;
	while (size--)
	{
		s[size] = '0' + ft_int_abs(n % 10);
		n /= 10;
	}
	if (i < 0)
		s[0] = '-';
	return (s);
}
