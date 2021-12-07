/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fig_get_palette_and_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:07:22 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 15:07:31 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fig_get_nth_color(t_figure *fig, size_t nth_color)
{
	return (fig->palettes.array[fig->palettes.choice].colors[nth_color]);
}

t_palt	*fig_get_palette(t_figure *fig)
{
	return (&fig->palettes.array[fig->palettes.choice]);
}
