/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_usage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:20:23 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 19:21:22 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	f_usage(void)
{
	ft_putendl_fd("\e[33mUsage: ./fractol <fractal_name>", 2);
	ft_putendl_fd("Supported fractals: \n - mandelbrot\n - julia\e[0m", 2);
}
