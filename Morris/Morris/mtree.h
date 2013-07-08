#ifndef MORRIS_MTREE_H
#define MORRIS_MTREE_H

typedef struct node_t{
	int data;
	struct node_t *left;
	struct node_t *right;
}node_t;

#endif