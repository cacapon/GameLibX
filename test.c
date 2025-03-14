#include "glx.h"

int	draw(t_glx *self)
{
	//mlx_clear_window(self->mlx, self->win);
	self->put_img(self, 0, 16, 16);
	return (0);
}

int	update(t_glx *self)
{
	if (self->btnp(self, XK_q))
		exit(0);
	if (self->btnp(self, XK_a))
		ft_printf("put a\n");
	return (0);
}

int	main(void)
{
	t_glx *glx;

	glx = glx_init("test", 500, 500);
	glx->load_img(glx, "./plane.xpm", 16, 16);
	ft_printf("glx:img[%d]=%p\n",glx->imgc-1, glx->imgs[glx->imgc-1]);
	glx->run(glx, draw, update);
	return (0);
}