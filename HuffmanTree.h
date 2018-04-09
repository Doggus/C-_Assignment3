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
        bool operator()(const HuffmanNode &a, const HuffmanNode &b);

    };

    class HuffmanTree
    {

    public:

        std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> queue;

        HuffmanTree( std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, Compare> q);

        ~HuffmanTree();

    };
}

#endif //HUFFMANPROJECT_HUFFMANTREE_H
