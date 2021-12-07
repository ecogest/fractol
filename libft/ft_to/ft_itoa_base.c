/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:57:25 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 20:34:21 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_length(unsigned long long n, int base)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		size++;
		n /= base;
	}
	return (size);
}

/*
** Convert unsigned long long to string, according to a base between 2 and 16.
**
** On utilise un double car les adresses (pointeurs) à convertir en hexa
** dépassent la taille d'un int ou d'un unsigned int.
*/

char	*ft_itoa_base(unsigned long long n, int base)
{
	char				*base_char;
	char				*ret;
	int					len_nbr;

	if (base > 16 || base < 2)
		return (NULL);
	base_char = "0123456789ABCDEF";
	len_nbr = number_length(n, base);
	ret = (char *)malloc(sizeof(char) * (len_nbr + 1));
	if (!ret)
		return (NULL);
	ret[len_nbr] = '\0';
	while (len_nbr--)
	{
		ret[len_nbr] = base_char[n % (unsigned long long)base];
		n /= (unsigned long long)base;
	}
	return (ret);
}
