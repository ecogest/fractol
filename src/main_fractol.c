/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/05 15:35:20 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//TODO: error checking
void	parse_args(t_root *root, int ac, const char *av[])
{
	if (ac == 2)
		root->win.name = av[1];
	else
		root->win.name = "Fractol";
}

void	win_init(t_win *win, void **mlx)
{
	*mlx = mlx_init();
	if (*mlx)
	{
		win->width = WIN_WIDTH;
		win->height = WIN_HEIGHT;
		win->win = mlx_new_window(*mlx, win->width, win->height, \
				(char *)win->name);
	}
	if (!mlx || !win->win)
		win->error = error;
}

	/* img_draw(circle); */
	/* img_render(); */
int	main_fractol(int ac, const char *av[])
{
	t_root	root;

	root = (t_root){};
	parse_args(&root, ac, av);
	win_init(&root.win, &root.mlx);
	mlx_loop(root.mlx);
	return (0);
}
