/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:15:20 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_H
# define GLX_H

// custom includes
# include "inc/glx_color.h"
# include "inc/glx_define.h"
# include "inc/glx_img.h"
# include "inc/glx_private.h"
# include "inc/glx_str.h"
# include "inc/glx_struct.h"
# include "inc/glx_win.h"

// submodule
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"

// standard library
# include <X11/keysym.h>

// private
void	glx_error(t_glx *self, char *mes);

// public

t_glx	*glx_init(char *title, int win_w, int win_h, size_t update_lim);
t_glx   *get_glx(void);
void	glx_run(int (*update)(void *), int (*draw)(void *));
void	glx_quit(t_glx *self, int sts_code);
int		glx_btnp(t_glx *self, int keycode);
#endif