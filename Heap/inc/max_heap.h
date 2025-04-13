#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>

// 最大堆结构体定义
typedef struct MaxHeapStruct
{
    int* array;     // 堆元素数组
    int capacity;   // 堆容量
    int size;       // 堆当前大小
} MaxHeap;

// 创建最大堆
MaxHeap* create_max_heap(int capacity);

// 上浮操作
void heap_ify_up_max(MaxHeap* heap, int index);

// 下沉操作
void heap_ify_down_max(MaxHeap* heap, int index);

// 插入节点
void insert_max_heap(MaxHeap* heap, int value);

// 删除堆顶
int delete_max_heap(MaxHeap* heap);

// 打印堆
void print_max_heap(MaxHeap* heap);

// 释放堆
void free_max_heap(MaxHeap* heap);

#endif // MAX_HEAP_H