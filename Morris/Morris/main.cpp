#include "mtree.h"
#include <stdlib.h>

extern void inorder_traversal(node_t * root);
extern node_t * tree_insert(node_t *root, int data);

int main()
{
	char c_list[] = {'F', 'B','A','G','D','I','E','C','H',NULL};
	char * c_data;
	node_t * root = NULL;

	for(c_data = c_list; *c_data != NULL; c_data+= 1){
		root = tree_insert(root, *c_data);
	} 

	inorder_traversal(root);

	return 0;
}