/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:07:49 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/19 12:44:41 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Update one string by appending n chars from a second one
**
** If success, return *str, else return (NULL)
*/

char	*ft_strnappend(char **str, const char *part2, size_t n)
{
	char	*tmp;

	if (!str | !part2)
		return (NULL);
	if (!n)
		return (*str);
	tmp = ft_strnjoin(*str, part2, n);
	if (!tmp)
		return (NULL);
	free(*str);
	*str = tmp;
	return (*str);
}
