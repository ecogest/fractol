/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:06:03 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/19 10:16:40 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Join two strings into the first one
**
** If success, return *str, else return (NULL)
*/

char	*ft_strappend(char**str, const char *suffix)
{
	char	*tmp;

	if (!suffix || !str)
		return (NULL);
	tmp = ft_strjoin(*str, suffix);
	if (!tmp)
		return (NULL);
	free(*str);
	*str = tmp;
	return (*str);
}
