/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:53:57 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/11 17:54:26 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
	struct MusicLibrary *library;
	const char **filenames;
	struct MusicFile *song;

	library = create_music_library();
	if (!library)
		return (NULL);
	filenames = scan_directory(directory_path);
	if (!filenames)
	{
		free(library);
		return (NULL);
	}
	for (int i = 0; filenames[i] != NULL; i++)
	{
		song = process_music_file(directory_path, filenames[i]);
		if (!song)
		{
			free(filenames);
			free(library);
			return (NULL);
		}
		update_music_library(library, song);
		free(song);
	}
	free(filenames);
	return (library);
}
