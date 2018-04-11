//
// Created by tldlir001 on 2018/04/09.
//

#include "HuffmanNode.h"

//normal constructor
tldlir001::HuffmanNode::HuffmanNode(const char &l, const int &f)
{
    tldlir001::HuffmanNode::letter = l;
    tldlir001::HuffmanNode::frequency = f;

    tldlir001::HuffmanNode::right;
    tldlir001::HuffmanNode::left;
}

//copy constructor (breaks program)
/*
tldlir001::HuffmanNode::HuffmanNode(const tldlir001::HuffmanNode &node)
{

    tldlir001::HuffmanNode::letter = node.letter;
    tldlir001::HuffmanNode::frequency = node.frequency;

    tldlir001::HuffmanNode::right;
    tldlir001::HuffmanNode::left;
}

//move constructor (couldn't get to work)
tldlir001::HuffmanNode::HuffmanNode(tldlir001::HuffmanNode &&node)
{
    tldlir001::HuffmanNode::letter = node.letter;
    tldlir001::HuffmanNode::frequency = node.frequency;

    tldlir001::HuffmanNode::right = std::move(node.right);
    tldlir001::HuffmanNode::left = std::move(node.left);
}
*/

//default constructor
tldlir001::HuffmanNode::HuffmanNode()
{
    tldlir001::HuffmanNode::letter = '#'; //empty (sort of) [arbitrary]
    tldlir001::HuffmanNode::frequency = 0;

    tldlir001::HuffmanNode::right = nullptr;
    tldlir001::HuffmanNode::left = nullptr;
}


//destructor
tldlir001::HuffmanNode::~HuffmanNode() //calls by itself (automatic)
{
    //make pointers point to nothing (no memory allocated with new)
    right = nullptr; //or right.reset()
    left = nullptr; // or left.reset()
}

// This copy assignment operator is neccesary for copy constructor to work
//tldlir001::HuffmanNode &tldlir001::HuffmanNode::operator=(const tldlir001::HuffmanNode &node) = default;

