/*
 * heap.h
 *
 *  Created on: Mar 23, 2015
 *      Author: aaronc
 */

#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <sstream>

template <typename T>
inline void swap (T A[], int i, int j) {
    T temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

class max {
public:
    template <typename T>
    static bool prior (T a, T b) {
        return a > b;
    }
};

class min {
public:
    template <typename T>
    static bool prior (T a, T b) {
        return a < b;
    }
};

template <typename T, typename Comp>
class heap {
private:
    T* Heap;
    int maxsize;
    int n;

    void siftdown (int pos) {
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

public:
    heap (T* h, int num, int max) :
        Heap (h), maxsize (max), n (num) {
        buildHeap();
    }
    int size() const {
        return n;
    }
    bool isLeaf (int pos) const {
        return (pos >= n/2) && (pos < n);
    }
    int leftchild (int pos) const {
        return 2*pos + 1;
    }
    int rightchild (int pos) const {
        return 2*pos + 2;
    }
    int parent (int pos) const {
        return (pos - 1) / 2;
    }

    void buildHeap () {
        for (int i = (n / 2) - 1; i >= 0; --i) {
            siftdown (i);
        }
    }

    void insert (const T& it) {
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

    T removefirst () {
        if (n <= 0) {
            throw std::runtime_error ("Heap is empty!");
        }
        swap (Heap, 0, --n);
        if (n != 0) {
            siftdown(0);
        }
        return Heap[n];
    }

    T remove (int pos) {
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
};


#endif
