/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:32:05 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 19:51:29 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memcpy_opti(void **d, const void **src, size_t *n)
{
	while (*n >= sizeof(t_op) * 8)
	{
		((t_op *)*d)[0] = ((const t_op *)*src)[0];
		((t_op *)*d)[1] = ((const t_op *)*src)[1];
		((t_op *)*d)[2] = ((const t_op *)*src)[2];
		((t_op *)*d)[3] = ((const t_op *)*src)[3];
		((t_op *)*d)[4] = ((const t_op *)*src)[4];
		((t_op *)*d)[5] = ((const t_op *)*src)[5];
		((t_op *)*d)[6] = ((const t_op *)*src)[6];
		((t_op *)*d)[7] = ((const t_op *)*src)[7];
		*d += sizeof(t_op) * 8;
		*src += sizeof(t_op) * 8;
		*n -= sizeof(t_op) * 8;
	}
	while (*n >= sizeof(t_op))
	{
		*(t_op *)*d = *(const t_op *)*src;
		*d += sizeof(t_op);
		*src += sizeof(t_op);
		*n -= sizeof(t_op);
	}
}

/*
** Copy n bytes. Source and dest should NOT overlap.
**
** "The memcpy() function copies n bytes from memory area src to memory area
** dst.  If dst and src overlap, behavior is undefined.  Applications in which
** dst and src might overlap should use memmove(3) instead."
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*d;

	if (dst == src)
		return (dst);
	d = dst;
	ft_memcpy_opti(&d, &src, &n);
	while (n >= sizeof(int))
	{
		*(int *)d = *(const int *)src;
		d += sizeof(int);
		src += sizeof(int);
		n -= sizeof(int);
	}
	while (n--)
		*(char *)d++ = *(const char *)src++;
	return (dst);
}

/*
** // OPTI
** void	*bft_memcpy(void *dst, const void *src, size_t n)
** {
** 	void	*d;
**
** 	if (dst == src)
** 		return (dst);
** 	d = dst;
** 	ft_memcpy_opti(&d, &src, &n);
** 	while (n >= sizeof(t_op) * 8)
** 	{
** 		((t_op *)d)[0] = ((const t_op *)src)[0];
** 		((t_op *)d)[1] = ((const t_op *)src)[1];
** 		((t_op *)d)[2] = ((const t_op *)src)[2];
** 		((t_op *)d)[3] = ((const t_op *)src)[3];
** 		((t_op *)d)[4] = ((const t_op *)src)[4];
** 		((t_op *)d)[5] = ((const t_op *)src)[5];
** 		((t_op *)d)[6] = ((const t_op *)src)[6];
** 		((t_op *)d)[7] = ((const t_op *)src)[7];
** 		d += sizeof(t_op) * 8;
** 		src += sizeof(t_op) * 8;
** 		n -= sizeof(t_op) * 8;
** 	}
** 	while (n >= sizeof(t_op))
** 	{
** 		*(t_op *)d = *(const t_op *)src;
** 		d += sizeof(t_op);
** 		src += sizeof(t_op);
** 		n -= sizeof(t_op);
** 	}
** 	while (n >= sizeof(int))
** 	{
** 		*(int *)d = *(const int *)src;
** 		d += sizeof(int);
** 		src += sizeof(int);
** 		n -= sizeof(int);
** 	}
** 	while (n--)
** 		*(char *)d++ = *(const char *)src++;
** 	return (dst);
** }
*/

/*
** // NAIVE
** void	*xft_memcpy(void *dst, const void *src, size_t n)
** {
** 	char		*d;
** 	const char	*s;
**
** 	if (dst == src)
** 		return (dst);
** 	d = dst;
** 	s = src;
** 	while (n--)
** 		*d++ = *s++;
** 	return (dst);
** }
*/
