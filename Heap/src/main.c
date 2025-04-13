#define  _CRT_SECURE_NO_WARNINGS
#include "max_heap.h"
#include "min_heap.h"

// ȫ�ֱ��������ڴ洢��ǰѡ��Ķ�����
int current_choice = 0;
MaxHeap* max_heap = NULL;
MinHeap* min_heap = NULL;

// �������
void display_menu()
{
    printf("\n======= �����˵� =======\n");
    printf("1. ��������\n");
    printf("2. ������С��\n");
    printf("3. ����ڵ�\n");
    printf("4. ɾ���Ѷ�\n");
    printf("5. ��ӡ��\n");
    printf("6. �ͷŶ�\n");
    printf("���������ַ� �˳�����\n");
    printf("=======================\n");
    printf("����������ѡ��");
}

// �ͷŵ�ǰ��
void free_current_heap()
{
    if (current_choice == 1 && max_heap != NULL)
    {
        free_max_heap(max_heap);
        max_heap = NULL;
        printf("�������ͷţ�\n");
    }
    else if (current_choice == 2 && min_heap != NULL)
    {
        free_min_heap(min_heap);
        min_heap = NULL;
        printf("��С�����ͷţ�\n");
    }
    current_choice = 0;
}

int main()
{
    int choice, value, capacity;

    while (1)
    {
        choice = 0;
        display_menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // ��������
            printf("������ѵ�������");
            scanf("%d", &capacity);
            max_heap = create_max_heap(capacity);
            current_choice = 1;
            printf("�����Ѵ�����\n");
            break;

        case 2: // ������С��
            printf("������ѵ�������");
            scanf("%d", &capacity);
            min_heap = create_min_heap(capacity);
            current_choice = 2;
            printf("��С���Ѵ�����\n");
            break;

        case 3: // ����ڵ�
            if (current_choice == 0)
            {
                printf("���ȴ����ѣ�\n");
                break;
            }
            printf("������Ҫ�����ֵ��");
            scanf("%d", &value);
            if (current_choice == 1)
            {
                insert_max_heap(max_heap, value);
                printf("�����Ķѣ�");
                print_max_heap(max_heap);
            }
            else if (current_choice == 2)
            {
                insert_min_heap(min_heap, value);
                printf("�����Ķѣ�");
                print_min_heap(min_heap);
            }
            break;

        case 4: // ɾ���Ѷ�
            if (current_choice == 0)
            {
                printf("���ȴ����ѣ�\n");
                break;
            }
            if (current_choice == 1)
            {
                value = delete_max_heap(max_heap);
                if (value != -1)
                {
                    printf("ɾ���ĶѶ�ֵΪ��%d\n", value);
                    printf("ɾ����Ķѣ�");
                    print_max_heap(max_heap);
                }
            }
            else if (current_choice == 2)
            {
                value = delete_min_heap(min_heap);
                if (value != -1)
                {
                    printf("ɾ���ĶѶ�ֵΪ��%d\n", value);
                    printf("ɾ����Ķѣ�");
                    print_min_heap(min_heap);
                }
            }
            break;

        case 5: // ��ӡ��
            if (current_choice == 0)
            {
                printf("���ȴ����ѣ�\n");
                break;
            }
            if (current_choice == 1)
            {
                print_max_heap(max_heap);
            }
            else if (current_choice == 2)
            {
                print_min_heap(min_heap);
            }
            break;

        case 6: // �ͷŶ�
            free_current_heap();
            break;

        case 0: // �˳�����
            free_current_heap();
            printf("�����˳���\n");
            exit(0);
            break;

        default:
            printf("��Чѡ�����������룡\n");
            break;
        }
    }

    return 0;
}