/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 14:29:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_H
# define GLX_H

// custom includes
# include "glx_color.h"
# include "glx_define.h"
# include "glx_img.h"
# include "glx_private.h"
# include "glx_str.h"
# include "glx_struct.h"
# include "glx_win.h"

// submodule
# include "libft.h"
# include "mlx.h"

// standard library
# include <X11/keysym.h>

// private
void	glx_error(t_glx *self, char *mes);

// public

t_glx	*glx_init(char *title, int win_w, int win_h, size_t update_lim);
void	glx_run(t_glx *self, int (*update)(t_glx *), int (*draw)(t_glx *));
void	glx_quit(t_glx *self, int sts_code);
int		glx_btnp(t_glx *self, int keycode);
#endif