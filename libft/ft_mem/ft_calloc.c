/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:29:11 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 10:58:28 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloc n * p bytes, or 1 bytes if (n * p == 0).
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	int		n;

	if (count && size)
		n = count * size;
	else
		n = 1;
	mem = malloc(n);
	if (mem)
		ft_bzero(mem, n);
	return (mem);
}
