#include "btree.h"

int main(int argc, char **av)
{
	t_btree 	*tree;
	void		*item1;
	void		*item2;
	
	item1 = 10;
	item2 = 2;
	tests(tree, item1, item2);
}