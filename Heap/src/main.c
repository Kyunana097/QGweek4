#define  _CRT_SECURE_NO_WARNINGS
#include "max_heap.h"
#include "min_heap.h"

// 全局变量，用于存储当前选择的堆类型
int current_choice = 0;
MaxHeap* max_heap = NULL;
MinHeap* min_heap = NULL;

// 操作面板
void display_menu()
{
    printf("\n======= 操作菜单 =======\n");
    printf("1. 创建最大堆\n");
    printf("2. 创建最小堆\n");
    printf("3. 插入节点\n");
    printf("4. 删除堆顶\n");
    printf("5. 打印堆\n");
    printf("6. 释放堆\n");
    printf("其他任意字符 退出程序\n");
    printf("=======================\n");
    printf("请输入您的选择：");
}

// 释放当前堆
void free_current_heap()
{
    if (current_choice == 1 && max_heap != NULL)
    {
        free_max_heap(max_heap);
        max_heap = NULL;
        printf("最大堆已释放！\n");
    }
    else if (current_choice == 2 && min_heap != NULL)
    {
        free_min_heap(min_heap);
        min_heap = NULL;
        printf("最小堆已释放！\n");
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
        case 1: // 创建最大堆
            printf("请输入堆的容量：");
            scanf("%d", &capacity);
            max_heap = create_max_heap(capacity);
            current_choice = 1;
            printf("最大堆已创建！\n");
            break;

        case 2: // 创建最小堆
            printf("请输入堆的容量：");
            scanf("%d", &capacity);
            min_heap = create_min_heap(capacity);
            current_choice = 2;
            printf("最小堆已创建！\n");
            break;

        case 3: // 插入节点
            if (current_choice == 0)
            {
                printf("请先创建堆！\n");
                break;
            }
            printf("请输入要插入的值：");
            scanf("%d", &value);
            if (current_choice == 1)
            {
                insert_max_heap(max_heap, value);
                printf("插入后的堆：");
                print_max_heap(max_heap);
            }
            else if (current_choice == 2)
            {
                insert_min_heap(min_heap, value);
                printf("插入后的堆：");
                print_min_heap(min_heap);
            }
            break;

        case 4: // 删除堆顶
            if (current_choice == 0)
            {
                printf("请先创建堆！\n");
                break;
            }
            if (current_choice == 1)
            {
                value = delete_max_heap(max_heap);
                if (value != -1)
                {
                    printf("删除的堆顶值为：%d\n", value);
                    printf("删除后的堆：");
                    print_max_heap(max_heap);
                }
            }
            else if (current_choice == 2)
            {
                value = delete_min_heap(min_heap);
                if (value != -1)
                {
                    printf("删除的堆顶值为：%d\n", value);
                    printf("删除后的堆：");
                    print_min_heap(min_heap);
                }
            }
            break;

        case 5: // 打印堆
            if (current_choice == 0)
            {
                printf("请先创建堆！\n");
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

        case 6: // 释放堆
            free_current_heap();
            break;

        case 0: // 退出程序
            free_current_heap();
            printf("程序退出！\n");
            exit(0);
            break;

        default:
            printf("无效选择，请重新输入！\n");
            break;
        }
    }

    return 0;
}