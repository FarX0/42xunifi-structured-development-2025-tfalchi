#ifndef FILESYTEM_H
# define FILESYTEM_H

typedef struct s_FSNode
{
	
	s_FSNode	*sub_folder;
}					FSNode;

typedef struct s_file
{
	s_file	*data;
}					file;

FSNode	*create_file(const char *name, int size);
FSNode	*create_folder(const char *name);
void	add_child(FSNode *parent, FSNode *child);
FSNode	*get_children(const FSNode *parent);
FSNode	*get_sibling(const FSNode *node);

#endif