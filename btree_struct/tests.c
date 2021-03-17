#include "btree.h"

int item_cmp(void *item ,void *cmp)
{
	if (item < cmp)
		return (-1);
	if (item > cmp)
		return (1);
	return (0);
}

void tests(t_btree *tree, void *item1, void *item2)
{
	tree = btree_create_node(item1);
	if (!item1 || !item2)
	{
		printf ("%sWRONG ARGUMENTS%s");
		exit (1);
	}
	printf("Creation test:\n");
	if (tree->item)
		printf("%d\n%stest passed%s\n", tree->item, RED, RESET);
	else
		printf("%s\ntest failed%s\n", RED, RESET);
	btree_insert_data(tree, item2, item_cmp);
	printf("Insertion test:\n");
	if (tree->left->item)
		printf("%d %d\n%stest passed%s\n",tree->item, tree->left->item, RED, RESET);
	else if(tree->right->item)
		printf("%d %d\n%stest passed%s\n",tree->item,  tree->right->item, RED, RESET);
	else
		printf("%s\ntest failed%s\n", RED, RESET);
	printf("Search test:\nSearching %d\n", item1);
	if (item1 == btree_search_item(tree, item1, item_cmp))
		printf("%d was found\n%stest passed%s\n", item1, RED, RESET);
	else
		printf("%s\ntest failed%s\n", RED, RESET);
}