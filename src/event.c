#include "fractol.h"

void	ft_key1(int key, t_s *s, int x, int y)
{
	if (key == 1 && (x >= 0 && x <= 160) &&
	(y >= 0 && y <= 160) && s->afflink == 0)
	{
		s->fract = 0;
		s->init = 0;
	}
	if (key == 1 && (x >= XWIN - 160 && x <= XWIN) &&
	(y >= 0 && y <= 400) && s->afflink == 0)
	{
		s->fract = 1;
		s->julia = 1;
		s->movex = 0.4;
		s->movey = 0.2;
		s->init = 0;
	}
	if (key == 1 && (x >= 0 && x <= 160) &&
	(y >= YWIN - 160 && y <= YWIN) && s->afflink == 0)
	{
		s->fract = 1;
		s->julia = 2;
		s->movex = 0.26;
		s->movey = 0;
		s->init = 0;
	}
}

int		mouse_hook(int key, int x, int y, void *param)
{
	t_s *s;

	s = (t_s *)param;
	(void)y;
	ft_key1(key, s, x, y);
	if (key == 1 && (x >= XWIN - 160 && x <= XWIN) &&
	(y >= YWIN - 160 && y <= YWIN) && s->afflink == 0)
	{
		s->fract = 3;
		s->init = 0;
		s->movex = 0.14;
		s->movey = 0;
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
