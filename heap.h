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
inline void swap (T A[], int i, int j);

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

    void siftdown (int pos);

public:
    heap (T* h, int num, int max);
    int size() const;
    bool isLeaf (int pos) const;
    int leftchild (int pos) const;
    int rightchild (int pos) const;
    int parent (int pos) const;

    void buildHeap ();

    void insert (const T& it);

    T removefirst ();

    T remove (int pos);
};

#include "heap.tpp"

#endif
