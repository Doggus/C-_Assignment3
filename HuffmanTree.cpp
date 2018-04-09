//
// Created by tldlir001 on 2018/04/09.
//

#include "HuffmanTree.h"


tldlir001::HuffmanTree::HuffmanTree(std::priority_queue<tldlir001::HuffmanNode,std::vector<tldlir001::HuffmanNode>,tldlir001::Compare> q)
{

    tldlir001::HuffmanTree::queue = q;
    char c = '#';

    while(q.size()>1)
    {

        tldlir001::HuffmanNode h = queue.top(); //get top node
        q.pop(); // remove top node
        tldlir001::HuffmanNode h2 = queue.top(); //get top node
        q.pop(); // remove top node

        int f = h.frequency + h2.frequency;
        tldlir001::HuffmanNode parentNode(c,f);

        parentNode.left = std::make_shared<tldlir001::HuffmanNode>(h);
        parentNode.right = std::make_shared<tldlir001::HuffmanNode>(h2);

        queue.push(parentNode); //push to top

    }

    root = std::make_shared<tldlir001::HuffmanNode>(queue.top());
    queue.pop();

}

tldlir001::HuffmanTree::~HuffmanTree()
{

}

tldlir001::Compare::Compare()
{
    //maybe
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
