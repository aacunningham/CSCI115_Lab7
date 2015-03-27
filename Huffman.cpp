/*
 * Huffman.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: aaronc
 */


template <typename T>
bool HuffNode<T>::operator< (const HuffNode& rhs) const {
    return (this->weight() < rhs.weight());
}

template <typename T>
bool HuffNode<T>::operator> (const HuffNode& rhs) const {
    return (this->weight() > rhs.weight());
}


template <typename T>
LeafNode<T>::LeafNode (const T& val, int freq) :
    it (val), wgt (freq) {}

template <typename T>
int LeafNode<T>::weight () const {
    return wgt;
}

template <typename T>
T LeafNode<T>::val () const {
    return it;
}

template <typename T>
bool LeafNode<T>::isLeaf () {
    return true;
}


template <typename T>
IntlNode<T>::IntlNode (HuffNode<T>* l, HuffNode<T>* r) {
    wgt = l->weight() + r->weight();
    lc = l;
    rc = r;
}

template <typename T>
int IntlNode<T>::weight () const {
    return wgt;
}

template <typename T>
bool IntlNode<T>::isLeaf () {
    return false;
}

template <typename T>
HuffNode<T>* IntlNode<T>::left () const {
    return lc;
}

template <typename T>
void IntlNode<T>::setLeft (HuffNode<T>* b) {
    lc = (HuffNode<T>*)b;
}

template <typename T>
HuffNode<T>* IntlNode<T>::right () const {
    return lc;
}

template <typename T>
void IntlNode<T>::setRight (HuffNode<T>* b) {
    rc = (HuffNode<T>*)b;
}


template <typename T>
HuffTree<T>::HuffTree (const T& val, int freq) {
    Root = new LeafNode<T> (val, freq);
}

template <typename T>
HuffTree<T>::HuffTree (HuffTree<T>* l, HuffTree<T>* r) {
    Root = new IntlNode<T> (l->root(), r->root());
}

template <typename T>
HuffTree<T>::~HuffTree () {
    std::cout << "delete huff root\n";
}

template <typename T>
HuffNode<T>* HuffTree<T>::root () {
    return Root;
}

template <typename T>
int HuffTree<T>::weight () {
    return Root->weight();
}

template <typename T>
bool HuffTree<T>::operator> (HuffTree& rhs) {
    return this->root()->weight() > rhs.root()->weight();
}

template <typename T>
bool HuffTree<T>::operator< (HuffTree& rhs) {
    return this->root()->weight() < rhs.root()->weight();
}


HuffTree<char>* buildHuff (HuffTree<char>** TreeArray, int count) {
    heap<HuffTree<char>*, min>* forest = new heap<HuffTree<char>*, min> (TreeArray, count, count);
    HuffTree<char> *temp1, *temp2, *temp3 = 0;
    while (forest->size() > 1) {
        temp1 = forest->removefirst();
        temp2 = forest->removefirst();
        temp3 = new HuffTree<char> (temp1, temp2);
        forest->insert(temp3);
        delete temp1;
        delete temp2;
    }
    return temp3;
}

