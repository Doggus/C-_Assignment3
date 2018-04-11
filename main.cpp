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
void bitmap(tldlir001::HuffmanNode n, unordered_map<char, string> &map, string s)
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


}

int main(int argc, char* argv[])
{
    std::priority_queue<tldlir001::HuffmanNode, std::vector<tldlir001::HuffmanNode>, tldlir001::Compare> pq;

    ifstream in((string)argv[1] + ".txt");

    vector<char> let;

    if(!in)
    {
        cout << "Couldn't open file";
    }
    else {

        string s = "";

        for (string line; getline(in, line);)
        {
            s = s + line;
        }

        cout << s << endl;

        //gets input from file and fills priority queue with values

        vector<char> letters (s.begin(), s.end()); //char array made of the letters of the string

        sort(letters.begin(), letters.end()); //sorts letters in ascending order (NB!)

        let = letters; // creates copy to use later

        int count = 0;
        for(int i = 0; i < letters.size(); i++) // fills priority queue (vector NEEDS to be sorted)
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

    unordered_map<char, string> umap; //create map
    bitmap(*ht.root,umap,""); // fill map with bit values

    //create string buffer of bit values
    string buffer = "";
    for(int i = 0; i < let.size(); i++)
    {
        buffer = buffer + umap.at(let[i]);
    }

    // write bit stream to file
   ofstream out;
   out.open((string)argv[2] + ".txt");

   out << buffer;

   out.close();

   //writes chars and their frequencies to a file
   ofstream o;
   o.open((string)argv[2] + ".hdr");

    int c = 0;
    for(int j = 0; j < let.size(); j++)
    {
        if(j <= let.size()-1 && let[j] == let[j+1])
        {
            c++;
        }
        else
        {
            o << let[j] << ": "  << c+1 << endl;
            c = 0;
        }
    }

   o.close();

    return 0;

}



