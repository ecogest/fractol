/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_px_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacq <mjacq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:08:06 by mjacq             #+#    #+#             */
/*   Updated: 2021/12/06 11:08:17 by mjacq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_px_put(t_img *img, t_pixel *px)
{
	char	*px_addr;

	px_addr = img->buf + px->y * img->size_line + px->x * img->bpp / CHAR_BIT;
	*(int *)px_addr = px->color;
}
