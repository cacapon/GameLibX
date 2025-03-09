/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/09 14:56:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_glx	*glx_init(char *title, int win_x, int win_y)
{
	t_glx	*glx;

	glx = ft_calloc(1, sizeof(t_glx));
	glx->mlx = mlx_init();
	glx->win = mlx_new_window(glx->mlx, win_x, win_y, title);
	glx->free = glx_free;
	glx->run = glx_run;
	return (glx);
}

void	glx_load_img(t_glx *self, char *img_path)
{
	int		*w;
	int		*h;
	void	*(*load)(void *, char *, int *, int *);

	load = mlx_xpm_file_to_image;
	if (self->img->count >= MAX_IMG_COUNT)
		return ;
	w = &(self->img->w);
	h = &(self->img->h);
	self->img->img[self->img->count++] = load(self->mlx, img_path, w, h);
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
