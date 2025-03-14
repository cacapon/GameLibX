/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/14 17:54:32 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_H
# define GLX_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <stdbool.h>

# define MAX_IMG 32
# define KEY_MAX XK_Delete
# define UPDATE_COUNT 500

typedef struct s_glx	t_glx;

typedef struct s_glx
{
	size_t				frame_count;
	void				*mlx;
	void				*win;
	void				*imgs[MAX_IMG];
	int					imgc;
	bool				key_state[KEY_MAX];
	bool				key_just_state[KEY_MAX];
	int					(*update)(t_glx *);
	int					(*draw)(t_glx *);
	void				(*load_img)(t_glx *, char *, int, int);
	void				(*put_img)(t_glx *, int, int, int);
	void				(*run)(t_glx *, int (*)(t_glx *), int (*)(t_glx *));
	void				(*quit)(t_glx *, int);
	bool				(*btnp)(t_glx *, int);
}						t_glx;

t_glx					*glx_init(char *title, int win_w, int win_h);
void					glx_load_img(t_glx *self, char *path, int w, int h);
void					glx_put_img(t_glx *self, int img_i, int w, int h);
void					glx_run(t_glx *, int (*)(t_glx *), int (*)(t_glx *));
void					glx_quit(t_glx *self, int sts_code);
bool					glx_btnp(t_glx *self, int keycode);
#endif