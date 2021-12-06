/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:48:59 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 10:30:44 by mjacq            ###   ########.fr       */
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

/* void	win_change_background(t_win *win) */
/* { */
/* } */

	/* img_draw(circle); */
	/* img_render(); */
int	main_fractol(int ac, const char *av[])
{
	t_root	root;

	root = (t_root){};
	parse_args(&root, ac, av);
	win_init(&root.win);
	win_hook_and_loop(&root.win);
	win_destroy(&root.win);
	return (0);
}
