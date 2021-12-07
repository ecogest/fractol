/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:14:25 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/29 19:52:34 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

static void	ft_optimemset(void **b, t_op cccc, size_t *len)
{
	while (*len >= sizeof(t_op) * 8)
	{
		((t_op *)*b)[0] = cccc;
		((t_op *)*b)[1] = cccc;
		((t_op *)*b)[2] = cccc;
		((t_op *)*b)[3] = cccc;
		((t_op *)*b)[4] = cccc;
		((t_op *)*b)[5] = cccc;
		((t_op *)*b)[6] = cccc;
		((t_op *)*b)[7] = cccc;
		*b += sizeof(t_op) * 8;
		*len -= sizeof(t_op) * 8;
	}
	while (*len >= sizeof(t_op))
	{
		*(t_op *)*b = cccc;
		*b += sizeof(t_op);
		*len -= sizeof(t_op);
	}
}

/*
** Set n bytes to c (casted to unsigned char).
**
** The memset() function writes len bytes of value c (converted to an unsigned
** char) to the string b.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	t_op	cccc;
	void	*a;

	a = b;
	cccc = (unsigned char)c;
	cccc |= (cccc << CHAR_BIT);
	cccc |= (cccc << (CHAR_BIT * 2));
	if (sizeof(t_op) > 4)
		cccc |= (cccc << (CHAR_BIT * 2)) << (CHAR_BIT * 2);
	ft_optimemset(&b, cccc, &len);
	if (len >= sizeof(int))
	{
		*(int *)b = cccc;
		b += sizeof(int);
		len -= sizeof(int);
	}
	while (len--)
		*(char *)b++ = c;
	return (a);
}

/*
** ////////////// BEST
** void	*bft_memset(void *b, int c, size_t len)
** {
** 	t_op	cccc;
** 	void	*a;
**
** 	a = b;
** 	// creer un objet de la plus grande taille que peut traiter le proc
** 	cccc = (unsigned char)c; // unsigned important
** 	cccc |= (cccc << CHAR_BIT);
** 	cccc |= (cccc << (CHAR_BIT * 2));
** 	if (sizeof(t_op) > 4) // 2 steps avoid warning
** 		cccc |= (cccc << (CHAR_BIT * 2)) << (CHAR_BIT * 2);
**
** 	while (len >= sizeof(t_op) * 8) // loop unrolling
** 	{
** 		((t_op *)b)[0] = cccc;
** 		((t_op *)b)[1] = cccc;
** 		((t_op *)b)[2] = cccc;
** 		((t_op *)b)[3] = cccc;
** 		((t_op *)b)[4] = cccc;
** 		((t_op *)b)[5] = cccc;
** 		((t_op *)b)[6] = cccc;
** 		((t_op *)b)[7] = cccc;
** 		b += sizeof(t_op) * 8;
** 		len -= sizeof(t_op) * 8;
** 	}
** 	while (len >= sizeof(t_op))
** 	{
** 		*(t_op *)b = cccc;
** 		b += sizeof(t_op);
** 		len -= sizeof(t_op);
** 	}
** 	if (len >= sizeof(int))
** 	{
** 		*(int *)b = cccc;
** 		b += sizeof(int);
** 		len -= sizeof(int);
** 	}
** 	while (len--)
** 		*(char *)b++ = c; //unsigned char casting here is useless
**
** 	return (a);
** }
*/

/*
** ///////////// NAIVE
** void	*nft_memset(void *b, int c, size_t len)
** {
** 	while (len--)
** 		((char *)b)[len] = c;
** 	return (b);
** }
*/
