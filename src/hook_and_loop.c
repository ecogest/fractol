/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:56:28 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 12:18:33 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hook_click_close(t_win *win)
{
	mlx_loop_end(win->mlx);
	return (0);
}

/*
** X11 treats scrolling as mouse clicking (button 4 and 5)
** mlx_mouse_hook(win->ptr, hook_mouse, win)
** <=> mlx_hook(win->ptr, Button4, ButtonPressMask, hook_mouse, win);
*/

void	f_hook_and_loop(t_root *root)
{
	t_win	*win;

	win = &root->win;
	if (win->error)
		return ;
	mlx_key_hook(win->ptr, hook_keyboard, root);
	mlx_hook(win->ptr, DestroyNotify, ButtonReleaseMask, hook_click_close, win);
	mlx_hook(win->ptr, MotionNotify, PointerMotionMask, hook_mouse_move, root);
	mlx_mouse_hook(win->ptr, hook_mouse_button, root);
	mlx_loop(win->mlx);
}
