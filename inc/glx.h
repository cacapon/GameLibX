/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 12:37:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_H
# define GLX_H

// custom includes
# include "glx_color.h"
# include "glx_private.h"
# include "glx_struct.h"

// submodule
# include "libft.h"
# include "mlx.h"

// standard library
# include <X11/keysym.h>
# include <stdbool.h>

# define MAX_IMG 32
# define KEY_MAX 0xFFFF
# define UPDATE_COUNT 50000

typedef struct s_glx
{
	size_t	_update_count;
	size_t	frame_count;
	void	*mlx;
	void	*win;
	void	*imgs[MAX_IMG];
	int		imgc;
	bool	key_state[KEY_MAX];
	bool	key_just_state[KEY_MAX];
	int		(*btnp)(t_glx *, int);
	int		(*update)(t_glx *);
	int		(*draw)(t_glx *);
	void	(*load_img)(t_glx *, char *, int, int);
	void	(*put_img)(t_glx *, int, t_pos);
	void	(*put_str)(t_glx *, char *, t_pos, t_glx_color_index);
	void	(*run)(t_glx *, int (*)(t_glx *), int (*)(t_glx *));
	void	(*quit)(t_glx *, int);
	void	(*_error)(t_glx *, char *);
}			t_glx;

void		_glx_error(t_glx *self, char *mes);

t_glx		*glx_init(char *title, int win_w, int win_h);
void		glx_load_img(t_glx *self, char *path, int w, int h);
void		glx_put_img(t_glx *self, int img_i, t_pos pos);
void		glx_put_str(t_glx *self, char *str, t_pos pos,
				t_glx_color_index color);
void		glx_run(t_glx *self, int (*update)(t_glx *), int (*draw)(t_glx *));
void		glx_quit(t_glx *self, int sts_code);
bool		glx_btnp(t_glx *self, int keycode);
#endif