#include "fractol.h"

void	ft_key_suite2(int key, t_s *s)
{
	if (key == 69)
	{
		if (s->itermax < 1000)
			s->itermax += 24;
	}
	if (key == 78)
	{
		if (s->itermax > 50)
			s->itermax -= 24;
	}
	if (key == 25)
	{
		s->fract = 2;
		s->init = 0;
		s->itermax = 24;
	}
	if (key == 37)
	{
		s->move = s->move == 1 ? 0 : 1;
		s->itermax = s->move == 1 ? 75 : s->itermax;
	}
}

void	ft_key_suite(int key, t_s *s)
{
	if (key == 3)
		s->afflink = s->afflink == 0 ? 1 : 0;
	if (key == 9)
		s->scope = s->scope == 0 ? 1 : 0;
	if (key == 46)
		s->affmenu = s->affmenu == 0 ? 1 : 0;
	if (key == 83)
		s->color = 0;
	if (key == 84)
		s->color = 1;
	if (key == 85)
		s->color = 2;
	if (key == 86)
		s->color = 3;
	if (key == 87)
		s->color = 4;
	if (key == 88)
		s->color = 5;
	if (key == 89)
		s->color = 6;
	if (key == 91)
		s->color = 7;
	if (key == 92)
		s->color = 8;
}

int		key_hook(int key, void *param)
{
	t_s *s;

	s = (t_s *)param;
	if (key == 53)
		exit(0);
	if (key == 67)
		s->itermax = s->itermax == 50 ? 100 : 50;
	if (key == 123 || key == 124)
	{
		s->left += key == 124 ? 30 / s->zoomx : -(30 / s->zoomx);
		s->right += key == 124 ? 30 / s->zoomx : -(30 / s->zoomx);
	}
	if (key == 125 || key == 126)
	{
		s->high += key == 125 ? 30 / s->zoomy : -(30 / s->zoomy);
		s->low += key == 125 ? 30 / s->zoomy : -(30 / s->zoomy);
	}
	if (key == 3 || key == 9 || key == 46 || (key > 82 && key < 93))
		ft_key_suite(key, s);
	if (key == 69 || key == 78 || key == 25 || key == 37)
		ft_key_suite2(key, s);
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s, 0);
	return (0);
}
