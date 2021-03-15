#include "btree.h"
#include <stdio.h>

int item_cmp(void *item ,void *cmp)
{
	if (item < cmp)
		return (-1);
	if (item > cmp)
		return (1);
	return (0);
}

int main(int argc, char **av)
{
	t_btree *tree;

	void *a, *b;
	a = 3;
	b = 4;
	tree = btree_create_node(a);
	printf("test creation:\n%d", tree->item);
	btree_insert_data(&tree, b, item_cmp);
	printf("\ntest insertion:\n%d\n%d", tree->item, tree->right->item);
	printf("\ntest search:\nif result == %d => works\nresult = %d", a, btree_search_item(&tree, a, item_cmp));
}