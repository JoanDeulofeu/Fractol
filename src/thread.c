#include "fractol.h"

void *ft_thread_1(void *arg)
{
	t_thr	*thr1;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr1 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	s->pxl = 0;
	while (i++ < YWIN / 8) //130 pour 1040
	{
		ft_resetmand(s, thr1);
		thr1 = ft_calcul(s, thr1);
		if (thr1->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, thr1->i * 255 / s->itermax);
	}
	free(thr1);
	pthread_exit(NULL);
}


void *ft_thread_2(void *arg)
{
	t_thr	*thr2;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr2 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	s->pxl = 130;
	while (i++ < YWIN / 8) //130 pour 1040
	{
		ft_resetmand(s, thr2);
		thr2 = ft_calcul(s, thr2);
		if (thr2->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, thr2->i * 255 / s->itermax);
	}
	free(thr2);
	pthread_exit(NULL);
}

void *ft_thread_3(void *arg)
{
	t_thr	*thr3;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr3 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	s->pxl = 260;
	while (i++ < YWIN / 8) //130 pour 1040
	{
		ft_resetmand(s, thr3);
		thr3 = ft_calcul(s, thr3);
		if (thr3->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, thr3->i * 255 / s->itermax);
	}
	free(thr3);
	pthread_exit(NULL);
}

void *ft_thread_4(void *arg)
{
	t_thr	*thr4;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr4 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	s->pxl = 390;
	while (i++ < YWIN / 8) //130 pour 1040
	{
		ft_resetmand(s, thr4);
		thr4 = ft_calcul(s, thr4);
		if (thr4->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, thr4->i * 255 / s->itermax);
	}
	free(thr4);
	pthread_exit(NULL);
}

void *ft_thread_5(void *arg)
{
	t_thr	*thr5;
	t_s 	*s;
	int		i;

	i = 0;
	if (!(thr5 = (t_thr *)malloc(sizeof(t_thr))))
		return (0);
	s = (t_s *)arg;
	s->pxl = 520;
	while (i++ < YWIN / 8) //130 pour 1040
	{
		ft_resetmand(s, thr5);
		thr5 = ft_calcul(s, thr5);
		if (thr5->i == s->itermax)
			ft_lightup_pixel(s, s->x, s->y, 255);
		else
			ft_lightup_pixel(s, s->x, s->y, thr5->i * 255 / s->itermax);
	}
	free(thr5);
	pthread_exit(NULL);
}
