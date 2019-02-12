/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:26:34 by jgehin            #+#    #+#             */
/*   Updated: 2019/02/12 15:26:54 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned char	ft_red(t_s *s, t_thr *thr)
{
	if (s->fract == 2)
		return (255);
	if (s->color == 0)
		return (sin(0.3 * (thr->i * 255 / s->itermax)) * 127 + 128);
	if (s->color == 1)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 20) * 127 + 128);
	if (s->color == 2)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 1.2) * 127 + 128);
	if (s->color == 3)
		return (sin(0.7 * (thr->i * 255 / s->itermax) + 9) * 127 + 128);
	if (s->color == 4)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 4) * 127 + 128);
	if (s->color == 5)
		return (sin(0.6 * (thr->i * 255 / s->itermax) + 3.1) * 127 + 128);
	if (s->color == 6)
		return (sin(0.05 * (thr->i * 255 / s->itermax)) * 127 + 128);
	if (s->color == 7)
		return (sin(0.1 * (thr->i * 255 / s->itermax) + 6) * 127 + 128);
	if (s->color == 8)
		return (sin(0.4 * (thr->i * 255 / s->itermax) + 1) * 127 + 128);
	return (0);
}

unsigned char	ft_green(t_s *s, t_thr *thr)
{
	if (s->fract == 2)
		return (255);
	if (s->color == 0)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 2) * 127 + 128);
	if (s->color == 1)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 2) * 127 + 128);
	if (s->color == 2)
		return (sin(0.3 * (thr->i * 255 / s->itermax)) * 127 + 128);
	if (s->color == 3)
		return (sin(0.7 * (thr->i * 255 / s->itermax) + 4) * 127 + 128);
	if (s->color == 4)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 4) * 127 + 128);
	if (s->color == 5)
		return (sin(0.2 * (thr->i * 255 / s->itermax) + 2.8) * 127 + 128);
	if (s->color == 6)
		return (sin(2 * (thr->i * 255 / s->itermax)) * 127 + 128);
	if (s->color == 7)
		return (sin(0.4 * (thr->i * 255 / s->itermax) + 6) * 127 + 128);
	if (s->color == 8)
		return (sin(0.4 * (thr->i * 255 / s->itermax) + 4) * 127 + 128);
	return (0);
}

unsigned char	ft_blue(t_s *s, t_thr *thr)
{
	if (s->fract == 2)
		return (255);
	if (s->color == 0)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 4) * 127 + 128);
	if (s->color == 1)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 4) * 127 + 128);
	if (s->color == 2)
		return (sin(0.3 * (thr->i * 255 / s->itermax)) * 127 + 128);
	if (s->color == 3)
		return (sin(0.7 * (thr->i * 255 / s->itermax) + 0.5) * 127 + 128);
	if (s->color == 4)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 4) * 127 + 128);
	if (s->color == 5)
		return (sin(0.3 * (thr->i * 255 / s->itermax) + 1.8) * 127 + 128);
	if (s->color == 6)
		return (sin(6.2 * (thr->i * 255 / s->itermax)) * 127 + 128);
	if (s->color == 7)
		return (sin(0.1 * (thr->i * 255 / s->itermax) + 2.5) * 127 + 128);
	if (s->color == 8)
		return (sin(0.4 * (thr->i * 255 / s->itermax) + 7) * 127 + 128);
	return (0);
}

void			ft_lightup_pixel(t_s *s, t_thr *thr)
{
	int new_x;

	if (s->dolink == 1)
		ft_lightup_menu(s, thr, s->link1->s_img);
	else if (s->dolink == 2)
		ft_lightup_menu(s, thr, s->link2->s_img);
	else if (s->dolink == 3)
		ft_lightup_menu(s, thr, s->link3->s_img);
	else if (s->dolink == 4)
		ft_lightup_menu(s, thr, s->link4->s_img);
	else
	{
		if (thr->x <= s->img_x && thr->y <= s->img_y &&
			thr->x >= 0 && thr->y >= 0)
		{
			new_x = thr->x * 4 + ((s->img_x * 4) * thr->y);
			s->s_img[new_x + 0] = ft_blue(s, thr);
			s->s_img[new_x + 1] = ft_green(s, thr);
			s->s_img[new_x + 2] = ft_red(s, thr);
			s->s_img[new_x + 3] = 0;
		}
	}
}

int				ft_init_image(void *ptr, int sizex, int sizey)
{
	int size;
	int	bpp;
	int endian;
	t_s *s;

	s = (t_s *)ptr;
	size = sizex;
	bpp = 4;
	endian = 0;
	s->img = mlx_new_image(s->m_ptr, sizex, sizey);
	s->s_img = (unsigned char*)(mlx_get_data_addr(s->img, &(bpp), &(size),
	&(endian)));
	return (0);
}
