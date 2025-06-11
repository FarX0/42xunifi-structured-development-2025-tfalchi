#ifndef MOVIE_PLANNER_H
# define MOVIE_PLANNER_H

# include <stdlib.h>

typedef struct Movie
{
	char	*name;
	char	genere;
	int		time;
}					Movie;

typedef struct Preferences
{
	char	*name;
	Movie	movie;
}					Preferences;

typedef struct MovieList
{
	Movie	**movie;
	int		number;
}					MovieList;

typedef struct plan
{
	Movie	*movie;
}					plan;

// Returns user preferences. Returns NULL on failure.
struct Preferences *get_user_preferences(void);
// Returns a list of movies matching the given preferences. Returns NULL on failure.
struct MovieList *find_movies(struct Preferences *prefs);
// Returns a movie night plan from the given list. Returns NULL on failure.
struct Plan *build_plan(struct MovieList *list);

#endif