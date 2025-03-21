/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:56:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/21 02:11:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_PRIVATE_H
# define GLX_PRIVATE_H

# include "glx_struct.h"

t_glx_prv	*_glx_init_private(size_t update_lim);
void		_glx_error(char *mes);
void		_glx_key_state_init(t_glx *self);
void		_glx_key_just_state_init(t_glx *self);
int			_glx_key_pressed(int keycode, t_glx *glx);
int			_glx_key_released(int keycode, t_glx *glx);
int			_glx_win_exit(t_glx *glx);

#endif