/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/14 17:53:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

void	glx_key_state_init(t_glx *self)
{
	int	i;

	i = 0;
	while (i < KEY_MAX)
	{
		self->key_state[i] = false;
		self->key_just_state[i] = false;
		i++;
	}
}
t_glx	*glx_init(char *title, int win_w, int win_h)
{
	t_glx	*glx;

	glx = ft_calloc(1, sizeof(t_glx));
	glx->frame_count = 0;
	glx->mlx = mlx_init();
	glx->win = mlx_new_window(glx->mlx, win_w, win_h, title);
	glx->imgc = 0;
	glx->run = glx_run;
	glx->load_img = glx_load_img;
	glx->put_img = glx_put_img;
	glx->quit = glx_quit;
	glx->btnp = glx_btnp;
	glx_key_state_init(glx);
	return (glx);
}

int	_glx_key_pressed(int keycode, t_glx *glx)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (1);
	glx->key_state[keycode] = true;
	glx->key_just_state[keycode] = true;
	ft_printf("key_pressed,%d\n", keycode);
	return (0);
}

int	_glx_key_released(int keycode, t_glx *glx)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (1);
	glx->key_state[keycode] = false;
	glx->key_just_state[keycode] = false;
	ft_printf("key_released,%d\n", keycode);
	return (0);
}

bool glx_btnp(t_glx *self, int keycode)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (false);
	if (!self->key_just_state[keycode])
		return (false);
	self->key_just_state[keycode] = false;
	return (true);
}

void	glx_load_img(t_glx *self, char *path, int w, int h)
{
	self->imgs[self->imgc++] = mlx_xpm_file_to_image(self->mlx, path, &w, &h);
}

void	glx_put_img(t_glx *self, int img_i, int w, int h)
{
	mlx_put_image_to_window(self->mlx, self->win, self->imgs[img_i], w, h);
}

void	glx_quit(t_glx *self, int sts_code)
{
	mlx_do_key_autorepeaton(self->mlx);
	while (self->imgc)
	{
		self->imgc--;
		mlx_destroy_image(self->mlx, self->imgs[self->imgc]);
	}
	mlx_destroy_window(self->mlx, self->win);
	mlx_destroy_display(self->mlx);
	free(self);
	exit (sts_code);
}

int	loop_function(t_glx *self)
{
	self->frame_count = (self->frame_count + 1) % SIZE_MAX;
	if (self->frame_count % UPDATE_COUNT == 0)
	{
		self->update(self);
		self->draw(self);
	}
	return (0);
}

void	glx_run(t_glx *self, int(*update)(t_glx*), int(*draw)(t_glx*))
{
	mlx_do_key_autorepeatoff(self->mlx);
	self->update = update;
	self->draw = draw;
	mlx_loop_hook(self->mlx, loop_function, self);
	mlx_hook(self->win, 2, (1L << 0), _glx_key_pressed, self);
	mlx_hook(self->win, 3, (1L << 1), _glx_key_released, self);
	mlx_loop(self->mlx);
}
