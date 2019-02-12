#include "fractol.h"

void	ft_lightup_fougere(t_s *s, t_thr *thr)
{
	int new_x;

	if (thr->x <= s->img_x && thr->y <= s->img_y && thr->x >= 0 && thr->y >= 0)
	{
		new_x = thr->x * 4 + ((s->img_x * 4) * thr->y);
		s->s_img[new_x + 0] = 255;
		s->s_img[new_x + 1] = 255;
		s->s_img[new_x + 2] = 255;
		s->s_img[new_x + 3] = 0;
	}
}

void	ft_fougere2(t_thr *thr, int r, int zr, int zi)
{
	r = rand() % 100;
	if (r < 2)
	{
		zr = 50;
		zi = 0.27 * zi;
	}
	else if (r < 17)
	{
		zr = -0.139 * zr + 0.263 * zi + 57;
		zi = 0.246 * zr + 0.224 * zi - 8.28;
	}
	else if (r < 30)
	{
		zr = 0.17 * zr - 0.215 * zi + 40.8;
		zi = 0.222 * zr + 0.176 * zi + 20.539;
	}
	else
	{
		zr = 0.781 * zr + 0.034 * zi + 10.75;
		zi = -0.032 * zr + 0.739 * zi + 62.1;
	}
	thr->y = 4 * (235 - zi);
	thr->x = 4 * (zr - 5) + 300;
}

void	ft_fougere(t_s *s, t_thr *thr)
{
	int k;
	int r;
	int zr;
	int zi;

	k = 0;
	zr = 50;
	zi = 0;
	r = 0;
	while (++k < s->itermax)
		ft_fougere2(thr, r, zr, zi);
	ft_lightup_fougere(s, thr);
}
