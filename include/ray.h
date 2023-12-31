/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:18:07 by sunko             #+#    #+#             */
/*   Updated: 2023/12/21 16:15:07 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "structures.h"

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, const double t);

t_bool		hit_sphere(t_sphere *sphere, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_plane *plane, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_cylinder *cylinder, t_ray *ray, t_hit_record *rec);
t_bool		hit_cone(t_cone *cone, t_ray *ray, t_hit_record *rec);
t_bool		hit_disk(t_plane *disk, double radius, \
				t_ray *ray, t_hit_record *rec);

t_color3	execute_phong(t_vars *vars);

t_bool		hit_obj(t_list *object, t_ray *ray, t_hit_record *rec);
t_bool		hit(t_vars *vars, t_ray *ray, t_hit_record *rec);
t_bool		in_shadow(t_vars *vars, t_ray r, double light_len);
t_color3	ray_color(t_vars *vars);

#endif
