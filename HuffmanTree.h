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

        Compare();

    };

    class HuffmanTree
    {

    public:

        std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, Compare> queue;
        std::shared_ptr<tldlir001::HuffmanNode> root; //root node

        HuffmanTree( std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, Compare> q);

        ~HuffmanTree();

    };
}

#endif //HUFFMANPROJECT_HUFFMANTREE_H
