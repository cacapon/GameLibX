/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:46:33 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 12:41:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

t_glx	*glx_init(char *title, int win_w, int win_h)
{
	t_glx	*glx;

	glx = ft_calloc(1, sizeof(t_glx));
	glx->_update_count = 0;
	glx->frame_count = 0;
	glx->mlx = mlx_init();
	glx->win = mlx_new_window(glx->mlx, win_w, win_h, title);
	glx->imgc = 0;
	glx->run = glx_run;
	glx->load_img = glx_load_img;
	glx->put_img = glx_put_img;
	glx->put_str = glx_put_str;
	glx->quit = glx_quit;
	glx->btnp = glx_btnp;
	glx->_error = _glx_error;
	_glx_key_state_init(glx);
	_glx_key_just_state_init(glx);
	return (glx);
}

void	_glx_error(t_glx *self, char *mes)
{
	ft_putstr_fd(mes, STDERR_FILENO);
	self->quit(self, EXIT_FAILURE);
}

void	glx_put_str(t_glx *self, char *str, t_pos pos, t_glx_color_i color)
{
	mlx_string_put(self->mlx, self->win, pos.x, pos.y, glx_get_color(color),
		str);
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
	exit(sts_code);
}

int	loop_function(t_glx *self)
{
	self->_update_count = (self->_update_count + 1) % SIZE_MAX;
	if (self->_update_count % UPDATE_COUNT == 0)
	{
		self->frame_count = (self->frame_count + 1) % SIZE_MAX;
		self->update(self);
		self->draw(self);
		_glx_key_just_state_init(self);
	}
	return (0);
}

void	glx_run(t_glx *self, int (*update)(t_glx *), int (*draw)(t_glx *))
{
	mlx_do_key_autorepeatoff(self->mlx);
	self->update = update;
	self->draw = draw;
	mlx_loop_hook(self->mlx, loop_function, self);
	mlx_hook(self->win, 2, (1L << 0), _glx_key_pressed, self);
	mlx_hook(self->win, 3, (1L << 1), _glx_key_released, self);
	mlx_loop(self->mlx);
}
