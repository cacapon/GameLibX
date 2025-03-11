/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/11 13:12:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

t_glx	*glx_init(char *title, int win_w, int win_h)
{
	t_glx	*glx;

	glx = ft_calloc(1, sizeof(t_glx));
	glx->mlx = mlx_init();
	glx->win = mlx_new_window(glx->mlx, win_w, win_h, title);
	glx->imgc = 0;
	glx->run = glx_run;
	glx->load_img = glx_load_img;
	glx->put_img = glx_put_img;
	glx->free = glx_free;
	return (glx);
}

void	glx_load_img(t_glx *self, char *path, int w, int h)
{
	self->imgs[self->imgc++] = mlx_xpm_file_to_image(self->mlx, path, &w, &h);
}

void	glx_put_img(t_glx *self, int img_i, int w, int h)
{
	mlx_put_image_to_window(self->mlx, self->win, self->imgs[img_i], w, h);
}

void	glx_free(t_glx *self)
{
	free(self->mlx);
	free(self);
}

void	glx_run(t_glx *self)
{
	mlx_loop(self->mlx);
}
