/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:12:26 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/12 12:37:52 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_priv.h"

static int	gnl_has_chars_in_buffer(t_gnl *gnl)
{
	return (*gnl->buf != '\0');
}

static int	gnl_has_to_stop(t_gnl *gnl)
{
	return (gnl->error_occured || gnl->eol_reached || gnl->eof_reached);
}

void	gnl_run(t_gnl *gnl)
{
	if (gnl->error_occured)
		return ;
	while (1)
	{
		if (gnl_has_chars_in_buffer(gnl))
			gnl_buf_to_tok(gnl);
		if (gnl_has_to_stop(gnl))
			break ;
		gnl_read(gnl);
	}
	gnl_join_tokens(gnl);
}
