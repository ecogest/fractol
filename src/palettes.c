/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:12:41 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 15:56:21 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	palette_fill_colors(t_palt *palette, size_t size, int *colors)
{
	palette->size = size;
	palette->colors = malloc(sizeof(*palette->colors) * palette->size);
	if (palette->colors)
	{
		while (size--)
		{
			palette->colors[size] = colors[size];
		}
	}
}

static void	palettes_check_errors(t_palettes *palettes)
{
	size_t	i;

	if (palettes->error)
		return ;
	if (!palettes->array)
	{
		palettes->error = error;
		return ;
	}
	i = 0;
	while (i < palettes->count)
	{
		if (!palettes->array[i].colors)
		{
			palettes->error = error;
			return ;
		}
		i++;
	}
}

void	palettes_free(t_palettes *palettes)
{
	size_t	i;
	t_palt	*palette;

	if (palettes->array)
	{
		i = 0;
		while (i < palettes->count)
		{
			palette = &palettes->array[i];
			free(palette->colors);
			i++;
		}
		free(palettes->array);
	}
}

/*
** More palettes:
**		palette = &palettes->array[3];
**		palette_fill_colors(palette, 10, (int []) \
**				{0xF72585, 0xB5179E, 0x7209B7, 0x560BAD, 0x480CA8, \
**				0x3A0CA3, 0x3F37C9, 0x4361EE, 0x4895EF, 0x4CC9F0});
*/

void	palettes_init(t_palettes *palettes)
{
	t_palt	*palette;

	palettes->count = PALETTES_COUNT;
	palettes->choice = PALETTES_CHOICE_START;
	palettes->array = malloc(sizeof(*palettes->array) * palettes->count);
	if (palettes->array)
	{
		ft_bzero(palettes->array, sizeof(*palettes->array) * palettes->count);
		palette = &palettes->array[0];
		palette_fill_colors(palette, 5, (int []) \
				{0x264653, 0x2a9d8f, 0xe9c46a, 0xf4a261, 0xe76f51});
		palette = &palettes->array[1];
		palette_fill_colors(palette, 8, (int []) \
				{0x24283B, 0xF7768E, 0x9ECE6A, 0xE0AF68, 0x7AA2F7, \
				0xBB9AF7, 0x7DCFFF, 0x414868});
		palette = &palettes->array[2];
		palette_fill_colors(palette, 10, (int []) \
				{0x797D62, 0x9B9B7A, 0xBAA587, 0xD9AE94, 0xF1DCA7, \
				0xFFCB69, 0xE8AC65, 0xD08C60, 0xB58463, 0x997B66});
		palettes_check_errors(palettes);
	}
	else
		palettes->error = error;
}
