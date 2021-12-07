/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:19:36 by mjacq             #+#    #+#             */
/*   Updated: 2021/04/07 10:20:46 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Destroy all nodes and content of a list.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	if (!lst)
		return ;
	while (*lst)
	{
		if (del)
			del((*lst)->content);
		t = (*lst)->next;
		free(*lst);
		*lst = t;
	}
}
