#include "btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*out;

	out = NULL;
	if (root)
	{
		out = btree_search_item(root->left, data_ref, cmpf);
		if (!out && !((*cmpf)(root->item, data_ref)))
			out = root->item;
		if (!out)
			out = btree_search_item(root->right, data_ref, cmpf);
	}
	return (out);
}