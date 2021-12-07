/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:56:00 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/12 13:18:08 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_priv.h"
#include "libft.h"

static void	init_gnl(t_gnl *gnl, int fd, char **line, char *buffer)
{
	ft_bzero(gnl, sizeof(*gnl));
	gnl->fd = fd;
	gnl->line_ptr = line;
	gnl->buf = buffer;
}

static void	gnl_free_temp_data(t_gnl *gnl)
{
	ft_lstclear(&gnl->parts, free);
}

static int	gnl_return(t_gnl *gnl)
{
	if (gnl->error_occured)
		return (e_gnl_error);
	else if (gnl->eol_reached)
		return (e_gnl_eol);
	else
		return (e_gnl_eof);
}

/*
** Return: 1 for a '\n' terminated line, 0 for the last line, -1 if err.
**
** If error, *line is set to NULL.
**
** Ex:
** - 'hello\nworld' -> [ 1: 'hello' ] , [ 0: 'world' ]
** - 'hello\n'      -> [ 1: 'hello' ] , [ 0: '' ]
** - 'hello'        -> [ 0: 'hello' ]
*/

int	get_next_line(int fd, char **line)
{
	static char	buf[GNL_BUFFER_SIZE];
	t_gnl		gnl;

	if (fd < 0 || !line)
		return (e_gnl_error);
	*line = NULL;
	init_gnl(&gnl, fd, line, buf);
	gnl_run(&gnl);
	gnl_free_temp_data(&gnl);
	return (gnl_return(&gnl));
}
