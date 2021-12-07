/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:16:08 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 11:51:50 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return byte_s1 - byte_s2 as soon as they differ (return 0 after n bytes).
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s;
	const unsigned char	*t;
	size_t				i;

	s = s1;
	t = s2;
	i = 0;
	while (i < n)
	{
		if (s[i] != t[i])
			return (s[i] - t[i]);
		else
			i++;
	}
	return (0);
}
