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
	double diffx;
	double diffy;
	double percent;

	percent = 0.2;
	// x=y;
	diffx = (fabs(s->left) + fabs(s->right)) / 2;
	diffy = (fabs(s->high) + fabs(s->low)) / 2;
	if (zoom == 1)
	{
		s->zoomx *= 1.29;
		s->zoomy *= 1.29;
		s->left = ((s->left * s->zoomx + x - 0.5 * s->img_x + 160 + diffx) / s->zoomx);
		s->right = ((s->right * s->zoomx + x - 0.5 * s->img_x + 160 + diffx) / s->zoomx);
		s->high = ((s->high * s->zoomy + y - 0.5 * s->img_y + 160 + diffy) / s->zoomy);
		s->low = ((s->low * s->zoomy + y - 0.5 * s->img_y + 160 + diffy) / s->zoomy);

		// s->left = (s->left * s->zoomx - fabs(s->left) + fabs(s->right) * 0.1 * s->zoomx) / s->zoomx;
		// s->right = (s->right * s->zoomx - fabs(s->left) + fabs(s->right) * 0.1 * s->zoomx) / s->zoomx;
		// s->high = (s->high * s->zoomy - fabs(s->high) + fabs(s->low) * 0.1 * s->zoomy) / s->zoomy;
		// s->low = (s->low * s->zoomy - fabs(s->high) + fabs(s->low) * 0.1 * s->zoomy) / s->zoomy;

		// printf("   -avant-\ns->left=%f, s->right=%f, s->high=%f, s->low=%f\ndiffx=%f, diffy=%f\n", s->left,s->right,s->high,s->low,diffx,diffy);
		// s->left = s->left + (diffx * percent);
		// s->right = s->right - (diffx * percent);
		// s->high = s->high + (diffy * percent);
		// s->low = s->low - (diffy * percent);
		// printf("   -apres-\ns->left=%f, s->right=%f, s->high=%f, s->low=%f\ndiffx=%f, diffy=%f\n\n", s->left,s->right,s->high,s->low,diffx,diffy);

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

t_thr	*ft_calcul(t_s *s, t_thr *thr)
{
	double	tmp;

	if (s->fract != 3)
		while (thr->zr * thr->zr + thr->zi * thr->zi < 4 && thr->i < s->itermax)
		{
			tmp = thr->zr;
			thr->zr = thr->zr * thr->zr - thr->zi * thr->zi + thr->cr;
			thr->zi = 2 * thr->zi * tmp + thr->ci;
			thr->i++;
		}
	else
		while (thr->zr * thr->zr + thr->zi * thr->zi < 4 && thr->i < s->itermax)
		{
			tmp = thr->zr;
			thr->zr = sin(thr->zr * thr->zr) * 2 - thr->zi * thr->zi + thr->cr;
			thr->zi = sin(2 * thr->zi) * 2 * tmp + thr->ci;
			thr->i++;
		}
	return (thr);
}
