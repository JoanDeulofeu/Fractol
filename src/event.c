#include "fractol.h"

int		key_hook(int key, void *param)
{
	t_s *s;

	// s->left = -2.1;
	// s->right = 0.6;
	// s->high = -1.2;
	// s->low = 1.2;

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
	if (key == 69)
	{
		if (s->itermax < 1000)
			s->itermax += 25;
	}
	if (key == 78)
	{
		if (s->itermax > 50)
			s->itermax -= 25;
	}
	if (key == 18)
	{
		s->fract = 0;
		s->init = 0;
	}
	if (key == 19)
	{
		s->fract = 1;
		s->init = 0;
	}
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s);
	return (0);
}

int		mouse_hook(int key, int x, int y, void *param)
{
	t_s *s;

	s = (t_s *)param;
	(void)y;
	if (key == 1)
		s->move = s->move == 1 ? 0 : 1;
	if (key == 2)
		exit(0);
	if (key == 4)
		ft_zoom(s, x, y, 1);
	if (key == 5)
		ft_zoom(s, x, y, 0);
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_s *s;

	s = (t_s *)param;
	x = y; // MERDE
	// if (s->move == 1)
	// {
	// 	if (s->savex < x)
	// 		s->zr += 0.02;
	// 	if (s->savex < y)
	// 		s->zi += 0.02;
	// 	if (s->savex > x)
	// 		s->zr -= 0.02;
	// 	if (s->savex > y)
	// 		s->zi -= 0.02;
	// 	s->savex = x;
	// 	s->savey = y;
	// }
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s);
	return (0);
}

int		ft_expose(void *param)
{
	t_s *s;

	s = (t_s *)param;
	exit(0);
}
