/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:28:27 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 18:39:35 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Given z0 (complex number), compute how many z_{n+1} = (z_n)**2 + c
** are possible before the sequel diverges for sure (when |z| >= 2)
*/

int	iter_julia(t_coordinates *c, t_coordinates *zn, int max_iter)
{
	t_coordinates	zsquare;
	t_coordinates	znext;
	float			square_modulus_next;

	if (!max_iter)
		return (0);
	zsquare.x = zn->x * zn->x - zn->y * zn->y;
	zsquare.y = 2 * zn->x * zn->y;
	znext.x = zsquare.x + c->x;
	znext.y = zsquare.y + c->y;
	square_modulus_next = znext.x * znext.x + znext.y * znext.y;
	if (square_modulus_next >= 4)
		return (0);
	else
		return (1 + iter_julia(c, &znext, max_iter - 1));
}

/*
** main bud opti : (x+1)**2 + y**2 < 1/16
*/

int	iter_mandelbrot(t_coordinates *c, int max_iter)
{
	t_coordinates	z0;

	if (powf(c->x + 1, 2) + powf(c->y, 2) < 1.0 / 16)
		return (max_iter);
	z0 = (t_coordinates){};
	return (iter_julia(c, &z0, max_iter));
}
