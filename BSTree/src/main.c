#define _CRT_SECURE_NO_WARNINGS
#include "BSTree.h"

static int arr[] = { 1,5,4,3,2,6 };
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int choice, value;
    BSTree root = NULL;

    printf("��ʼ���� == �������: ");
    for (int i = 0; i < TBL_SIZE(arr); i++)
    {
        printf("%d ", arr[i]);
        root = insert_bstree(root, arr[i]);
    }
    printf("\n");

    while (1) 
    {
        choice = 0;
        printf("\n======= �����˵� =======\n");
        printf("1. �����в���ڵ�\n");
        printf("2. ɾ�����еĽڵ�\n");
        printf("3. �������еĽڵ�\n");
        printf("4. ͳ�����нڵ�����\n");
        printf("5. ��ӡ����ǰ�����\n");
        printf("6. ��ӡ�����������\n");
        printf("7. ��ӡ���ĺ������\n");
        printf("8. ��ӡ���Ĳ�α���\n");
        printf("9. �ж����Ƿ�Ϊ��\n");
        printf("10. �����\n");
        printf("0. �˳�����\n");
        printf("======= �����˵� =======\n");
        printf("\n����������ѡ��");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // �����в���ڵ�
            printf("������Ҫ�����ֵ��");
            scanf("%d", &value);
            root = insert_bstree(root, value);
            printf("��������������");
            inorder_bstree(root);
            printf("\n");
            break;

        case 2: // ɾ�����еĽڵ�
            if (root == NULL)
            {
                printf("��Ϊ�ա�\n");
                continue;
            }
            printf("������Ҫɾ����ֵ��");
            scanf("%d", &value);
            if (bstree_search(root, value) == NULL)
            {
                printf("δ��ѯ���ýڵ�\n");
                continue;
            }
            root = delete_bstree(root, value);
            printf("ɾ�������������");
            inorder_bstree(root);
            printf("\n");
            break;

        case 3: // �������еĽڵ�
            if (root == NULL)
            {
                printf("��Ϊ�ա�\n");
                continue;
            }
            printf("������Ҫ���ҵ�ֵ��");
            scanf("%d", &value);
            if (bstree_search(root, value) != NULL)
                printf("�ڵ� %d ���������С�\n", value);
            else
                printf("�ڵ� %d �����������С�\n", value);
            break;

        case 4: // ͳ�����нڵ�����
            printf("���нڵ�����Ϊ��%d\n", count_bstree(root));
            break;

        case 5: // ��ӡ����ǰ�����
            if (root == NULL)
            {
                printf("��Ϊ�ա�\n");
                continue;
            }
            printf("ǰ�������");
            preorder_bstree(root);
            printf("\n");
            break;

        case 6: // ��ӡ�����������
            if (root == NULL)
            {
                printf("��Ϊ�ա�\n");
                continue;
            }
            printf("���������");
            inorder_bstree(root);
            printf("\n");
            break;

        case 7: // ��ӡ���ĺ������
            if (root == NULL)
            {
                printf("��Ϊ�ա�\n");
                continue;
            }
            printf("���������");
            postorder_bstree(root);
            printf("\n");
            break;

        case 8: // ��ӡ���Ĳ�α���
            if (root == NULL) {
                printf("��Ϊ�ա�\n");
            }
            else {
                printf("��α�����");
                levelOrderTraversal(root);
                printf("\n");
            }
            break;

        case 9: // �ж����Ƿ�Ϊ��
            if (root == NULL)
                printf("��Ϊ�ա�\n");
            else
                printf("����Ϊ�ա�\n");
            break;

        case 10: // �����
            destroy_bstree(root);
            root = NULL;
            printf("������ա�\n");
            break;

        case 0: // �˳�����
            printf("�˳�����\n");
            destroy_bstree(root); // ���ٶ�����
            return 0;

        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    }
    return 0;
}