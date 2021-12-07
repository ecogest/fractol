/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:56:15 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 16:08:30 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If size > len(dest):
** - concatenate untill reaching at most a size-len '\0' terminated string
** - return len(dest) + len(src)
** Else if size <= len(dest): do nothing and return size + len_src
**
** Notes:
** - dest is always '\0' terminated
** - space after s1 must be pre-allocated
** - return 0 and leaves dst untouched if !src or !dst (unlike system strcpy)
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	len_dest = 0;
	len_src = 0;
	if (!dest || !src)
		return (0);
	while (dest[len_dest])
		len_dest++;
	while (src[len_src])
		len_src++;
	if (size <= len_dest)
		return (size + len_src);
	i = 0;
	while (size - len_dest - i >= 2 && *src)
		dest[len_dest + i++] = *(src++);
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
