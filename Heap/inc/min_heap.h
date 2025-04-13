#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>

// ��С�ѽṹ�嶨��
typedef struct MinHeapStruct
{
    int* array;     // ��Ԫ������
    int capacity;   // ������
    int size;       // �ѵ�ǰ��С
} MinHeap;

// ������С��
MinHeap* create_min_heap(int capacity);

// �ϸ�����
void heap_ify_up_min(MinHeap* heap, int index);

// �³�����
void heap_ify_down_min(MinHeap* heap, int index);

// ����ڵ�
void insert_min_heap(MinHeap* heap, int value);

// ɾ���Ѷ�
int delete_min_heap(MinHeap* heap);

// ��ӡ��
void print_min_heap(MinHeap* heap);

// �ͷŶ�
void free_min_heap(MinHeap* heap);

#endif // MIN_HEAP_H