/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_prv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:37:06 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:33:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx.h"

/**
 * @brief 文字列mesを出力し、ゲームを終了します。
 * 
 * @param self 
 * @param mes 
 */
void	glx_error(t_glx *self, char *mes)
{
	ft_putstr_fd(mes, STDERR_FILENO);
	self->quit(EXIT_FAILURE);
}
