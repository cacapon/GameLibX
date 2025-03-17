/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:49:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/17 13:56:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_STR_H
# define GLX_STR_H

# include "glx.h"
# include "glx_define.h"
# include "glx_struct.h"

void	glx_put_str(t_glx *self, char *str, t_pos pos, t_glx_color_i color);

#endif