/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:50:54 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 16:12:06 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If size:
** - copy at most size - 1 chars of src, then '\0' terminate
** Else: do nothing
**
** Return: strlen(src) (whatever the size)
**
** Notes:
** - dest is always '\0' terminated
** - space after s1 must be pre-allocated
** - return 0 and leaves dst untouched if !src or !dst (unlike system strcpy)
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (*src && i + 2 <= size)
		dest[i++] = *src++;
	if (size)
		dest[i] = '\0';
	while (*src++)
		i++;
	return (i);
}
