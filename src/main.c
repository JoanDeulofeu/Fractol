/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <jgehin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:27:29 by jgehin            #+#    #+#             */
/*   Updated: 2019/02/13 16:28:40 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_main(t_s *s)
{
	s->savefract = s->fract;
	s->init = 0;
	s->dolink = 0;
	s->afflink = 0;
	s->affmenu = 1;
	s->julia = 1;
	s->move = 0;
	s->savex = 0;
	s->savey = 0;
	s->scope = 1;
	s->color = 0;
	s->m_ptr = mlx_init();
	s->w_ptr = mlx_new_window(s->m_ptr, XWIN, YWIN, "Fractol");
	s->itermax = 250;
}

int		main(int ac, char **av)
{
	t_s	*s;

	if (!(s = (t_s *)malloc(sizeof(t_s))))
		return (0);
	if (ac != 2)
		ft_exit(2, s);
	if (!(ft_strcmp(av[1], "Mandelbrot")))
		ft_init_mand(s);
	else if (!(ft_strcmp(av[1], "Julia")))
		ft_init_julia(s, 1);
	else if (!(ft_strcmp(av[1], "Joan")))
		ft_init_joan(s);
	else
		ft_exit(2, s);
	ft_init_main(s);
	ft_init_image(s, XWIN, YWIN);
	ft_fractales(s, 0);
	mlx_hook(s->w_ptr, 2, 0, key_hook, (void *)s);
	mlx_hook(s->w_ptr, 4, 0, mouse_hook, (void *)s);
	mlx_hook(s->w_ptr, 6, 0, mouse_move, (void *)s);
	mlx_hook(s->w_ptr, 17, 0, ft_expose, (void *)s);
	mlx_loop(s->m_ptr);
	return (0);
}

void	ft_exit(int error, t_s *s)
{
	if (error == 0)
		perror("pthread_create");
	if (error == 1)
		perror("pthread_join");
	if (error == 2)
		ft_putstr("usage : ./fractol [Mandelbrot / Julia / Joan]\n");
	if (error == 3)
		perror("malloc_link");
	free(s);
	exit(0);
}
