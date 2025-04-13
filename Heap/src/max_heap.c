#include "max_heap.h"

// 创建最大堆
MaxHeap* create_max_heap(int capacity)
{
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// 上浮操作
void heap_ify_up_max(MaxHeap* heap, int index)
{
    int parent_index = (index - 1) / 2; // 父节点索引
    if (index > 0 && heap->array[index] > heap->array[parent_index]) // 子节点大于父节点且索引值大于零时
    {
        int temp = heap->array[index];
        heap->array[index] = heap->array[parent_index];
        heap->array[parent_index] = temp;
        // 递归上浮
        heap_ify_up_max(heap, parent_index);
    }
}

// 下沉操作
void heap_ify_down_max(MaxHeap* heap, int index)
{
    int largest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    // 确定最大值，默认当前节点最大
    if (left_child < heap->size && heap->array[left_child] > heap->array[largest])
    {
        largest = left_child;
    }
    if (right_child < heap->size && heap->array[right_child] > heap->array[largest])
    {
        largest = right_child;
    }
    // 若最大值不是当前节点
    if (largest != index)
    {
        // 交换最大值与当前节点
        int temp = heap->array[index];
        heap->array[index] = heap->array[largest];
        heap->array[largest] = temp;
        // 递归下沉
        heap_ify_down_max(heap, largest);
    }
}

// 插入节点
void insert_max_heap(MaxHeap* heap, int value)
{
    if (heap->size == heap->capacity)
    {
        printf("堆已满！\n");
        return;
    }
    heap->array[heap->size] = value; // push
    heap->size++;                    // 大小+1
    heap_ify_up_max(heap, heap->size - 1); // 上浮维护
}

// 删除堆顶
int delete_max_heap(MaxHeap* heap)
{
    if (heap->size == 0)
    {
        printf("堆为空堆！\n");
        return -1;
    }
    int root_value = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heap_ify_down_max(heap, 0); // 下沉维护
    return root_value;          // 返回根节点值
}

// 打印堆
void print_max_heap(MaxHeap* heap)
{
    if (heap->size == 0)
    {
        printf("堆为空！\n");
        return;
    }
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

// 释放堆
void free_max_heap(MaxHeap* heap)
{
    free(heap->array);
    free(heap);
}