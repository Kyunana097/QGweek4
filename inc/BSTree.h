#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int Type;

//节点定义
typedef struct BSTreeNode               
{
    Type   key;                             // 关键字（键值），用来对二叉查找树的节点进行排序
    struct BSTreeNode* left;                // 左孩子指针
    struct BSTreeNode* right;               // 右孩子指针
    struct BSTreeNode* parent;              // 父节点指针
} Node, * BSTree;

// 创建二叉树节点
struct Node* create_bstree_node(Type key, Node* parent, Node* left, Node* right);

// 前序遍历
void preorder_bstree(BSTree tree);
// 中序遍历
void inorder_bstree(BSTree tree);
// 后序遍历
void postorder_bstree(BSTree tree);

// 前序遍历（非递归）
void iterative_preorder_bstree(BSTree tree);
// 中序遍历（非递归）
void iterative_inorder_bstree(BSTree tree);
// 后序遍历（非递归）
void iterative_postorder_bstree(BSTree tree);

// 查找最小结点：返回tree为根结点的二叉树的最小结点。
Node* bstree_minimum(BSTree tree);
// 查找最大结点：返回tree为根结点的二叉树的最大结点。
Node* bstree_maximum(BSTree tree);

// 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
Node* bstree_successor(Node* x);
// 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
Node* bstree_predecessor(Node* x);

//查找(递归)
Node* bstree_search(BSTree x, Type key);
//查找（非递归）
Node* iterative_bstree_search(BSTree x, Type key);

//插入节点 将结点(z)插入到二叉树(tree)中，并返回插入节点后的根节点(内部调用函数)
static Node* bstree_insert(BSTree tree, Node* z);
//插入节点 在树中新增节点，key是节点的值；并返回插入节点后的根节点（查找并插入 外部接口）
Node* insert_bstree(BSTree tree, Type key);

//删除节点 删除二叉树(tree)中的节点(z)，并返回删除节点后的根节点（内部调用函数）
static Node* bstree_delete(BSTree tree, Node* z);
//删除节点 在树中查找键值为key的节点，找到的话就删除该节点；并返回删除节点后的根节点(查找并删除 外部接口)
Node* delete_bstree(BSTree tree, Type key);

//打印二叉树
void print_bstree(BSTree tree, Type key, int direction);

//销毁二叉树（册尼玛跟你爆了）（递归）
void destroy_bstree(BSTree tree);

//统计节点数
int count_bstree(BSTree tree);

//层次遍历
void levelOrderTraversal(BSTree root);

#endif
