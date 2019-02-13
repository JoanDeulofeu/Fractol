/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:27:45 by jgehin            #+#    #+#             */
/*   Updated: 2019/02/13 15:29:03 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 100 : (placement / distance) * 100);
}

void	ft_dezoom(t_s *s, int x, int y)
{
	double pery;
	double perx;

	perx = x / (double)XWIN;
	pery = y / (double)YWIN;
	s->zoomx /= 1.25;
	s->zoomy /= 1.25;
	s->itermax -= 20;
	s->left -= 130 * (perx - 0.5) / s->zoomx * 2;
	s->right -= 130 * (perx - 0.5) / s->zoomx * 2;
	s->high -= 130 * (pery - 0.5) / s->zoomy * 2;
	s->low -= 130 * (pery - 0.5) / s->zoomy * 2;
	s->left -= s->zoom_coef * s->diffx;
	s->right -= s->zoom_coef * s->diffx;
	s->high -= s->zoom_coef * s->diffy;
	s->low -= s->zoom_coef * s->diffy;
	s->zoom_coef /= 0.8;
}

void	ft_zoom_joan(t_s *s, int x, int y)
{
	s->zoomx *= 1.29;
	s->zoomy *= 1.29;
	s->left = ((s->left * s->zoomx + x - 0.5 *
		s->img_x + 160 + s->diffx) / s->zoomx);
	s->right = ((s->right * s->zoomx + x - 0.5 *
		s->img_x + 160 + s->diffx) / s->zoomx);
	s->high = ((s->high * s->zoomy + y - 0.5 *
		s->img_y + 160 + s->diffy) / s->zoomy);
	s->low = ((s->low * s->zoomy + y - 0.5 *
		s->img_y + 160 + s->diffy) / s->zoomy);
	s->itermax += 3;
}

void	ft_zoom(t_s *s, int x, int y, int zoom)
{
	double pery;
	double perx;

	if (zoom == 1 && s->fract != 3)
	{
		perx = x / (double)XWIN;
		pery = y / (double)YWIN;
		s->zoomx *= 1.25;
		s->zoomy *= 1.25;
		s->itermax += 20;
		s->left += 130 * (perx - 0.5) / s->zoomx * 2;
		s->right += 130 * (perx - 0.5) / s->zoomx * 2;
		s->high += 130 * (pery - 0.5) / s->zoomy * 2;
		s->low += 130 * (pery - 0.5) / s->zoomy * 2;
		s->left += s->zoom_coef * s->diffx;
		s->right += s->zoom_coef * s->diffx;
		s->high += s->zoom_coef * s->diffy;
		s->low += s->zoom_coef * s->diffy;
		s->zoom_coef *= 0.8;
	}
	if (zoom == 1 && s->fract == 3)
		ft_zoom_joan(s, x, y);
	if (zoom == 0)
		ft_dezoom(s, x, y);
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
