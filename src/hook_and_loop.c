/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:56:28 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 10:20:16 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Quit on Esc, lock/unlock julia on Space
*/

int	key_hook(int key, t_root *root)
{
	if (key == XK_Escape)
		mlx_loop_end(root->win.mlx);
	else if (key == XK_Return && root->fig.name == fig_julia)
	{
		root->fig.lock_julia = !root->fig.lock_julia;
		if (root->fig.lock_julia)
			ft_putendl("Julia's param locked.");
		else
			ft_putendl("Julia's param unlocked.");
	}
	return (0);
}

int	hook_click_close(t_win *win)
{
	mlx_loop_end(win->mlx);
	return (0);
}

int	hook_mouse(int button, int x, int y, t_root *root)
{
	if (button == ZOOM_IN || button == ZOOM_OUT)
		hook_zoom(button, x, y, root);
	else if (button == LEFT_CLICK)
		ft_putstr("Left click !\n");
	else if (button == RIGHT_CLICK)
		ft_putstr("Right click !\n");
	else if (button == MIDDLE_CLICK)
		ft_putstr("Middle click !\n");
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
	mlx_key_hook(win->ptr, key_hook, root);
	mlx_hook(win->ptr, DestroyNotify, ButtonReleaseMask, hook_click_close, win);
	mlx_mouse_hook(win->ptr, hook_mouse, root);
	mlx_loop(win->mlx);
}
