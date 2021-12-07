/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_priv.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:04:51 by mjacq             #+#    #+#             */
/*   Updated: 2021/05/12 12:37:50 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PRIV_H
# define GET_NEXT_LINE_PRIV_H

# include "get_next_line.h"
# include "libft.h"

typedef enum e_gnl_status {
	e_gnl_stat_continue,
	e_gnl_stat_stop
}	t_gnl_status;

typedef struct s_gnl {
	int		fd;
	char	**line_ptr;
	char	*buf;
	t_list	*parts;
	int		error_occured;
	int		eol_reached;
	int		eof_reached;
	int		newline_reached;
}	t_gnl;

void	gnl_run(t_gnl *gnl);
void	gnl_read(t_gnl *gnl);
void	gnl_buf_to_tok(t_gnl *gnl);
void	gnl_join_tokens(t_gnl *gnl);

#endif
