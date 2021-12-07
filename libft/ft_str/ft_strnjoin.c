/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:09:55 by mjacq             #+#    #+#             */
/*   Updated: 2021/09/24 09:54:47 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return concatenation of s1 and up to n characters from s2
*/

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	char	*dst;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len2 = ft_strlen(s2);
	if (n > len2)
		n = len2;
	dst = malloc(sizeof(*dst) * (ft_strlen(s1) + n + 1));
	if (dst)
	{
		ft_strcpy(dst, s1);
		ft_strncat(dst, s2, n);
	}
	return (dst);
}
