/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:15:01 by tfalchi           #+#    #+#             */
/*   Updated: 2025/06/19 12:24:36 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode	*create_file(const char *name, int size)
{
	FSNode *new_file;
	
	new_file = (FSNode *)malloc(sizeof(FSNode));
	if (!new_file)
		return NULL;
	strncpy(new_file->name, name, sizeof(new_file->name) - 1);
	new_file->name[sizeof(new_file->name) - 1] = '\0';
	new_file->size = size;
	new_file->child = NULL;
	new_file->parent = NULL;
	return (new_file);
}

FSNode	*create_folder(const char *name)
{
	FSNode *new_folder;

	new_folder = (FSNode *)malloc(sizeof(FSNode));
	if (!new_folder)
		return NULL;
	strncpy(new_folder->name, name, sizeof(new_folder->name) - 1);
	new_folder->name[sizeof(new_folder->name) - 1] = '\0';
	new_folder->size = 0;
	new_folder->child = NULL;
	new_folder->parent = NULL;
	return (new_folder);
}
void add_child(FSNode *parent, FSNode *child)
{
	if (!parent || !child)
		return;
	
	child->parent = parent;
	
	if (parent->child == NULL)
		parent->child = child;
	else
	{
		FSNode *last_sibling = parent->child;
		while (last_sibling->child != NULL)
			last_sibling = last_sibling->child;
		last_sibling->child = child;
	}
	child->child = NULL;
}
FSNode	*get_children(const FSNode *parent)
{
	if (!parent)
		return NULL;
	return parent->child;
}

FSNode	*get_sibling(const FSNode *node)
{
	if (!node || !node->parent)
		return NULL;
	FSNode *sibling = node->parent->child;
	while (sibling)
	{
		if (sibling != node)
			return sibling;
		sibling = sibling->child;
	}
	return (NULL);
}

void print_fs(FSNode *node, int level)
{
	if (!node)
		return;
	for (int i = 0; i < level; i++)
		printf("  ");
	printf("%s (%d bytes)\n", node->name, node->size);
	FSNode *child = node->child;
	while (child)
	{
		print_fs(child, level + 1);
		child = child->child;
	}
}

void cleanup_fs(FSNode *node)
{
	int i = 0;

	while (node && node->child)
	{
		cleanup_fs(node->child);
		node = node->child;
	}
}
/*
int main(void)
{
	// Create root directory
	FSNode *root = create_folder("root");
	
	// Create folders
	FSNode *docs = create_folder("Documents");
	FSNode *pics = create_folder("Pictures");
	FSNode *music = create_folder("Music");
	
	// Add folders to root
	add_child(root, docs);
	add_child(root, pics);
	add_child(root, music);
	
	// Create and add files to Documents
	FSNode *resume = create_file("resume.pdf", 1024);
	FSNode *letter = create_file("cover_letter.doc", 512);
	add_child(docs, resume);
	add_child(docs, letter);
	
	// Create and add file to Pictures
	FSNode *photo = create_file("vacation.jpg", 2048);
	add_child(pics, photo);
	
	// Create and add file to Music
	FSNode *song = create_file("favorite_song.mp3", 4096);
	add_child(music, song);
	
	// Print the file system structure
	printf("File System Structure:\n");
	print_fs(root, 0);
	printf("\n");
	
	// Test get_children function
	printf("Testing get_children:\n");
	FSNode *child = get_children(root);
	if (child)
		printf("First child of root: %s\n", child->name);
	
	// Test get_sibling function
	printf("\nTesting get_sibling:\n");
	FSNode *sibling = get_sibling(docs);
	if (sibling)
		printf("A sibling of Documents: %s\n", sibling->name);
	
	// Test creating a deeper structure
	printf("\nCreating deeper structure:\n");
	FSNode *subfolder = create_folder("Subfolder");
	FSNode *deep_file = create_file("deep_file.txt", 100);
	add_child(docs, subfolder);
	add_child(subfolder, deep_file);
	
	// Print updated structure
	printf("\nUpdated File System Structure:\n");
	print_fs(root, 0);
	
	// Clean up all allocated memory
	cleanup_fs(root);
	
	return 0;
}
*/