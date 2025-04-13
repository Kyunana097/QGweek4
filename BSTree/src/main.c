#define _CRT_SECURE_NO_WARNINGS
#include "BSTree.h"

static int arr[] = { 1,5,4,3,2,6 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int choice, value;
    BSTree root = NULL;

    printf("初始数组 == 依次添加: ");
    for (int i = 0; i < TBL_SIZE(arr); i++)
    {
        printf("%d ", arr[i]);
        root = insert_bstree(root, arr[i]);
    }
    printf("\n");

    while (1) 
    {
        choice = 0;
        printf("\n======= 操作菜单 =======\n");
        printf("1. 在树中插入节点\n");
        printf("2. 删除树中的节点\n");
        printf("3. 查找树中的节点\n");
        printf("4. 统计树中节点数量\n");
        printf("5. 打印树的前序遍历\n");
        printf("6. 打印树的中序遍历\n");
        printf("7. 打印树的后序遍历\n");
        printf("8. 打印树的层次遍历\n");
        printf("9. 判断树是否为空\n");
        printf("10. 清空树\n");
        printf("0. 退出程序\n");
        printf("======= 操作菜单 =======\n");
        printf("\n请输入您的选择：");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // 在树中插入节点
            printf("请输入要插入的值：");
            scanf("%d", &value);
            root = insert_bstree(root, value);
            printf("插入后中序遍历：");
            inorder_bstree(root);
            printf("\n");
            break;

        case 2: // 删除树中的节点
            if (root == NULL)
            {
                printf("树为空。\n");
                continue;
            }
            printf("请输入要删除的值：");
            scanf("%d", &value);
            if (bstree_search(root, value) == NULL)
            {
                printf("未查询到该节点\n");
                continue;
            }
            root = delete_bstree(root, value);
            printf("删除后中序遍历：");
            inorder_bstree(root);
            printf("\n");
            break;

        case 3: // 查找树中的节点
            if (root == NULL)
            {
                printf("树为空。\n");
                continue;
            }
            printf("请输入要查找的值：");
            scanf("%d", &value);
            if (bstree_search(root, value) != NULL)
                printf("节点 %d 存在于树中。\n", value);
            else
                printf("节点 %d 不存在于树中。\n", value);
            break;

        case 4: // 统计树中节点数量
            printf("树中节点数量为：%d\n", count_bstree(root));
            break;

        case 5: // 打印树的前序遍历
            if (root == NULL)
            {
                printf("树为空。\n");
                continue;
            }
            printf("前序遍历：");
            preorder_bstree(root);
            printf("\n");
            break;

        case 6: // 打印树的中序遍历
            if (root == NULL)
            {
                printf("树为空。\n");
                continue;
            }
            printf("中序遍历：");
            inorder_bstree(root);
            printf("\n");
            break;

        case 7: // 打印树的后序遍历
            if (root == NULL)
            {
                printf("树为空。\n");
                continue;
            }
            printf("后序遍历：");
            postorder_bstree(root);
            printf("\n");
            break;

        case 8: // 打印树的层次遍历
            if (root == NULL) {
                printf("树为空。\n");
            }
            else {
                printf("层次遍历：");
                levelOrderTraversal(root);
                printf("\n");
            }
            break;

        case 9: // 判断树是否为空
            if (root == NULL)
                printf("树为空。\n");
            else
                printf("树不为空。\n");
            break;

        case 10: // 清空树
            destroy_bstree(root);
            root = NULL;
            printf("树已清空。\n");
            break;

        case 0: // 退出程序
            printf("退出程序。\n");
            destroy_bstree(root); // 销毁二叉树
            return 0;

        default:
            printf("无效的选择，请重新输入。\n");
        }
    }
    return 0;
}