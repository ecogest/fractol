/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:50:47 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/06 20:28:30 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

/*
** Put a wide char (wchar_t) to stdout.
*/

void	ft_putwchar(wchar_t wc)
{
	ft_putwchar_fd(wc, 1);
}
