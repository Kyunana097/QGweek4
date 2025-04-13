#include "min_heap.h"

// 创建最小堆
MinHeap* create_min_heap(int capacity)
{
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// 上浮操作
void heap_ify_up_min(MinHeap* heap, int index)
{
    int parent_index = (index - 1) / 2; // 父节点索引
    if (index > 0 && heap->array[index] < heap->array[parent_index]) // 子节点小于父节点且索引值大于零时
    {
        int temp = heap->array[index];
        heap->array[index] = heap->array[parent_index];
        heap->array[parent_index] = temp;
        // 递归上浮
        heap_ify_up_min(heap, parent_index);
    }
}

// 下沉操作
void heap_ify_down_min(MinHeap* heap, int index)
{
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    // 确定最小值，默认当前节点最小
    if (left_child < heap->size && heap->array[left_child] < heap->array[smallest])
    {
        smallest = left_child;
    }
    if (right_child < heap->size && heap->array[right_child] < heap->array[smallest])
    {
        smallest = right_child;
    }
    // 若最小值不是当前节点
    if (smallest != index)
    {
        // 交换最小值与当前节点
        int temp = heap->array[index];
        heap->array[index] = heap->array[smallest];
        heap->array[smallest] = temp;
        // 递归下沉
        heap_ify_down_min(heap, smallest);
    }
}

// 插入节点
void insert_min_heap(MinHeap* heap, int value)
{
    if (heap->size == heap->capacity)
    {
        printf("堆已满！\n");
        return;
    }
    heap->array[heap->size] = value; // push
    heap->size++;                    // 大小+1
    heap_ify_up_min(heap, heap->size - 1); // 上浮维护
}

// 删除堆顶
int delete_min_heap(MinHeap* heap)
{
    if (heap->size == 0)
    {
        printf("堆为空堆！\n");
        return -1;
    }
    int root_value = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heap_ify_down_min(heap, 0); // 下沉维护
    return root_value;          // 返回根节点值
}

// 打印堆
void print_min_heap(MinHeap* heap)
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
void free_min_heap(MinHeap* heap)
{
    free(heap->array);
    free(heap);
}