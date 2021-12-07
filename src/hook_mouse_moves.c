/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:09:30 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 11:13:27 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hook_julia_mouse_move(int x, int y, t_figure *fig, t_win *win)
{
	fig->julia_lock = 1;
	if (x != win->mouse.last_x)
	{
		fig->julia_c.x += (x - win->mouse.last_x) / (float)WIN_WIDTH;
		win->mouse.last_x = x;
	}
	if (y != win->mouse.last_y)
	{
		fig->julia_c.y -= (y - win->mouse.last_y) / (float)WIN_WIDTH;
		win->mouse.last_y = y;
	}
	win_put_figure(win, fig);
	printf("\e[32mc.x = %f \t c.y = %f\e[0m\n", \
			fig->julia_c.x, fig->julia_c.y);
	fig->julia_lock = 0;
	return (0);
}

/*
** TODO: divide delta cx and cy by scale
*/

int	hook_mouse_move(int x, int y, t_root *root)
{
	static int		start;
	t_figure *const	fig = &root->fig;

	if (!start)
	{
		root->win.mouse.last_x = x;
		root->win.mouse.last_y = y;
		start = 1;
	}
	else if (fig->name == fig_julia && !fig->julia_lock && \
			(x != root->win.mouse.last_x || y != root->win.mouse.last_y))
		hook_julia_mouse_move(x, y, fig, &root->win);
	return (0);
}
