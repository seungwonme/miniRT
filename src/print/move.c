/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:01:00 by seunan            #+#    #+#             */
/*   Updated: 2023/12/14 22:31:35 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"
#include "hook.h"
#include "print.h"
#include <math.h>

static void	update_viewport(t_vars *vars)
{
	vars->camera.fov_len = atan((vars->camera.fov / 2) * (M_PI / 180));
	vars->camera.viewport_upper_left = v_minus(v_minus(v_minus(\
	vars->camera.view_point, vec3(0, 0, vars->camera.fov_len)) \
	, vt_mul(vars->camera.viewport_u, 0.5)) \
	, vt_mul(vars->camera.viewport_v, 0.5));
	vars->camera.pixel_00_loc = v_plus(\
	vars->camera.viewport_upper_left \
	, vt_mul(\
	v_plus(vars->camera.pixel_delta_u, vars->camera.pixel_delta_v), 0.5));
}

void	move_front(t_mlx_args *mlx_args)
{
	t_mlx_data	*mlx_data;

	mlx_data = mlx_args->mlx_data;
	mlx_args->vars->camera.view_point = \
		v_minus(mlx_args->vars->camera.view_point, vec3(0, 0, 0.5));
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, \
		&mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
	update_viewport(mlx_args->vars);
	render(mlx_args->vars, mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img, 0, 0);
}

void	move_left(t_mlx_args *mlx_args)
{
	t_mlx_data	*mlx_data;

	mlx_data = mlx_args->mlx_data;
	mlx_args->vars->camera.view_point = \
		v_minus(mlx_args->vars->camera.view_point, vec3(0.5, 0, 0));
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, \
		&mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
	update_viewport(mlx_args->vars);
	render(mlx_args->vars, mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img, 0, 0);
}

void	move_back(t_mlx_args *mlx_args)
{
	t_mlx_data	*mlx_data;

	mlx_data = mlx_args->mlx_data;
	mlx_args->vars->camera.view_point = \
		v_plus(mlx_args->vars->camera.view_point, vec3(0, 0, 0.5));
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, \
		&mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
	update_viewport(mlx_args->vars);
	render(mlx_args->vars, mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img, 0, 0);
}

void	move_right(t_mlx_args *mlx_args)
{
	t_mlx_data	*mlx_data;

	mlx_data = mlx_args->mlx_data;
	mlx_args->vars->camera.view_point = \
		v_plus(mlx_args->vars->camera.view_point, vec3(0.5, 0, 0));
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, \
		&mlx_data->bits_per_pixel, &mlx_data->line_length, &mlx_data->endian);
	update_viewport(mlx_args->vars);
	render(mlx_args->vars, mlx_data);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img, 0, 0);
}