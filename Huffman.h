/*
 * Huffman.h
 *
 *  Created on: Mar 23, 2015
 *      Author: aaronc
 */

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "heap.h"
#include <iostream>

template <typename T>
class HuffNode {
public:
    virtual ~HuffNode () {};
    virtual int weight () const = 0;
    virtual bool isLeaf () = 0;
    bool operator< (const HuffNode& rhs) const;
    bool operator> (const HuffNode& rhs) const;
};

template <typename T>
class LeafNode : public HuffNode<T> {
private:
    T it;
    int wgt;

public:
    LeafNode (const T& val, int freq);
    ~LeafNode () {}

    int weight () const;
    T val () const;
    bool isLeaf ();
};

template <typename T>
class IntlNode : public HuffNode<T> {
private:
    HuffNode<T>* lc;
    HuffNode<T>* rc;
    int wgt;

public:
    IntlNode (HuffNode<T>* l, HuffNode<T>* r);
    ~IntlNode () {
        std::cout << "delete left child\n";
        std::cout << "delete right child\n";
    }

    int weight () const;
    bool isLeaf ();
    HuffNode<T>* left () const;
    void setLeft (HuffNode<T>* b);
    HuffNode<T>* right () const;
    void setRight (HuffNode<T>* b);
};

template <typename T>
class HuffTree {
private:
    HuffNode<T>* Root;
public:
    HuffTree (const T& val, int freq);
    HuffTree (HuffTree<T>* l, HuffTree<T>* r);
    ~HuffTree ();
    HuffNode<T>* root ();
    int weight ();
    bool operator> (HuffTree& rhs);
    bool operator< (HuffTree& rhs);
};

HuffTree<char>* buildHuff (HuffTree<char>** TreeArray, int count);


#include "Huffman.tpp"

#endif
