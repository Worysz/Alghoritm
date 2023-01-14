#include <iostream>
#ifndef _heap
#define _heap 1

using namespace std;

template <typename T>
class heap
{
    T* wsk;
    int size;
    int capacity;
    void heap_up(int);
    void heap_down(int);
    void build_heap_top_down();
    void build_heap_bottom_up();
public:
    heap();
    heap(T*, int, bool);
    void sort();
    void push_h(T);
    void remove_h();
    void show();
    T pol();

};
template <typename T>
void heap<T>::build_heap_top_down() {
    for (int i = 1; i < size; i++) {
        heap_up(i);
    }
}

template <typename T>
void heap<T>::build_heap_bottom_up() {
    for (int i = (size - 2) / 2; i >= 0; i--) {
        heap_down(i);
    }
}
template <typename T>
heap<T>::heap()
{
    size = 0;
    capacity = 1;
    wsk = new T[capacity];
}
template <typename T>
heap<T>::heap(T* array, int s, bool top_down)
{
    size = s;
    wsk = array;
    if (top_down) {
        build_heap_top_down();
    }
    else {
        build_heap_bottom_up();
    }
}
template <typename T>
void heap<T>::sort() {
    int temp_size = size;
    while (size > 1) {
        swap(wsk[0], wsk[size - 1]);
        size--;
        heap_down(0);
    }
    size = temp_size;
}

template <typename T>
void heap<T>::heap_up(int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && wsk[index] > wsk[parent])
    {
        swap(wsk[index], wsk[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

template <typename T>
void heap<T>::heap_down(int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && wsk[left] > wsk[largest])
    {
        largest = left;
    }
    if (right < size && wsk[right] > wsk[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(wsk[index], wsk[largest]);
        heap_down(largest);
    }
}


template <typename T>
void heap<T>::push_h(T value)
{
    if (size == capacity)
    {
        capacity *= 2;
        T* temp = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = wsk[i];
        }
        wsk = temp;
    }
    wsk[size] = value;
    size++;
    heap_up(size - 1);

}

template <typename T>
void heap<T>::remove_h()
{
    if (size == 0)
    {
        cout << "Cannot remove the heap cause it's empty";
    }
    else
    {
        wsk[0] = wsk[size - 1];
        size--;
        heap_down(0);
    }
}

template <typename T>
T heap<T>::pol()
{
    if (size == 0)
    {
        cout << "Heap is empty" << endl;
    }
    else
    {
        return wsk[0];
    }
}
template <typename T>
void heap<T>::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << wsk[i] << "\t";
    }
}
#endif