/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:46:07 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/12 11:54:22 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 10
# endif

typedef enum e_gnl_return {
	e_gnl_error = -1,
	e_gnl_eol = 1,
	e_gnl_eof = 0
}	t_gnl_return;

int	get_next_line(int fd, char **line);

#endif
