/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:56:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 14:37:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_PRIVATE_H
# define GLX_PRIVATE_H

# include "glx_struct.h"

int		_glx_exit_btn_pressed(t_glx *glx);
void	_glx_key_state_init(t_glx *self);
void	_glx_key_just_state_init(t_glx *self);
int		_glx_key_pressed(int keycode, t_glx *glx);
int		_glx_key_released(int keycode, t_glx *glx);

#endif