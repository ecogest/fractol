/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:26:08 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 15:27:11 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concatenate s2 after s1
**
** Notes:
** - space after s1 must be pre-allocated
** - Return NULL and leaves s1 untouched if !s1 or !s2 (unlike system strcat)
*/

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}
