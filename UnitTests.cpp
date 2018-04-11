//UNIT TESTS

//Methods being tested are from:
#include "HuffmanNode.h"
#include "HuffmanTree.h"

//Necessary lines of code to operate testing:
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//Necessary imports:
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

TEST_CASE("HUFFMAN TREE CONSTRUCTOR TEST","Tests if huffman tree is being constructed correctly")
{
    priority_queue<tldlir001::HuffmanNode, vector<tldlir001::HuffmanNode>, tldlir001::Compare> pq;

    tldlir001::HuffmanNode n1('a',1);
    tldlir001::HuffmanNode n2('b',2);

    pq.push(n1);
    pq.push(n2);

    tldlir001::HuffmanTree ht(pq);

    tldlir001::HuffmanNode r = *ht.root; //root node

    tldlir001::HuffmanNode left = *r.left; //left child
    tldlir001::HuffmanNode right = *r.right; //right child

    bool equal;

    if(r.letter == '#' && r.frequency == 3 &&
            left.letter == 'a' && left.frequency == 1 &&
            right.letter == 'b' && right.frequency == 2)
    {
        equal = true;
    }
    else
    {
        equal = false;
    }

    REQUIRE(equal == true);
}

TEST_CASE("HUFFMAN TREE DEFAULT CONSTRUCTOR TEST","Tests if huffman tree default constructor works correctly")
{

    tldlir001::HuffmanTree ht; //default constructor

    bool equal;

    if(ht.root == nullptr)
    {
        equal = true;
    }
    else
    {
        equal = false;
    }

    REQUIRE(equal == true);
}

TEST_CASE("HUFFMAN TREE COPY CONSTRUCTOR TEST","Tests if huffmanTree copy constructor works correctly")
{
    priority_queue<tldlir001::HuffmanNode, vector<tldlir001::HuffmanNode>, tldlir001::Compare> pq;

    tldlir001::HuffmanNode n1('a',1);
    tldlir001::HuffmanNode n2('b',2);

    pq.push(n1);
    pq.push(n2);

    tldlir001::HuffmanTree ht(pq);
    tldlir001::HuffmanTree htCopy(ht);

    tldlir001::HuffmanNode r = *ht.root;
    tldlir001::HuffmanNode rCopy = *htCopy.root;

    bool equal;

    if(r.letter == rCopy.letter && r.frequency == rCopy.frequency)
    {
        equal = true;
    }
    else
    {
        equal = false;
    }

    REQUIRE(equal == true);
}


TEST_CASE("MOVE METHOD","Tests if the compare method from the compare class works correctly")
{
    priority_queue<tldlir001::HuffmanNode, vector<tldlir001::HuffmanNode>, tldlir001::Compare> pq;

    tldlir001::HuffmanNode n1('a',1);
    tldlir001::HuffmanNode n2('b',2);

    pq.push(n1);
    pq.push(n2);

    tldlir001::HuffmanTree ht(pq);
    tldlir001::HuffmanTree Mht(ht);

    shared_ptr<tldlir001::HuffmanNode>  r = std::move(ht.root);
    //tldlir001::HuffmanNode Mr = *Mht.root;

    bool equal;

    if(Mht.root == r)
    {
        equal = true;
    }
    else
    {
        equal = false;
    }

    REQUIRE(equal == true);

}

TEST_CASE("HUFFMAN NODE CONSTRUCTOR TEST","Tests if huffman node is being created correctly")
{
    tldlir001::HuffmanNode hn('a',1);

    bool equal;

    if(hn.letter == 'a' && hn.frequency == 1)
    {
        equal = true;
    }
    else
    {
        equal = false;
    }


    REQUIRE(equal == true);

}

TEST_CASE("HUFFMAN NODE DEFAULT CONSTRUCTOR TEST","Tests if huffman node default constructor works correctly")
{
    tldlir001::HuffmanNode hn;

    bool equal;

    if(hn.letter == '#' && hn.frequency == 0)
    {
        equal = true;
    }
    else
    {
        equal = false;
    }

    REQUIRE(equal == true);

}

TEST_CASE("COMPARE METHOD","Tests if compare method from compare class works correctly")
{
    tldlir001::HuffmanNode n1('a',1);
    tldlir001::HuffmanNode n2('b',2);

    tldlir001::Compare com;
    bool c = com.operator()(n1,n2);

    bool equal;

    if(c == false)
    {
        equal = true;
    }
    else
    {
        equal = false;
    }

    REQUIRE(equal == true);

}









