#include "glx.h"
#include <stdio.h>

typedef struct s_test_data
{
	t_pos	player_pos;
}	t_test_data;

static char *_player_pos_str(t_pos p_pos)
{
	char *x_str;
	char *y_str;
	char *result;
	char *tmp;

	x_str = ft_itoa(p_pos.x);
	y_str = ft_itoa(p_pos.y);
	result = ft_strjoin("pos:(", x_str);
	tmp = ft_strjoin(result, ",");
	free(result);
	result = tmp;
	tmp = ft_strjoin(result, y_str);
	free(result);
	result = tmp;
	tmp = ft_strjoin(result, ")");
	free(result);
	free(x_str);
	free(y_str);
	return (tmp);
}

static void data_free(t_test_data *data)
{
	free(data);
}

int	draw(void *param)
{
	t_glx	*glx;
	t_test_data	*data;
	char	flm_c[20];
	char	up_c[20];
	char	*pos_str;

	glx = get_glx();
	glx->cls();
	data = (t_test_data *)param;
	sprintf(flm_c, "%zu", glx->frame_count);
	sprintf(up_c, "%zu", glx->_->update_count);
	glx->text("hello glx!", (t_pos){16, 16}, glx->frame_count % 16);
	glx->text(flm_c, (t_pos){16, 32}, GLX_COLOR_WHITE);
	glx->text(up_c, (t_pos){16, 48}, GLX_COLOR_WHITE);
	pos_str = _player_pos_str(data->player_pos);
	glx->text(pos_str, (t_pos){16, 64}, GLX_COLOR_SKY_BLUE);
	if (glx->btn(XK_a))
		glx->put_img(0, (t_pos){0, 0});
	free(pos_str);
	return (0);
}

int	update(void *param)
{
	t_glx	*glx;
	t_test_data	*data;

	glx = get_glx();
	data = (t_test_data *)param;
	if (glx->btnp(XK_q))
	{
		data_free(data);
		glx->quit(EXIT_SUCCESS);
	}
	if (glx->btnp(XK_a))
		data->player_pos.x--;
	if (glx->btnp(XK_w))
		data->player_pos.y--;
	if (glx->btnp(XK_s))
		data->player_pos.y++;
	if (glx->btnp(XK_d))
		data->player_pos.x++;
	return (0);
}

int	main(void)
{
	t_glx *glx;
	t_test_data	*test;

	glx = glx_init("test", 500, 500, 500);
	test = ft_calloc(1, sizeof(t_test_data));
	*test = (t_test_data){.player_pos = (t_pos){0,0}};
	glx->load_img("./plane.xpm", 16, 16);
	glx->hook(update, draw);
	glx->run(test);
}