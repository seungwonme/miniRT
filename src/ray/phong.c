/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:47:29 by sunko             #+#    #+#             */
/*   Updated: 2023/12/23 20:49:25 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"
#include "ray.h"

static t_color3	get_diffuse(t_vars *vars, t_light *light, t_vec3 light_dir);
static t_vec3	get_reflect_vec(t_vec3 v, t_vec3 n);
static t_color3	get_specular(t_vars *vars, t_light *light, t_vec3 light_dir);
static t_color3	point_light_get(t_vars *vars, t_light *light);

t_color3	execute_phong(t_vars *vars)
{
	t_color3	light_color;
	t_list		*light;

	light_color = color3(0, 0, 0);
	light = vars->light;
	while (light)
	{
		if (light->type == LIGHT)
			light_color = v_plus(light_color, \
			point_light_get(vars, (t_light *)light->content));
		light = light->next;
	}
	return (v_min(v_mul(light_color, vars->rec.color), color3(1, 1, 1)));
}

static t_color3	point_light_get(t_vars *vars, t_light *light)
{
	t_color3	diffuse;
	t_vec3		light_dir;
	t_color3	specular;
	t_ray		light_ray;
	double		light_len;

	light_dir = v_minus(light->light_point, vars->rec.p);
	light_len = v_length(light_dir);
	light_dir = v_unit(light_dir);
	light_ray = ray(v_plus(vars->rec.p, vt_mul(light_dir, 1e-6)), \
	light_dir);
	diffuse = get_diffuse(vars, light, light_dir);
	specular = get_specular(vars, light, light_dir);
	if (in_shadow(vars, light_ray, light_len))
		return (v_mul(vars->rec.color, vars->ambient.r_rgb));
	return (v_plus(v_plus(vars->ambient.r_rgb, diffuse), specular));
}

static t_color3	get_diffuse(t_vars *vars, t_light *light, t_vec3 light_dir)
{
	double	kd;

	kd = fmax(v_dot(vars->rec.normal, light_dir), 0.0);
	return (vt_mul(light->r_rgb, kd));
}

static t_color3	get_specular(t_vars *vars, t_light *light, t_vec3 light_dir)
{
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;

	view_dir = v_unit(vt_mul(vars->ray.dir, -1));
	reflect_dir = get_reflect_vec(vt_mul(light_dir, -1), vars->rec.normal);
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), SHIN_VALUE);
	return (vt_mul(vt_mul(light->r_rgb, SPEC_VALUE), spec));
}

static t_vec3	get_reflect_vec(t_vec3 v, t_vec3 n)
{
	return (v_minus(v, vt_mul(n, v_dot(v, n) * 2)));
}
