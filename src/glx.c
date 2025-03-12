/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/12 13:31:03 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

void	glx_key_state_init(t_glx *self)
{
	int	i;

	i = 0;
	while (i < KEY_MAX)
	{
		self->prev_key_state[i] = false;
		self->current_key_state[i] = false;
		i++;
	}
}
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
	glx->btnp = glx_btnp;
	glx_key_state_init(glx);
	return (glx);
}

int _glx_update_key_state(t_glx *self)
{
	int i;

	ft_memcpy(self->prev_key_state, self->current_key_state, sizeof(self->current_key_state));
	i = 0;
	while (i < KEY_MAX)
		self->current_key_state[i++] = false;
	ft_printf("key_state updated. q_key p:%d c;%d\n", self->prev_key_state[XK_q], self->current_key_state[XK_q]);
	return (0);
}

int	_glx_key_pressed(int keycode, t_glx *glx)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (1);
	glx->current_key_state[keycode] = true;
	ft_printf("key%d pushed. p:%d c:%d\n", keycode, glx->prev_key_state[keycode], glx->current_key_state[keycode]);
	return (0);
}

int	_glx_key_released(int keycode, t_glx *glx)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (1);
	glx->current_key_state[keycode] = false;
	ft_printf("key%d released. p:%d, c:%d\n", keycode, glx->prev_key_state[keycode], glx->current_key_state[keycode]);
	return (0);
}

bool glx_btnp(t_glx *self, int keycode)
{
	bool prev;
	bool current;

	if (keycode < 0 || keycode > KEY_MAX)
		return (false);
	prev = self->prev_key_state[keycode];
	current = self->current_key_state[keycode];
	return (!prev && current);
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

int	loop_function(t_glx *self)
{
	self->update(self);
	_glx_update_key_state(self);
	self->draw(self);
	return (0);
}

void	glx_run(t_glx *self, int(*update)(t_glx*), int(*draw)(t_glx*))
{
	self->update = update;
	self->draw = draw;
	mlx_loop_hook(self->mlx, loop_function, self);
	mlx_hook(self->win, 2, 1L << 0, _glx_key_pressed, self);
	mlx_hook(self->win, 3, 1L << 1, _glx_key_released, self);
	mlx_loop(self->mlx);
}
