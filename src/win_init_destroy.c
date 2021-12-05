/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:18:32 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/05 16:18:41 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	win_init(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx)
	{
		win->width = WIN_WIDTH;
		win->height = WIN_HEIGHT;
		win->win = mlx_new_window(win->mlx, win->width, win->height, \
				(char *)win->name);
	}
	if (!win->mlx || !win->win)
		win->error = error;
}

void	win_destroy(t_win *win)
{
	if (win->mlx && win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
		mlx_destroy_display(win->mlx);
	free(win->mlx);
}
