#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>

// 最小堆结构体定义
typedef struct MinHeapStruct
{
    int* array;     // 堆元素数组
    int capacity;   // 堆容量
    int size;       // 堆当前大小
} MinHeap;

// 创建最小堆
MinHeap* create_min_heap(int capacity);

// 上浮操作
void heap_ify_up_min(MinHeap* heap, int index);

// 下沉操作
void heap_ify_down_min(MinHeap* heap, int index);

// 插入节点
void insert_min_heap(MinHeap* heap, int value);

// 删除堆顶
int delete_min_heap(MinHeap* heap);

// 打印堆
void print_min_heap(MinHeap* heap);

// 释放堆
void free_min_heap(MinHeap* heap);

#endif // MIN_HEAP_H