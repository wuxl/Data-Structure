#include "mtree.h"
#include <stdlib.h>
#include <string.h>

node_t * new_node(int data)
{
	node_t * node = (node_t *)malloc(sizeof(node_t));

	memset(node,0,sizeof(*node));

	node->data = data;

	return node;
}

node_t * tree_insert(node_t *root, int data)
{
	node_t * parent,* current  = NULL;

	if(root ==NULL){
		root = new_node(data);
		return root;
	}
	
	current = root;
	while(current != NULL){
		parent= current;
		if(data > current->data){
			current = current->right;
		}
		else if(data == current->data){
			break;
		}
		else{
			current = current->left;
		}
	}

	if(!current){
		(data > parent->data ? parent->right : parent->left) = new_node(data);
	}
	return root;
}