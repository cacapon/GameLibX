/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:47:22 by ttsubo            #+#    #+#             */
/*   Updated: 2025/03/09 14:53:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define MAX_IMG_COUNT 64

# include "libft.h"
# include "mlx.h"

typedef struct s_glx	t_glx;
typedef struct s_img	t_img;


typedef struct s_glx
{
	void				*mlx;
	void				*win;
	t_img				*img;
	void				(*run)(t_glx *self);
	void				(*free)(t_glx *self);
}						t_glx;

typedef struct s_img
{
	void	*img[64];
	int		w;
	int		h;
	int		count;
}	t_img;


t_glx					*glx_init(char *title, int win_x, int win_y);
void					glx_run(t_glx *self);
void					glx_free(t_glx *self);

#endif