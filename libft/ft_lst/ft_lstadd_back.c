/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:28:35 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 10:12:57 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Append existing node to a list.
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*t;

	if (!(*alst))
		*alst = new;
	else
	{
		t = ft_lstlast(*alst);
		t->next = new;
	}
}
