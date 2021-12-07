/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:48:21 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 11:40:36 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns pointer to first occurence of c (as unsigned char), NULL if not found
*/

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*pos;
	unsigned char		target;

	pos = src;
	target = c;
	while (n--)
	{
		if (*pos == target)
			return ((void *)pos);
		pos++;
	}
	return (NULL);
}
