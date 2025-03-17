/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_key_input_pri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:52:07 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 14:08:08 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

/**
 * @brief key_stateをすべてfalseに設定します。
 * 
 * @param self 
 */
void	_glx_key_state_init(t_glx *self)
{
	int	i;

	i = 0;
	while (i < KEY_MAX)
		self->key_state[i++] = false;
}

/**
 * @brief key_just_stateをすべてfalseに設定します。
 * 
 * @param self 
 */
void	_glx_key_just_state_init(t_glx *self)
{
	int	i;

	i = 0;
	while (i < KEY_MAX)
		self->key_just_state[i++] = false;
}

/**
 * @brief 押下時に指定されたキーコードの状態をtrueにします。
 * 
 * @param keycode 
 * @param glx 
 * @return int
 * @note この関数は内部でキーハンドラとして登録済みです。 
 */
int	_glx_key_pressed(int keycode, t_glx *glx)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (1);
	glx->key_state[keycode] = true;
	glx->key_just_state[keycode] = true;
	return (0);
}

/**
 * @brief ボタンを離した際にキーコードの状態をfalseにします。
 * 
 * @param keycode 
 * @param glx 
 * @return int
 * @note この関数は内部でキーハンドラとして登録済みです。 
 */
int	_glx_key_released(int keycode, t_glx *glx)
{
	if (keycode < 0 || keycode > KEY_MAX)
		return (1);
	glx->key_state[keycode] = false;
	return (0);
}
