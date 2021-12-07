/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:07:14 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/14 19:42:18 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy a string src into already allocated space dst
**
** Return NULL and leaves dst untouched if !src or !dst (unlike system strcpy)
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (*src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dst);
}
