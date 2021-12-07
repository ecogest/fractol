/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:05:41 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 16:49:06 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Takes a pointer address (VOID**)ap: Free *ap and reset *ap to NULL.
**
** Prototype is (void *) only for because C-standard would ask casting otherwise
**
** Very different from the memdel found in <publib.h>
*/

void	ft_memdel(void *ap)
{
	void	**real_ap;

	if (!ap)
		return ;
	real_ap = ap;
	free(*real_ap);
	*real_ap = NULL;
}

/*
** void	ft_memdel(void *ap)
** {
** 	if (!ap)
** 		return ;
** 	free(*ap);
** 	*ap = NULL;
** }
*/
