//
// Created by tldlir001 on 2018/04/09.
//

#include "HuffmanNode.h"

tldlir001::HuffmanNode::HuffmanNode(const char &l, const int &f)
{
    tldlir001::HuffmanNode::letter = l;
    tldlir001::HuffmanNode::frequency = f;

    tldlir001::HuffmanNode::right;
    tldlir001::HuffmanNode::left;
}




tldlir001::HuffmanNode::~HuffmanNode()
{

}

