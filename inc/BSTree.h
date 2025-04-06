#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int Type;

//�ڵ㶨��
typedef struct BSTreeNode               
{
    Type   key;                             // �ؼ��֣���ֵ���������Զ���������Ľڵ��������
    struct BSTreeNode* left;                // ����ָ��
    struct BSTreeNode* right;               // �Һ���ָ��
    struct BSTreeNode* parent;              // ���ڵ�ָ��
} Node, * BSTree;

// �����������ڵ�
struct Node* create_bstree_node(Type key, Node* parent, Node* left, Node* right);

// ǰ�����
void preorder_bstree(BSTree tree);
// �������
void inorder_bstree(BSTree tree);
// �������
void postorder_bstree(BSTree tree);

// ǰ��������ǵݹ飩
void iterative_preorder_bstree(BSTree tree);
// ����������ǵݹ飩
void iterative_inorder_bstree(BSTree tree);
// ����������ǵݹ飩
void iterative_postorder_bstree(BSTree tree);

// ������С��㣺����treeΪ�����Ķ���������С��㡣
Node* bstree_minimum(BSTree tree);
// ��������㣺����treeΪ�����Ķ�����������㡣
Node* bstree_maximum(BSTree tree);

// �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
Node* bstree_successor(Node* x);
// �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
Node* bstree_predecessor(Node* x);

//����(�ݹ�)
Node* bstree_search(BSTree x, Type key);
//���ң��ǵݹ飩
Node* iterative_bstree_search(BSTree x, Type key);

//����ڵ� �����(z)���뵽������(tree)�У������ز���ڵ��ĸ��ڵ�(�ڲ����ú���)
static Node* bstree_insert(BSTree tree, Node* z);
//����ڵ� �����������ڵ㣬key�ǽڵ��ֵ�������ز���ڵ��ĸ��ڵ㣨���Ҳ����� �ⲿ�ӿڣ�
Node* insert_bstree(BSTree tree, Type key);

//ɾ���ڵ� ɾ��������(tree)�еĽڵ�(z)��������ɾ���ڵ��ĸ��ڵ㣨�ڲ����ú�����
static Node* bstree_delete(BSTree tree, Node* z);
//ɾ���ڵ� �����в��Ҽ�ֵΪkey�Ľڵ㣬�ҵ��Ļ���ɾ���ýڵ㣻������ɾ���ڵ��ĸ��ڵ�(���Ҳ�ɾ�� �ⲿ�ӿ�)
Node* delete_bstree(BSTree tree, Type key);

//��ӡ������
void print_bstree(BSTree tree, Type key, int direction);

//���ٶ���������������㱬�ˣ����ݹ飩
void destroy_bstree(BSTree tree);

//ͳ�ƽڵ���
int count_bstree(BSTree tree);

//��α���
void levelOrderTraversal(BSTree root);

#endif
