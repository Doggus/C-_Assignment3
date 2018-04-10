#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;

//functions need to be above main to be used in main

//Returns map with node letters and their bitmap values (will be used for compression/decompression)  [Code Table]
unordered_map<char, string> bitmap(tldlir001::HuffmanNode n, unordered_map<char, string> map, string s)
{

    if(n.letter != '#')
    {
        map[n.letter] = s;
        cout << s << endl;
    }
    else
    {
        bitmap(*n.left,map,s+"0");
        bitmap(*n.right,map,s+"1");
    }

    return map;
}


int main()
{
    cout << "Hello, World!" << endl;

    std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, tldlir001::Compare> pq;

    /*
    tldlir001::HuffmanNode h1('a',1);
    tldlir001::HuffmanNode h2('b',2);
    tldlir001::HuffmanNode h3('c',3);
    tldlir001::HuffmanNode h4('d',4);

    pq.push(h1);
    pq.push(h2);
    pq.push(h3);
    pq.push(h4);
    */

    ifstream in("input.txt");

    if(!in)
    {
        cout << "Couldn't open file";
    }
    else {

        /*
        for (string line; getline(in, line);)
        {
            //cout << line << endl;
        }
        */

        //gets input from file and fills priority queue with values

        string line;
        getline(in, line); // first line from file
        cout << line << endl;

        vector<char> letters (line.begin(), line.end()); //char array made of the letters of the string

        sort(letters.begin(), letters.end()); //sorts letters in ascending order

        int count = 0;
        for(int i = 0; i < letters.size(); i++)
        {
            if(i <= letters.size()-1 && letters[i] == letters[i+1])
            {
                count++;
            }
            else
            {
                tldlir001::HuffmanNode h(letters[i],count+1); //need to add 1 to count (just the way i worked out this algorithm)
                pq.push(h);
                count = 0;
            }
        }

    }


    tldlir001::HuffmanTree ht(pq); //create huffman tree using pq

    unordered_map<char, string> umap;
    unordered_map<char, string> map = bitmap(*ht.root,umap,"");
    cout << map.at('a') << endl;

    return 0;
}



