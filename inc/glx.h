/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/11 12:31:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_H
# define GLX_H
# include "libft.h"
# include "mlx.h"

typedef struct s_glx
{
	void	*mlx;
	void	(*free)(struct s_glx *self);
	void	(*run)(struct s_glx *self);
}			t_glx;

t_glx		*glx_init(void);
void		glx_free(t_glx *self);
void		glx_run(t_glx *self);

#endif