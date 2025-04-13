#include "max_heap.h"

// ��������
MaxHeap* create_max_heap(int capacity)
{
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// �ϸ�����
void heap_ify_up_max(MaxHeap* heap, int index)
{
    int parent_index = (index - 1) / 2; // ���ڵ�����
    if (index > 0 && heap->array[index] > heap->array[parent_index]) // �ӽڵ���ڸ��ڵ�������ֵ������ʱ
    {
        int temp = heap->array[index];
        heap->array[index] = heap->array[parent_index];
        heap->array[parent_index] = temp;
        // �ݹ��ϸ�
        heap_ify_up_max(heap, parent_index);
    }
}

// �³�����
void heap_ify_down_max(MaxHeap* heap, int index)
{
    int largest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    // ȷ�����ֵ��Ĭ�ϵ�ǰ�ڵ����
    if (left_child < heap->size && heap->array[left_child] > heap->array[largest])
    {
        largest = left_child;
    }
    if (right_child < heap->size && heap->array[right_child] > heap->array[largest])
    {
        largest = right_child;
    }
    // �����ֵ���ǵ�ǰ�ڵ�
    if (largest != index)
    {
        // �������ֵ�뵱ǰ�ڵ�
        int temp = heap->array[index];
        heap->array[index] = heap->array[largest];
        heap->array[largest] = temp;
        // �ݹ��³�
        heap_ify_down_max(heap, largest);
    }
}

// ����ڵ�
void insert_max_heap(MaxHeap* heap, int value)
{
    if (heap->size == heap->capacity)
    {
        printf("��������\n");
        return;
    }
    heap->array[heap->size] = value; // push
    heap->size++;                    // ��С+1
    heap_ify_up_max(heap, heap->size - 1); // �ϸ�ά��
}

// ɾ���Ѷ�
int delete_max_heap(MaxHeap* heap)
{
    if (heap->size == 0)
    {
        printf("��Ϊ�նѣ�\n");
        return -1;
    }
    int root_value = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heap_ify_down_max(heap, 0); // �³�ά��
    return root_value;          // ���ظ��ڵ�ֵ
}

// ��ӡ��
void print_max_heap(MaxHeap* heap)
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
void free_max_heap(MaxHeap* heap)
{
    free(heap->array);
    free(heap);
}