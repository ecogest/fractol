/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:01:06 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 20:10:26 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return a newly allocated string filled with s1 and s2 concatenated.
**
** Note:
** - to free s1 at the same time, see ft_strappend
** - return NULL if s1 or s2 is NULL
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(dest))
		return (NULL);
	i = 0;
	while (*s1)
		dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
