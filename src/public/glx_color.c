/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:14:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/16 19:55:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glx_color.h"

uint32_t	glx_get_color(t_glx_color_index color)
{
	const uint32_t	glx_colors[16] = {
		GLX_COLOR_0, GLX_COLOR_1, GLX_COLOR_2, GLX_COLOR_3,
		GLX_COLOR_4, GLX_COLOR_5, GLX_COLOR_6, GLX_COLOR_7,
		GLX_COLOR_8, GLX_COLOR_9, GLX_COLOR_A, GLX_COLOR_B,
		GLX_COLOR_C, GLX_COLOR_D, GLX_COLOR_E, GLX_COLOR_F
	};

	if (color < 0 || color > 15)
		return (GLX_COLOR_0);
	
	return (glx_colors[color]);
}
