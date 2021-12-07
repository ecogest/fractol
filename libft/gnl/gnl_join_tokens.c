/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_join_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:23:03 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/12 13:16:01 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_priv.h"

/*
** First and last token can be of variable size,
** others should be BUFFER_SIZE long.
*/

static size_t	gnl_strlen_tokens(t_gnl *gnl)
{
	size_t	token_count;
	size_t	length_sum;

	token_count = ft_lstsize(gnl->parts);
	if (!token_count)
		return (0);
	length_sum = ft_strlen(gnl->parts->content);
	if (token_count >= 2)
		length_sum += ft_strlen(ft_lstlast(gnl->parts)->content);
	if (token_count > 2)
		length_sum += GNL_BUFFER_SIZE * (token_count - 2);
	return (length_sum);
}

static	int	gnl_malloc_final_line(t_gnl *gnl)
{
	size_t	tokens_length_sum;

	tokens_length_sum = gnl_strlen_tokens(gnl);
	*gnl->line_ptr = malloc(tokens_length_sum + 1);
	if (!*gnl->line_ptr)
	{
		gnl->error_occured = 1;
		return (0);
	}
	return (1);
}

static void	gnl_copy_token_contents(char *final_line, t_list *tokens)
{
	while (tokens)
	{
		ft_strcpy(final_line, tokens->content);
		final_line += ft_strlen(tokens->content);
		tokens = tokens->next;
	}
}

/*
** Compose the final line by joining all the tokens
**
** if no token has been created, return an empty string "\0"
*/

void	gnl_join_tokens(t_gnl *gnl)
{
	if (gnl->error_occured || !gnl_malloc_final_line(gnl))
		return ;
	**gnl->line_ptr = '\0';
	gnl_copy_token_contents(*gnl->line_ptr, gnl->parts);
}
