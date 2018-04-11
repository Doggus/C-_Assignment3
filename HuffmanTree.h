//
// Created by tldlir001 on 2018/04/09.
//

#ifndef HUFFMANPROJECT_HUFFMANTREE_H
#define HUFFMANPROJECT_HUFFMANTREE_H

#include "HuffmanNode.h"
#include <queue>


namespace tldlir001
{
    class Compare
    {

    public:

        bool operator()(const tldlir001::HuffmanNode &a, const tldlir001::HuffmanNode &b); //used to structure order of priority queue

    };

    class HuffmanTree
    {

    public:


        std::shared_ptr<tldlir001::HuffmanNode> root; //root node

        HuffmanTree( std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, Compare> q);

        HuffmanTree(const HuffmanTree &tree); //copy constructor

        HuffmanTree(const HuffmanTree &&tree); //move constructor

        HuffmanTree(); // default constructor

        ~HuffmanTree(); //destructor

    };
}

#endif //HUFFMANPROJECT_HUFFMANTREE_H
