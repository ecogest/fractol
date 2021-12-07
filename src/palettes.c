/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:12:41 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/07 14:17:38 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	palette_fill_colors(t_palette *palette, size_t size, int *colors)
{
	palette->size = 5;
	palette->colors = malloc(sizeof(*palette->colors) * palette->size);
	if (colors)
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
	size_t		i;
	t_palette	*palette;

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

void	palettes_init(t_palettes *palettes)
{
	t_palette	*palette;

	palettes->count = 2;
	palettes->choice = 0;
	palettes->array = malloc(sizeof(*palettes->array) * palettes->count);
	if (palettes->array)
	{
		ft_bzero(palettes->array, sizeof(*palettes->array) * palettes->count);
		palette = &palettes->array[0];
		palette_fill_colors(palette, 5, (int []) \
				{0x264653, 0x2a9d8f, 0xe9c46a, 0xf4a261, 0xe76f51});
		palette = &palettes->array[1];
		palette_fill_colors(palette, 5, (int []) \
				{0xCDB4DB, 0xFFC8DD, 0xFFAFCC, 0xBDE0FE, 0xA2D2FF});
		palettes_check_errors(palettes);
	}
	else
		palettes->error = error;
}
