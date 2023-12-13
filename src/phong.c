/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:47:29 by sunko             #+#    #+#             */
/*   Updated: 2023/12/13 23:54:52 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vector.h"
#include "ray.h"
#include <math.h>

static t_color3	get_diffuse(t_vars *vars, t_light *light)
{
	t_vec3	light_dir;
	double	kd;

	light_dir = v_unit(v_minus(light->light_point, vars->rec.p));
	kd = fmax(v_dot(vars->rec.normal, light_dir), 0.0);
	return (vt_mul(light->r_rgb, kd));
}

static t_vec3	get_reflect_vec(t_vec3 v, t_vec3 n)
{
	return (v_minus(v, vt_mul(n, v_dot(v, n) * 2)));
}

static t_color3	get_specular(t_vars *vars, t_light *light)
{
	t_vec3	light_dir;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;

	light_dir = v_unit(v_minus(light->light_point, vars->rec.p));
	view_dir = v_unit(vt_mul(vars->ray.dir, -1));
	reflect_dir = get_reflect_vec(vt_mul(light_dir, -1), vars->rec.normal);
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), SHIN_VALUE);
	return (vt_mul(vt_mul(light->r_rgb, 0.5), spec));
}

static t_color3	point_light_get(t_vars *vars, t_light *light)
{
	t_color3	diffuse;
	t_color3	specular;
	double		light_len;
	t_ray		light_ray;
	t_vec3		light_dir;

	light_dir = v_minus(light->light_point, vars->rec.p);
	light_len = v_length(light_dir);
	light_ray = ray(\
	v_plus(vars->rec.p, vt_mul(vars->rec.normal, 1e-6)), light_dir);
	if (in_shadow(vars->objects, light_ray, light_len))
		return (color3(0, 0, 0));
	diffuse = get_diffuse(vars, light);
	specular = get_specular(vars, light);
	return (vt_mul(\
	v_plus(v_plus(\
	vt_mul(vars->ambient.r_rgb, vars->ambient.lighting_ratio), \
	diffuse), specular), light->brightness_ratio));
}

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
	return (v_min(light_color, color3(1, 1, 1)));
}