#include "fractol.h"

int		ft_percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 100 : (placement / distance) * 100);
}

void    ft_zoom(t_s *s, int x, int y, int zoom)
{
	if (zoom == 1)
	{
		s->zoomx *= 1.2;
		s->zoomy *= 1.2;
		s->left = (s->left * s->zoomx + x - 0.5 * XWIN) / s->zoomx;
		s->right = (s->right * s->zoomx + x + 0.5 * XWIN) / s->zoomx;
		s->high = (s->high * s->zoomy + y - 0.5 * YWIN) / s->zoomy;
		s->low = (s->low * s->zoomy + y + 0.5 * YWIN) / s->zoomy;
		s->itermax += 3;
	}
	if (zoom == 0)
	{
		s->zoomx *= 0.8;
		s->zoomy *= 0.8;
		s->left = (s->left * s->zoomx) / s->zoomx;
		s->right = (s->right * s->zoomx) / s->zoomx;
		s->high = (s->high * s->zoomy) / s->zoomy;
		s->low = (s->low * s->zoomy) / s->zoomy;
		s->itermax -= 3;
	}
}
