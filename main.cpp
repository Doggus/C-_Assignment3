#include <iostream>
#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;

int main()
{
    cout << "Hello, World!" << endl;

    std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, tldlir001::Compare> pq;

    tldlir001::HuffmanNode h1('a',1);
    tldlir001::HuffmanNode h2('b',2);
    tldlir001::HuffmanNode h3('c',3);
    tldlir001::HuffmanNode h4('d',4);

    pq.push(h1);
    pq.push(h2);
    pq.push(h3);
    pq.push(h4);


    tldlir001::HuffmanTree ht(pq);

    return 0;
}