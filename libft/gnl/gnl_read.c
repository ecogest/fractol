/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:21:29 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/12 12:37:52 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_priv.h"
#include <unistd.h>

static	void	gnl_read_set_flags(t_gnl *gnl, int read_return)
{
	if (read_return == -1)
		gnl->error_occured = 1;
	if (read_return < GNL_BUFFER_SIZE)
	{
		gnl->eof_reached = 1;
		gnl->buf[read_return] = '\0';
	}
}

/*
** Read GNL_BUFFER_SIZE characters into gnl->buf.
**
** gnl->buf is not '\0' terminated unless less than GNL_BUFFER_SIZE characters
** have been read (when EOF is reached)
**
** If EOF is reached, set the flag accordingly.
*/

void	gnl_read(t_gnl *gnl)
{
	int	read_return;

	if (gnl->error_occured)
		return ;
	read_return = read(gnl->fd, gnl->buf, GNL_BUFFER_SIZE);
	gnl_read_set_flags(gnl, read_return);
}
