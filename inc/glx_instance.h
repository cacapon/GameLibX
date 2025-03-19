/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx_instance.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:49:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/18 13:55:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_INSTANCE_H
# define GLX_INSTANCE_H

# include "glx_struct.h"

t_glx	*get_glx(void);
void	set_glx(t_glx *glx);

#endif