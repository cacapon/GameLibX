/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/11 12:52:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLX_H
# define GLX_H
# include "libft.h"
# include "mlx.h"

typedef struct s_glx
{
	void	*mlx;
	void	*win;
	void	(*load_img)(struct s_glx *, char *, int, int);
	void	(*run)(struct s_glx *);
	void	(*free)(struct s_glx *);
}			t_glx;

t_glx		*glx_init(char *title, int win_w, int win_h);
void		glx_load_img(t_glx *self, char *path, int w, int h);
void		glx_free(t_glx *self);
void		glx_run(t_glx *self);

#endif