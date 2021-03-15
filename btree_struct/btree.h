#ifndef FT_BTREE_H
# define FT_BTREE_H

#include <string.h>

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
t_btree		*btree_create_node(void *item);
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

#endif