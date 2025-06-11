/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:53:57 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/11 17:01:14 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
	struct Preferences *prefs;
	struct MovieList *list;
	struct Plan *plan;

	prefs = get_user_preferences();
	if (!prefs)
		return (NULL);
	list = find_movies(prefs);
	if (!list)
	{
		free(prefs);
		return (NULL);
	}
	plan = build_plan(list);
	if (!plan)
	{
		for (int i = 0; i < list->number; i++)
			free(list->movie[i]);
		free(list->movie);
		free(list);
		free(prefs);
		return (NULL);
	}
	free(list->movie);
	free(list);
	free(prefs);
	return (plan);
}
