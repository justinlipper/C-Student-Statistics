

#ifndef PriorityQueue_h
#define PriorityQueue_h
#include "Heap.h"

template<typename T>
class PriorityQueue
{
public:
    PriorityQueue();
    void enqueue(T element);
    T dequeue() throw (runtime_error);
    int getSize() const;
    
private:
    Heap<T> heap;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
}

template<typename T>
void PriorityQueue<T>::enqueue(T element)
{
    heap.add(element);
}

template<typename T>
T PriorityQueue<T>::dequeue() throw (runtime_error)
{
    return heap.remove();
}

template<typename T>
int PriorityQueue<T>::getSize() const
{
    return heap.getSize();
}

#endif /* PriorityQueue_h */
