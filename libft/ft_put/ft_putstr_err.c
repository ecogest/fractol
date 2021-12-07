/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:04:54 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/19 11:05:51 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** Put a string to stderr.
*/

void	ft_putstr_err(const char *s)
{
	if (!s)
		return ;
	write(2, s, ft_strlen(s));
}
