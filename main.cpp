#include <iostream>
#include <unordered_map>
#include <string>
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

    // tldlir001::Compare c;
    //bool b = c.operator()(h1,h3);
    //cout << b << endl; // prints 1 for true, 0 for false;

    /*
    cout << ht.root << endl;

    tldlir001::HuffmanNode r = *ht.root;
    tldlir001::HuffmanNode lr = *r.left;

    cout << lr.frequency << endl;
    */

    return 0;
}


unordered_map<char, string> bitmap(tldlir001::HuffmanNode n, unordered_map<char, string> map, string s)
{

    if(n.letter != '#')
    {
        map[n.letter] = s;
    }
    else
    {
        bitmap(*n.left,map,s+"0");
        bitmap(*n.right,map,s+"1");
    }

    return map;
}


/*
unordered_map<char, string> bitmap(unordered_map<char, string> map, string s)
{
    return map;
}
 */

