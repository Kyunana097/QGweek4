#include "min_heap.h"

// ������С��
MinHeap* create_min_heap(int capacity)
{
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// �ϸ�����
void heap_ify_up_min(MinHeap* heap, int index)
{
    int parent_index = (index - 1) / 2; // ���ڵ�����
    if (index > 0 && heap->array[index] < heap->array[parent_index]) // �ӽڵ�С�ڸ��ڵ�������ֵ������ʱ
    {
        int temp = heap->array[index];
        heap->array[index] = heap->array[parent_index];
        heap->array[parent_index] = temp;
        // �ݹ��ϸ�
        heap_ify_up_min(heap, parent_index);
    }
}

// �³�����
void heap_ify_down_min(MinHeap* heap, int index)
{
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    // ȷ����Сֵ��Ĭ�ϵ�ǰ�ڵ���С
    if (left_child < heap->size && heap->array[left_child] < heap->array[smallest])
    {
        smallest = left_child;
    }
    if (right_child < heap->size && heap->array[right_child] < heap->array[smallest])
    {
        smallest = right_child;
    }
    // ����Сֵ���ǵ�ǰ�ڵ�
    if (smallest != index)
    {
        // ������Сֵ�뵱ǰ�ڵ�
        int temp = heap->array[index];
        heap->array[index] = heap->array[smallest];
        heap->array[smallest] = temp;
        // �ݹ��³�
        heap_ify_down_min(heap, smallest);
    }
}

// ����ڵ�
void insert_min_heap(MinHeap* heap, int value)
{
    if (heap->size == heap->capacity)
    {
        printf("��������\n");
        return;
    }
    heap->array[heap->size] = value; // push
    heap->size++;                    // ��С+1
    heap_ify_up_min(heap, heap->size - 1); // �ϸ�ά��
}

// ɾ���Ѷ�
int delete_min_heap(MinHeap* heap)
{
    if (heap->size == 0)
    {
        printf("��Ϊ�նѣ�\n");
        return -1;
    }
    int root_value = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heap_ify_down_min(heap, 0); // �³�ά��
    return root_value;          // ���ظ��ڵ�ֵ
}

// ��ӡ��
void print_min_heap(MinHeap* heap)
{
    if (heap->size == 0)
    {
        printf("��Ϊ�գ�\n");
        return;
    }
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

// �ͷŶ�
void free_min_heap(MinHeap* heap)
{
    free(heap->array);
    free(heap);
}