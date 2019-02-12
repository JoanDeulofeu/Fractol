#include "fractol.h"

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
	if (key == 25) // fougere
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
	if (key == 117)
	{
		printf("s->left =%f\n", s->left);
		printf("s->right =%f\n", s->right);
		printf("s->high =%f\n", s->high);
		printf("s->low =%f\n", s->low);
		printf("s->zoomx =%f\n", s->zoomx);
		printf("s->zoomy =%f\n", s->zoomy);
		printf("s->movex =%f\n", s->movex);
		printf("s->movey =%f\n", s->movey);
		printf("s->itermax =%d\n", s->itermax);
		return (0);
	}
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s, 0);
	return (0);
}

int		mouse_hook(int key, int x, int y, void *param)
{
	t_s *s;

	s = (t_s *)param;
	(void)y;
	if (key == 1 && (x >= 0 && x <= 160) && (y >= 0 && y <= 160) && s->afflink == 0) //mandelbrot
	{
		s->fract = 0;
		s->init = 0;
		s->itermax = 250;
	}
	if (key == 1 && (x >= XWIN - 160 && x <= XWIN) && (y >= 0 && y <= 400) && s->afflink == 0) // julia1
	{
		s->fract = 1;
		s->julia = 1;
		s->movex = 0.4;
		s->movey = 0.2;
		s->init = 0;
		s->itermax = 250;
	}
	if (key == 1 && (x >= 0 && x <= 160) && (y >= YWIN - 160 && y <= YWIN) && s->afflink == 0) // julia2
	{
		s->fract = 1;
		s->julia = 2;
		s->movex = 0.26;
		s->movey = 0;
		s->init = 0;
		s->itermax = 250;
	}
	if (key == 1 && (x >= XWIN - 160 && x <= XWIN) && (y >= YWIN - 160 && y <= YWIN) && s->afflink == 0)
	{
		s->fract = 3;
		s->init = 0;
		s->movex = 0.14;
		s->movey = 0;
		s->itermax = 200;
	}
	if (key == 2)
		exit(0);
	if (key == 4)
		ft_zoom(s, x, y, 1);
	if (key == 5)
		ft_zoom(s, x, y, 0);
	mlx_destroy_image(s->m_ptr, s->img);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s, 0);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_s *s;

	s = (t_s *)param;
	if (s->move == 1)
	{
		if (s->fract == 1 || s->fract == 3)
		{
			if (s->savex < x)
				s->movex += 0.02;
			if (s->savey < y)
				s->movey += 0.02;
			if (s->savex > x)
				s->movex -= 0.02;
			if (s->savey > y)
				s->movey -= 0.02;
			s->savex = x;
			s->savey = y;
		}
		mlx_destroy_image(s->m_ptr, s->img);
		ft_init_image(s, XWIN, YWIN);
		ft_fractales(s, 0);
	}
	return (0);
}

int		ft_expose(void *param)
{
	t_s *s;

	s = (t_s *)param;
	exit(0);
}
