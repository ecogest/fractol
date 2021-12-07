/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:44:46 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/14 13:05:36 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Search haystack for a needle. Return matching haystack pointer.
**
** Return NULL if haystack or needle is NULL.
**
** Note : the system strstr segfaults in such cases.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	while (needle[i] && haystack[i] == needle[i])
		i++;
	if (!needle[i])
		return ((char *)haystack);
	else if (*haystack)
		return (ft_strstr(haystack + 1, needle));
	else
		return (NULL);
}
