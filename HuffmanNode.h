//
// Created by tldlir001 on 2018/04/09.
//

#ifndef HUFFMANPROJECT_HUFFMANNODE_H
#define HUFFMANPROJECT_HUFFMANNODE_H

#include <memory>

namespace tldlir001
{
    class HuffmanNode
    {

        public:

            char letter;
            int frequency;

            std::shared_ptr <HuffmanNode> left;
            std::shared_ptr <HuffmanNode> right;

            HuffmanNode(const char &l, const int &f);
            ~HuffmanNode();
    };
}



#endif //HUFFMANPROJECT_HUFFMANNODE_H
