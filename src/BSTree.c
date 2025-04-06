/**
 * 二叉搜索树(C语言): C语言实现的二叉搜索树。
 *
 * @author Kyunana
 * @date 2025/04/05
 */


#include "BSTree.h"


/*
 * 创建并返回二叉树结点。
 *
 * 参数说明：
 *     key 是键值。
 *     parent 是父结点。
 *     left 是左孩子。
 *     right 是右孩子。
 */
struct Node* create_bstree_node(Type key, Node* parent, Node* left, Node* right)
{
    Node* p;
    if ((p = (Node*)malloc(sizeof(Node))) == NULL) // 内存申请失败报错
    {
        printf("内存申请失败！");
        return NULL;
    }
    p->key = key;                           // 设置节点的键值
    p->left = left;                         // 设置左孩子指针
    p->right = right;                       // 设置右孩子指针
    p->parent = parent;                     // 设置父节点指针

    return p;
}

/*
 * 前序遍历"二叉树"（递归）
 */
void preorder_bstree(BSTree tree)
{
    if (tree != NULL)                       // 如果当前节点不为空
    {
        printf("%d ", tree->key);           // 先访问当前节点
        preorder_bstree(tree->left);        // 递归遍历左子树
        preorder_bstree(tree->right);       // 递归遍历右子树
    }
}

/*
 * 中序遍历"二叉树"（递归）
 */
void inorder_bstree(BSTree tree)
{
    if (tree != NULL)                       // 如果当前节点不为空
    {
        inorder_bstree(tree->left);         // 递归遍历左子树
        printf("%d ", tree->key);           // 访问当前节点
        inorder_bstree(tree->right);        // 递归遍历右子树
    }
}

/*
 * 后序遍历"二叉树"（递归）
 */
void postorder_bstree(BSTree tree)
{
    if (tree != NULL)                       // 如果当前节点不为空
    {
        postorder_bstree(tree->left);       // 递归遍历左子树
        postorder_bstree(tree->right);      // 递归遍历右子树
        printf("%d ", tree->key);           // 访问当前节点
    }
}

/*
 * 前序遍历"二叉树"（非递归）
 */
void iterative_preorder_bstree(BSTree tree)
{
    Node* stack[100];                       // 定义一个栈，用于存储节点
    int top = -1;                           // 栈顶指针初始化为-1
    Node* p = tree;                         // 从根节点开始遍历

    while (p != NULL || top != -1)          // 当前节点不为空或者栈不为空时继续循环
    {
        while (p != NULL)                   // 沿着左子树一直向下访问
        {
            printf("%d ", p->key);          // 访问当前节点
            stack[++top] = p;               // 当前节点入栈
            p = p->left;                    // 移动到左子节点
        }
        if (top != -1)                      // 如果栈不为空
        {
            p = stack[top--];               // 弹出栈顶元素
            p = p->right;                   // 移动到右子节点
        }
    }
}

/*
 * 中序遍历"二叉树"（非递归）
 */
void iterative_inorder_bstree(BSTree tree)
{
    Node* stack[100];                       // 定义一个栈，用于存储节点
    int top = -1;                           // 栈顶指针初始化为-1
    Node* p = tree;                         // 从根节点开始遍历

    while (p != NULL || top != -1)          // 当前节点不为空或者栈不为空时继续循环
    {
        while (p != NULL)                   // 沿着左子树一直向下访问
        {
            stack[++top] = p;               // 当前节点入栈
            p = p->left;                    // 移动到左子节点
        }
        if (top != -1)                      // 如果栈不为空
        {
            p = stack[top--];               // 弹出栈顶元素
            printf("%d ", p->key);          // 访问当前节点
            p = p->right;                   // 移动到右子节点
        }
    }
}

/*
 * 后序遍历"二叉树"（非递归）
 */
void iterative_postorder_bstree(BSTree tree)
{
    Node* stack1[100];                      // 定义两个栈，stack1用于存储遍历的节点
    Node* stack2[100];                      // stack2用于存储最终的输出顺序
    int top1 = -1, top2 = -1;               // 栈顶指针初始化为-1
    Node* p = tree;                         // 从根节点开始遍历

    while (p != NULL || top1 != -1)         // 当前节点不为空或者stack1不为空时继续循环
    {
        if (p != NULL)                      // 如果当前节点不为空
        {
            stack1[++top1] = p;             // 当前节点入stack1
            stack2[++top2] = p;             // 当前节点入stack2
            p = p->right;                   // 先将右子节点入栈
        }
        else                                // 如果当前节点为空
        {
            p = stack1[top1--];             // 弹出stack1的栈顶元素
            p = p->left;                    // 然后将左子节点入栈
        }
    }
    while (top2 != -1)                      // 将stack2中的元素依次弹出并访问
    {
        printf("%d ", stack2[top2--]->key);
    }
}

/*
 * 查找最小结点：返回tree为根结点的二叉树的最小结点。
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
 * 查找最大结点：返回tree为根结点的二叉树的最大结点。
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
 * 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
 */
Node* bstree_successor(Node* x)
{
    // 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
    if (x->right != NULL)
        return bstree_minimum(x->right);

    // 如果x没有右孩子。则x有以下两种可能：
    // (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
    // (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
    Node* y = x->parent;
    while ((y != NULL) && (x == y->right))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
 */
Node* bstree_predecessor(Node* x)
{
    // 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
    if (x->left != NULL)
        return bstree_maximum(x->left);

    // 如果x没有左孩子。则x有以下两种可能：
    // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
    // (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
    Node* y = x->parent;
    while ((y != NULL) && (x == y->left))
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
* (递归实现)查找"二叉树x"中键值为key的节点
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
 * (非递归实现)查找"二叉树x"中键值为key的节点
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
 * @brief 将节点插入到二叉树中
 * @param tree 二叉树的根节点
 * @param z 插入的节点
 * @return 根节点
 */
static Node* bstree_insert(BSTree tree, Node* z)
{
    Node* y = NULL;
    Node* x = tree;

    // 查找z的插入位置
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
 * @brief 将节点插入到二叉树中(此为对外接口)
 * @param tree 二叉树的根节点
 * @param z 插入的节点
 * @return 根节点
 */
Node* insert_bstree(BSTree tree, Type key)
{
    Node* z;    // 新建节点

    // 如果新建节点失败，则返回。
    if ((z = create_bstree_node(key, NULL, NULL, NULL)) == NULL)
        return tree;

    return bstree_insert(tree, z);
}

/**
 * @brief 删除结点(z)，并返回根节点
 * @param tree 二叉树的根结点
 * @param z 删除的结点
 * @return 根节点
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
 * @brief 删除结点(z)，并返回根节点(此为对外接口)
 * @param tree 二叉树的根结点
 * @param z 删除的结点
 * @return 根节点
 */
Node* delete_bstree(BSTree tree, Type key)
{
    Node* z, * node;

    if ((z = bstree_search(tree, key)) != NULL)
        tree = bstree_delete(tree, z);

    return tree;
}

/**
 * @brief 打印"二叉树"
 * @param tree 二叉树的节点
 * @param key 节点的键值 
 * @param direction 0，表示该节点是根节点;
 *                 -1，表示该节点是它的父结点的左孩子;
 *                  1，表示该节点是它的父结点的右孩子。
 */
void print_bstree(BSTree tree, Type key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)    // tree是根节点
            printf("%2d is root\n", tree->key);
        else                // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");

        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right, tree->key, 1);
    }
}

/**
 * 销毁二叉树
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
 * @brief 统计二叉搜索树中节点的数量
 * @param tree 二叉搜索树的根节点
 * @return 节点的数量
 */
int count_bstree(BSTree tree) 
{
    if (tree == NULL) 
    {
        return 0; // 如果当前节点为空，返回0
    }
    // 递归统计左子树和右子树的节点数量，并加上当前节点
    return 1 + count_bstree(tree->left) + count_bstree(tree->right);
}

// 队列节点（存储树节点指针）
typedef struct QueueNode
{
    BSTree treeNode;
    struct QueueNode* next;
} QueueNode;

// 队列结构
typedef struct
{
    QueueNode* front;
    QueueNode* rear;
} Queue;

// 初始化队列
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 入队
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

// 出队
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

// 检查队列是否为空
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

//层次遍历函数
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

    free(q);  // 释放队列内存
}