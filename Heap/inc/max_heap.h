#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>

// ���ѽṹ�嶨��
typedef struct MaxHeapStruct
{
    int* array;     // ��Ԫ������
    int capacity;   // ������
    int size;       // �ѵ�ǰ��С
} MaxHeap;

// ��������
MaxHeap* create_max_heap(int capacity);

// �ϸ�����
void heap_ify_up_max(MaxHeap* heap, int index);

// �³�����
void heap_ify_down_max(MaxHeap* heap, int index);

// ����ڵ�
void insert_max_heap(MaxHeap* heap, int value);

// ɾ���Ѷ�
int delete_max_heap(MaxHeap* heap);

// ��ӡ��
void print_max_heap(MaxHeap* heap);

// �ͷŶ�
void free_max_heap(MaxHeap* heap);

#endif // MAX_HEAP_H