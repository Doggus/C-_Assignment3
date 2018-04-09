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
        bool operator()(const tldlir001::HuffmanNode &a, const tldlir001::HuffmanNode &b);

    };

    class HuffmanTree
    {

    public:

        std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, Compare> queue;

        HuffmanTree( std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, Compare> q);

        ~HuffmanTree();

    };
}

#endif //HUFFMANPROJECT_HUFFMANTREE_H
