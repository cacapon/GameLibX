/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:49:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:54:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_IMG_H
# define GLX_IMG_H
# include "glx_struct.h"
# include "glx.h"

void	glx_load_img(char *path, int w, int h);
void	glx_put_img(int img_i, t_pos pos);

#endif