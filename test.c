#include "glx.h"

int	draw(t_glx *self)
{
    mlx_string_put(self->mlx, self->win, 16, 16, glx_get_color(self->frame_count % 16), "hello glx!");
	if (self->btnp(self, XK_a))
		self->put_img(self, 0, 0, 0);
	return (0);
}

int	update(t_glx *self)
{
	if (self->btnp(self, XK_q))
		self->quit(self, 0);
	return (0);
}

int	main(void)
{
	t_glx *glx;

	glx = glx_init("test", 500, 500);
	glx->load_img(glx, "./plane.xpm", 16, 16);
	glx->run(glx, update, draw);
}