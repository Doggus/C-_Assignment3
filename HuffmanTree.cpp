//
// Created by tldlir001 on 2018/04/09.
//

#include <iostream>
#include "HuffmanTree.h"

// Normal constructor
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

//Copy constructor
tldlir001::HuffmanTree::HuffmanTree(const tldlir001::HuffmanTree &tree)
{
    root = tree.root;
}

//move constructor

tldlir001::HuffmanTree::HuffmanTree(const tldlir001::HuffmanTree &&tree)
{
    root = std::move(root);
}


//default constructor
tldlir001::HuffmanTree::HuffmanTree()
{
    root = nullptr;
}


//destructor
tldlir001::HuffmanTree::~HuffmanTree() //calls by itself (automatic)
{
    //make pointers point to nothing (no memory allocated with new)
    root = nullptr; // or root.reset()
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
