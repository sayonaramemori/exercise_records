#define RR 5
#define RL 9
#define LR 6
#define LL 10
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
typedef double Data_type;

typedef struct node
{
    Data_type val;
    node *lchld;node *rchld;
}*Node;

typedef struct binary_tree
{
    Node root;
    size_t size;
    size_t high;
}binary_tree;
Node create_node();
int get_high(binary_tree*);
bool node_link(Node *,const Data_type*);
bool insert(Node p,const Data_type *val,Node *trace);
void btree_Travel_midorder(binary_tree *btp,void(*pf)(Data_type*));
void btree_Travel_preorder(binary_tree *btp,void(*pf)(Data_type*));
void btree_Travel_lasorder(binary_tree *btp,void(*pf)(Data_type*));
void btree_insert(binary_tree *btp,const Data_type *val);
void btree_clean(binary_tree *btp);
Data_type btree_find_max(binary_tree *btp);
Data_type btree_find_min(binary_tree *btp);
bool btree_find(binary_tree *btp,const Data_type* vp);
