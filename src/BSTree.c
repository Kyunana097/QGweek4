/**
 * ����������(C����): C����ʵ�ֵĶ�����������
 *
 * @author Kyunana
 * @date 2025/04/05
 */


#include "BSTree.h"


/*
 * ���������ض�������㡣
 *
 * ����˵����
 *     key �Ǽ�ֵ��
 *     parent �Ǹ���㡣
 *     left �����ӡ�
 *     right ���Һ��ӡ�
 */
struct Node* create_bstree_node(Type key, Node* parent, Node* left, Node* right)
{
    Node* p;
    if ((p = (Node*)malloc(sizeof(Node))) == NULL) // �ڴ�����ʧ�ܱ���
    {
        printf("�ڴ�����ʧ�ܣ�");
        return NULL;
    }
    p->key = key;                           // ���ýڵ�ļ�ֵ
    p->left = left;                         // ��������ָ��
    p->right = right;                       // �����Һ���ָ��
    p->parent = parent;                     // ���ø��ڵ�ָ��

    return p;
}

/*
 * ǰ�����"������"���ݹ飩
 */
void preorder_bstree(BSTree tree)
{
    if (tree != NULL)                       // �����ǰ�ڵ㲻Ϊ��
    {
        printf("%d ", tree->key);           // �ȷ��ʵ�ǰ�ڵ�
        preorder_bstree(tree->left);        // �ݹ����������
        preorder_bstree(tree->right);       // �ݹ����������
    }
}

/*
 * �������"������"���ݹ飩
 */
void inorder_bstree(BSTree tree)
{
    if (tree != NULL)                       // �����ǰ�ڵ㲻Ϊ��
    {
        inorder_bstree(tree->left);         // �ݹ����������
        printf("%d ", tree->key);           // ���ʵ�ǰ�ڵ�
        inorder_bstree(tree->right);        // �ݹ����������
    }
}

/*
 * �������"������"���ݹ飩
 */
void postorder_bstree(BSTree tree)
{
    if (tree != NULL)                       // �����ǰ�ڵ㲻Ϊ��
    {
        postorder_bstree(tree->left);       // �ݹ����������
        postorder_bstree(tree->right);      // �ݹ����������
        printf("%d ", tree->key);           // ���ʵ�ǰ�ڵ�
    }
}

/*
 * ǰ�����"������"���ǵݹ飩
 */
void iterative_preorder_bstree(BSTree tree)
{
    Node* stack[100];                       // ����һ��ջ�����ڴ洢�ڵ�
    int top = -1;                           // ջ��ָ���ʼ��Ϊ-1
    Node* p = tree;                         // �Ӹ��ڵ㿪ʼ����

    while (p != NULL || top != -1)          // ��ǰ�ڵ㲻Ϊ�ջ���ջ��Ϊ��ʱ����ѭ��
    {
        while (p != NULL)                   // ����������һֱ���·���
        {
            printf("%d ", p->key);          // ���ʵ�ǰ�ڵ�
            stack[++top] = p;               // ��ǰ�ڵ���ջ
            p = p->left;                    // �ƶ������ӽڵ�
        }
        if (top != -1)                      // ���ջ��Ϊ��
        {
            p = stack[top--];               // ����ջ��Ԫ��
            p = p->right;                   // �ƶ������ӽڵ�
        }
    }
}

/*
 * �������"������"���ǵݹ飩
 */
void iterative_inorder_bstree(BSTree tree)
{
    Node* stack[100];                       // ����һ��ջ�����ڴ洢�ڵ�
    int top = -1;                           // ջ��ָ���ʼ��Ϊ-1
    Node* p = tree;                         // �Ӹ��ڵ㿪ʼ����

    while (p != NULL || top != -1)          // ��ǰ�ڵ㲻Ϊ�ջ���ջ��Ϊ��ʱ����ѭ��
    {
        while (p != NULL)                   // ����������һֱ���·���
        {
            stack[++top] = p;               // ��ǰ�ڵ���ջ
            p = p->left;                    // �ƶ������ӽڵ�
        }
        if (top != -1)                      // ���ջ��Ϊ��
        {
            p = stack[top--];               // ����ջ��Ԫ��
            printf("%d ", p->key);          // ���ʵ�ǰ�ڵ�
            p = p->right;                   // �ƶ������ӽڵ�
        }
    }
}

/*
 * �������"������"���ǵݹ飩
 */
void iterative_postorder_bstree(BSTree tree)
{
    Node* stack1[100];                      // ��������ջ��stack1���ڴ洢�����Ľڵ�
    Node* stack2[100];                      // stack2���ڴ洢���յ����˳��
    int top1 = -1, top2 = -1;               // ջ��ָ���ʼ��Ϊ-1
    Node* p = tree;                         // �Ӹ��ڵ㿪ʼ����

    while (p != NULL || top1 != -1)         // ��ǰ�ڵ㲻Ϊ�ջ���stack1��Ϊ��ʱ����ѭ��
    {
        if (p != NULL)                      // �����ǰ�ڵ㲻Ϊ��
        {
            stack1[++top1] = p;             // ��ǰ�ڵ���stack1
            stack2[++top2] = p;             // ��ǰ�ڵ���stack2
            p = p->right;                   // �Ƚ����ӽڵ���ջ
        }
        else                                // �����ǰ�ڵ�Ϊ��
        {
            p = stack1[top1--];             // ����stack1��ջ��Ԫ��
            p = p->left;                    // Ȼ�����ӽڵ���ջ
        }
    }
    while (top2 != -1)                      // ��stack2�е�Ԫ�����ε���������
    {
        printf("%d ", stack2[top2--]->key);
    }
}

/*
 * ������С��㣺����treeΪ�����Ķ���������С��㡣
 */
Node* bstree_minimum(BSTree tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

/*
 * ��������㣺����treeΪ�����Ķ�����������㡣
 */
Node* bstree_maximum(BSTree tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}

/*
 * �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���"��
 */
Node* bstree_successor(Node* x)
{
    // ���x�����Һ��ӣ���"x�ĺ�̽��"Ϊ "�����Һ���Ϊ������������С���"��
    if (x->right != NULL)
        return bstree_minimum(x->right);

    // ���xû���Һ��ӡ���x���������ֿ��ܣ�
    // (01) x��"һ������"����"x�ĺ�̽��"Ϊ "���ĸ����"��
    // (02) x��"һ���Һ���"�������"x����͵ĸ���㣬���Ҹø����Ҫ��������"���ҵ������"��͵ĸ����"����"x�ĺ�̽��"��
    Node* y = x->parent;
    while ((y != NULL) && (x == y->right))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����"��
 */
Node* bstree_predecessor(Node* x)
{
    // ���x�������ӣ���"x��ǰ�����"Ϊ "��������Ϊ���������������"��
    if (x->left != NULL)
        return bstree_maximum(x->left);

    // ���xû�����ӡ���x���������ֿ��ܣ�
    // (01) x��"һ���Һ���"����"x��ǰ�����"Ϊ "���ĸ����"��
    // (01) x��"һ������"�������"x����͵ĸ���㣬���Ҹø����Ҫ�����Һ���"���ҵ������"��͵ĸ����"����"x��ǰ�����"��
    Node* y = x->parent;
    while ((y != NULL) && (x == y->left))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
* (�ݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
*/
Node* bstree_search(BSTree x, Type key)
{
    if (x == NULL || x->key == key)
        return x;

    if (key < x->key)
        return bstree_search(x->left, key);
    else
        return bstree_search(x->right, key);
}

/*
 * (�ǵݹ�ʵ��)����"������x"�м�ֵΪkey�Ľڵ�
 */
Node* iterative_bstree_search(BSTree x, Type key)
{
    while ((x != NULL) && (x->key != key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

/**
 * @brief ���ڵ���뵽��������
 * @param tree �������ĸ��ڵ�
 * @param z ����Ľڵ�
 * @return ���ڵ�
 */
static Node* bstree_insert(BSTree tree, Node* z)
{
    Node* y = NULL;
    Node* x = tree;

    // ����z�Ĳ���λ��
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    return tree;
}

/**
 * @brief ���ڵ���뵽��������(��Ϊ����ӿ�)
 * @param tree �������ĸ��ڵ�
 * @param z ����Ľڵ�
 * @return ���ڵ�
 */
Node* insert_bstree(BSTree tree, Type key)
{
    Node* z;    // �½��ڵ�

    // ����½��ڵ�ʧ�ܣ��򷵻ء�
    if ((z = create_bstree_node(key, NULL, NULL, NULL)) == NULL)
        return tree;

    return bstree_insert(tree, z);
}

/**
 * @brief ɾ�����(z)�������ظ��ڵ�
 * @param tree �������ĸ����
 * @param z ɾ���Ľ��
 * @return ���ڵ�
 */
static Node* bstree_delete(BSTree tree, Node* z)
{
    Node* x = NULL;
    Node* y = NULL;

    if ((z->left == NULL) || (z->right == NULL))
        y = z;
    else
        y = bstree_successor(z);

    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    if (x != NULL)
        x->parent = y->parent;

    if (y->parent == NULL)
        tree = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    if (y != z)
        z->key = y->key;

    if (y != NULL)
        free(y);

    return tree;
}

/**
 * @brief ɾ�����(z)�������ظ��ڵ�(��Ϊ����ӿ�)
 * @param tree �������ĸ����
 * @param z ɾ���Ľ��
 * @return ���ڵ�
 */
Node* delete_bstree(BSTree tree, Type key)
{
    Node* z, * node;

    if ((z = bstree_search(tree, key)) != NULL)
        tree = bstree_delete(tree, z);

    return tree;
}

/**
 * @brief ��ӡ"������"
 * @param tree �������Ľڵ�
 * @param key �ڵ�ļ�ֵ 
 * @param direction 0����ʾ�ýڵ��Ǹ��ڵ�;
 *                 -1����ʾ�ýڵ������ĸ���������;
 *                  1����ʾ�ýڵ������ĸ������Һ��ӡ�
 */
void print_bstree(BSTree tree, Type key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)    // tree�Ǹ��ڵ�
            printf("%2d is root\n", tree->key);
        else                // tree�Ƿ�֧�ڵ�
            printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");

        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right, tree->key, 1);
    }
}

/**
 * ���ٶ�����
 */
void destroy_bstree(BSTree tree)
{
    if (tree == NULL)
        return;

    if (tree->left != NULL)
        destroy_bstree(tree->left);
    if (tree->right != NULL)
        destroy_bstree(tree->right);

    free(tree);
}

/**
 * @brief ͳ�ƶ����������нڵ������
 * @param tree �����������ĸ��ڵ�
 * @return �ڵ������
 */
int count_bstree(BSTree tree) 
{
    if (tree == NULL) 
    {
        return 0; // �����ǰ�ڵ�Ϊ�գ�����0
    }
    // �ݹ�ͳ�����������������Ľڵ������������ϵ�ǰ�ڵ�
    return 1 + count_bstree(tree->left) + count_bstree(tree->right);
}

// ���нڵ㣨�洢���ڵ�ָ�룩
typedef struct QueueNode
{
    BSTree treeNode;
    struct QueueNode* next;
} QueueNode;

// ���нṹ
typedef struct
{
    QueueNode* front;
    QueueNode* rear;
} Queue;

// ��ʼ������
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// ���
void enqueue(Queue* q, BSTree treeNode)
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// ����
BSTree dequeue(Queue* q)
{
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    BSTree treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

// �������Ƿ�Ϊ��
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

//��α�������
void levelOrderTraversal(BSTree root) 
{
    if (root == NULL) return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) 
    {
        BSTree current = dequeue(q);
        printf("%d ", current->key);  

        if (current->left != NULL)
        {
            enqueue(q, current->left);
        }
        if (current->right != NULL) 
        {
            enqueue(q, current->right);
        }
    }

    free(q);  // �ͷŶ����ڴ�
}