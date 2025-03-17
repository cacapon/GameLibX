/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:48:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 11:50:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "glx_img.h"

void	glx_load_img(t_glx *self, char *path, int w, int h)
{
	self->imgs[self->imgc] = mlx_xpm_file_to_image(self->mlx, path, &w, &h);
	if (!self->imgs[self->imgc])
		self->_error(self, "glx_load_img: Failed to load image.");
	self->imgc++;
}

void	glx_put_img(t_glx *self, int img_i, t_pos pos)
{
	mlx_put_image_to_window(self->mlx, self->win, self->imgs[img_i], pos.x, pos.y);
}