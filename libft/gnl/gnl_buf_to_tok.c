/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_buf_to_tok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:34:12 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/12 13:10:15 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_priv.h"

static int	gnl_has_newline(t_gnl *gnl, size_t *newline_pos)
{
	size_t	pos;
	char	*buf;

	pos = 0;
	buf = gnl->buf;
	while (pos < GNL_BUFFER_SIZE && buf[pos])
	{
		if (buf[pos] == '\n')
		{
			gnl->eol_reached = 1;
			*newline_pos = pos;
			return (1);
		}
		pos++;
	}
	return (0);
}

/*
** Careful: the buffer is not necessarily null-terminated
*/

void	gnl_buf_to_tok(t_gnl *gnl)
{
	size_t	newline_pos;
	char	*token_string;
	t_list	*token;

	if (gnl_has_newline(gnl, &newline_pos))
	{
		token_string = ft_substr(gnl->buf, 0, newline_pos);
		ft_strlcpy(gnl->buf, \
				gnl->buf + newline_pos + 1, GNL_BUFFER_SIZE - newline_pos);
	}
	else
	{
		token_string = ft_substr(gnl->buf, 0, GNL_BUFFER_SIZE);
		*gnl->buf = '\0';
	}
	token = ft_lstnew(token_string);
	if (token_string && token)
		ft_lstadd_back(&gnl->parts, token);
	else
		gnl->error_occured = 1;
}
