//
// Created by tldlir001 on 2018/04/09.
//

#include "HuffmanTree.h"


tldlir001::HuffmanTree::HuffmanTree(std::priority_queue<HuffmanNode,std::vector,tldlir001::Compare> q)
{

    tldlir001::HuffmanTree::queue = q;
    char c = '#';

    while(q.size()>=2)
    {


        HuffmanNode h = queue.top(); //get top node
        q.pop(); // remove top node
        HuffmanNode h2 = queue.top(); //get top node
        q.pop(); // remove top node

        std::shared_ptr<HuffmanNode> pnode = std::make_shared<HuffmanNode> (HuffmanNode(c,h.frequency+h2.frequency));
        queue.push(*pnode);

        tldlir001::left =

    }

    std::shared_ptr<HuffmanNode> root = std::make_shared<HuffmanNode>(queue.top());
    queue.pop();

}

tldlir001::HuffmanTree::~HuffmanTree()
{

}

bool tldlir001::Compare::operator()(const tldlir001::HuffmanNode &a, const tldlir001::HuffmanNode &b)
{
    if (a.frequency < b.frequency) // or > if the algorithm requires that ordering
    {
        return true;
    }
    else
    {
        return false;
    }
}
