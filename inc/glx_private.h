/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:56:38 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/19 12:08:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_PRIVATE_H
# define GLX_PRIVATE_H

# include "glx_struct.h"

void	_glx_error(char *mes);
void	_glx_key_state_init(t_glx *self);
void	_glx_key_just_state_init(t_glx *self);
int		_glx_key_pressed(int keycode, t_glx *glx);
int		_glx_key_released(int keycode, t_glx *glx);
int		_glx_win_exit(t_glx *glx);

#endif