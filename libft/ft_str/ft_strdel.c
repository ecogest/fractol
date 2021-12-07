/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:13:52 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/18 16:26:43 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Free and set a string pointer to NULL.
**
** (memdel wrapped for char **)
*/

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
