//
// Created by tldlir001 on 2018/04/09.
//

#include <iostream>
#include "HuffmanTree.h"


tldlir001::HuffmanTree::HuffmanTree(std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, tldlir001::Compare> q)
{

    char c = '#';

    while (q.size() > 1)
    {

        tldlir001::HuffmanNode h = q.top(); //get top node
        q.pop(); // remove top node
        tldlir001::HuffmanNode h2 = q.top(); //get top node
        q.pop(); // remove top node

        int f = h.frequency + h2.frequency;
        std::cout << f << std::endl;
        tldlir001::HuffmanNode parentNode(c, f);

        parentNode.left = std::make_shared<tldlir001::HuffmanNode>(h);
        parentNode.right = std::make_shared<tldlir001::HuffmanNode>(h2);

        q.push(parentNode); //push to top

    }
    root = std::make_shared<tldlir001::HuffmanNode>(q.top());

    std::cout << "ROOT: " << root->frequency << std::endl;
    q.pop();

}

tldlir001::HuffmanTree::~HuffmanTree()
{

}

tldlir001::Compare::Compare()
{
    //Default constructor
}


bool tldlir001::Compare::operator()(const tldlir001::HuffmanNode &a, const tldlir001::HuffmanNode &b)
{
    if (a.frequency > b.frequency) // or > if the algorithm requires that ordering
    {
        return true;
    }
    else
    {
        return false;
    }
}
