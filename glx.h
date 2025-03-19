/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/19 11:55:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_H
# define GLX_H

// custom includes
# include "inc/glx_color.h"
# include "inc/glx_define.h"
# include "inc/glx_img.h"
# include "inc/glx_private.h"
# include "inc/glx_text.h"
# include "inc/glx_struct.h"
# include "inc/glx_win.h"
# include "inc/glx_instance.h"

// submodule
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"

// standard library
# include <X11/keysym.h>

// public methods.

t_glx	*glx_init(char *title, int win_w, int win_h, size_t update_lim);
t_glx   *get_glx(void);
void	glx_hook(int (*update)(void *), int (*draw)(void *), int (*clean)(void *));
void	glx_run(void *);
void	glx_quit(int sts_code);
int		glx_btnp(int keycode);
int		glx_btn(int keycode);
#endif