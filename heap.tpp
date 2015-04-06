/*
 * heap.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: aaronc
 */


template <typename T>
inline void swap (T A[], int i, int j) {
    T temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


template <typename T, typename Comp>
void heap<T, Comp>::siftdown(int pos) {
    while (!isLeaf (pos)) {
        int j = leftchild (pos);
        int rc = rightchild (pos);
        if ((rc < n) && Comp::prior (Heap[rc], Heap[j])) {
            j = rc;
        }
        if (Comp::prior (Heap[pos], Heap[j])) {
            return;
        }
        swap (Heap, pos, j);
        pos = j;
    }
}


template <typename T, typename Comp>
heap<T, Comp>::heap(T* h, int num, int max) :
    Heap (h), maxsize (max), n (num) {
    buildHeap();
}

template <typename T, typename Comp>
int heap<T, Comp>::size() const {
    return n;
}

template <typename T, typename Comp>
bool heap<T, Comp>::isLeaf (int pos) const {
    return (pos >= n/2) && (pos < n);
}

template <typename T, typename Comp>
int heap<T, Comp>::leftchild (int pos) const {
    return 2*pos + 1;
}

template <typename T, typename Comp>
int heap<T, Comp>::rightchild (int pos) const {
    return 2*pos + 2;
}

template <typename T, typename Comp>
int heap<T, Comp>::parent (int pos) const {
    return (pos - 1) / 2;
}

template <typename T, typename Comp>
void heap<T, Comp>::buildHeap () {
    for (int i = (n / 2) - 1; i >= 0; --i) {
        siftdown (i);
    }
}

template <typename T, typename Comp>
void heap<T, Comp>::insert (const T& it) {
    if (n >= maxsize) {
        throw std::runtime_error ("Heap is full!");
    }
    int curr = n++;
    Heap[curr] = it;
    while ((curr != 0) && (Comp::prior(*Heap[curr], *Heap[parent(curr)]))) {
        swap (Heap, curr, parent(curr));
        curr = parent(curr);
    }
}

template <typename T, typename Comp>
T heap<T, Comp>::removefirst () {
    if (n <= 0) {
        throw std::runtime_error ("Heap is empty!");
    }
    swap (Heap, 0, --n);
    if (n != 0) {
        siftdown(0);
    }
    return Heap[n];
}

template <typename T, typename Comp>
T heap<T, Comp>::remove (int pos) {
    if ((pos < 0) || (pos >= n)) {
        std::ostringstream s;
        s << "Position '" << pos << "' is outside of range 0 - " << n << "!";
        throw std::runtime_error (s.str());
    }
    if (pos == (n-1)) {
        n--;
    } else {
        swap(Heap, pos, --n);
        while ((pos != 0) && (Comp::prior (*Heap[pos], *Heap[parent(pos)]))) {
            swap(Heap, pos, parent(pos));
            pos = parent(pos);
        }
        if (n != 0) {
            siftdown(pos);
        }
    }
    return Heap[n];
}
