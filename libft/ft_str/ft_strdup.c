/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:43:47 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 18:01:00 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Duplicate a string (malloc and copy)
**
** Note: return NULL is !s1 (unlike system's strdup) or if malloc fails
*/

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s1)
		dest[i++] = *s1++;
	dest[i] = '\0';
	return (dest);
}
