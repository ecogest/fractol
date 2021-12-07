/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:19:24 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 19:47:48 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Split string at each char delimiter. Return NULL terminated array of strings.
*/

char	**ft_strsplit(char const *s, char c)
{
	return (ft_split(s, c));
}
