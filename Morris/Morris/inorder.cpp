#include"mtree.h"

#include <stdio.h>

static node_t * precursor(node_t * root)
{
	node_t * pre;
	if(root==NULL)
		return NULL; 
	if(root->left == NULL)
		return NULL;
	
	pre = root->left;
	/*
				B
		A				D
				C				E
		The A is the precursor of B , when we set A->right = B;
		Then, the next step current = current->right. The precursor is A->right(B)->right(D)->right(E)
		So, when we find the precursor, we must make sure : pre->right != root
	*/
	while(pre->right!=NULL && pre->right != root){
		pre = pre->right;
	}

	return pre;
}
void inorder_traversal(node_t * root)
{
	node_t * current, *prev;
	if(root==NULL) return;

	current = root;
	while(current!=NULL){
		if(current->left==NULL){
			fprintf(stdout,"%d  ", current->data);
			current = current->right;
		}else{
			prev = precursor(current);
			if(prev->right == NULL){
				prev->right = current;
				current = current->left;
			}
			else{
				/*
					Revert the changes made in if part to restore the original tree
					The precursor of B is A. 
					When A is done, A->right == B; So we must revert A->right = NULL and Print B, Then to deal with the B->right
				*/
				prev->right = NULL;
				fprintf(stdout,"%d ",current->data);
				current = current->right;
			}
		}
	}
}

