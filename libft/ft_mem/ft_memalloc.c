/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:55:15 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 19:52:14 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** Malloc n bytes, or 1 byte if (n = 0).
*/

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = ft_calloc(size, 1);
	if (!mem)
		return (NULL);
	else
		return (mem);
}
