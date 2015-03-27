/*
 * main.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: aaronc
 */

#include "Huffman.h"
#include <iostream>

const int ARRAYSIZE = 20;

int main(int argc, char **argv) {

    HuffTree<char>* test[8];
    test[0] = new HuffTree<char> ('z', 2);
    test[1] = new HuffTree<char> ('k', 7);
    test[2] = new HuffTree<char> ('m', 24);
    test[3] = new HuffTree<char> ('c', 32);
    test[4] = new HuffTree<char> ('u', 37);
    test[5] = new HuffTree<char> ('d', 42);
    test[6] = new HuffTree<char> ('l', 42);
    test[7] = new HuffTree<char> ('e', 120);

    HuffTree<char>* final = buildHuff (test, 8);


    return 0;
}


