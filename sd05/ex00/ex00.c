/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:26:17 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/19 17:22:17 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00.h"

void	init_book(t_book *book);
t_book	parse_book(char *str);
int		count_books(char *str);

/* Custom string splitting functions */
char	*get_next_field(char *str, char delimiter, int *pos)
{
	int		start;
	int		i;
	char	*result;
	int		length;

	start = *pos;
	i = start;
	// Skip to the next delimiter or end of string
	while (str[i] != '\0' && str[i] != delimiter)
		i++;
	// Calculate length of field
	length = i - start;
	// Allocate memory for the field
	result = (char *)malloc(length + 1);
	if (!result)
		return (NULL);
	// Copy the field
	for (int j = 0; j < length; j++)
		result[j] = str[start + j];
	result[length] = '\0';
	// Update position
	if (str[i] == delimiter)
		*pos = i + 1; // Skip the delimiter
	else
		*pos = i; // End of string
	return (result);
}

t_book	parse_book(char *str)
{
	t_book	book;
	int		pos;

	init_book(&book);
	char *id_str, *title, *author;
	pos = 0;
	if (!str || *str == '\0')
	{
		book.warning = true;
		return (book);
	}
	// Parse ID
	id_str = get_next_field(str, ',', &pos);
	if (id_str)
	{
		book.number = atoi(id_str);
		if (book.number < 0)
			book.warning = true;
		free(id_str);
	}
	else
	{
		book.warning = true;
	}
	title = get_next_field(str, ',', &pos);
	if (title && strlen(title) > 0)
	{
		book.title = title;
		for (int i = 0; title[i]; i++)
		{
			if (title[i] == ' ' && title[i + 1] == ' ')
			{
				book.warning = true;
				break ;
			}
		}
	}
	else
	{
		free(title);
		book.warning = true;
	}
	author = get_next_field(str, ',', &pos);
	if (author && strlen(author) > 0)
	{
		book.author = author;
		for (int i = 0; author[i]; i++)
		{
			if (author[i] == ' ' && author[i + 1] == ' ')
			{
				book.warning = true;
				break ;
			}
		}
	}
	else
	{
		free(author);
		book.warning = true;
	}
	return (book);
}

int	main(int argc, char *argv[])
{
	int		num_books;
	t_book	*books;
	char	*input;
	int		book_idx;
	int		pos;
	char	*book_str;

	pos = 0;
	if (argc != 2)
	{
		printf("Usage: %s \"book_list\"\n", argv[0]);
		return (1);
	}
	num_books = count_books(argv[1]);
	if (num_books <= 0)
	{
		printf("No valid books found in input\n");
		return (1);
	}
	books = (t_book *)malloc(sizeof(t_book) * num_books);
	if (!books)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	for (int i = 0; i < num_books; i++)
	{
		init_book(&books[i]);
	}
	input = ft_strdup(argv[1]);
	book_idx = 0;
	pos = 0;
	while (book_idx < num_books)
	{
		book_str = get_next_field(input, '\t', &pos);
		if (!book_str)
			break ;
		books[book_idx] = parse_book(book_str);
		free(book_str); // Free the book string after parsing
		book_idx++;
	}
	// Display results
	for (int i = 0; i < num_books; i++)
	{
		printf("Book %d:\n", i + 1);
		printf("  ID: %d\n", books[i].number);
		printf("  Title: %s\n", books[i].title ? books[i].title : "N/A");
		printf("  Author: %s\n", books[i].author ? books[i].author : "N/A");
		printf("  Warning: %s\n", books[i].warning ? "Yes" : "No");
		printf("\n");
	}
	// Cleanup
	for (int i = 0; i < num_books; i++)
	{
		free(books[i].title);
		free(books[i].author);
	}
	free(books);
	free(input);
	return (0);
}

void	init_book(t_book *book)
{
	if (book)
	{
		book->title = NULL;
		book->author = NULL;
		book->number = 0;
		book->warning = false;
	}
}

int	count_books(char *str)
{
	int	count;

	if (!str || *str == '\0')
		return (0);
	count = 1;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '\t')
			count++;
	}
	return (count);
}
