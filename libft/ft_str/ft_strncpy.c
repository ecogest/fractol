/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:14:35 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 16:10:01 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

/*
** Copy min(strlen(src), n) chars of src, then fill (n - strlen(src)) with '\0'
**
** Notes:
** - if n <= strlen(src), dst is NOT '\0' terminated.
** - space after dst must be pre-allocated
** - Return NULL and do nothing if !src or !dst (unlike system strcnpy)
*/

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
		dst[i++] = '\0';
	return (dst);
}
