//
//  dictionary1.cpp
//  DICTIONARY_CLASS
//
//  Created by abdul karim on 2/23/17.
//  Copyright © 2017 Abdul Karim. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Dictionary.h"
#include <fstream>
#include <iostream>
using namespace std;


Dictionary::Dictionary()
{
    root = new NodeType;
    numWords = 0;
    for ( int i = 0; i < 26; i++ ){
        root->next[i] = NULL;
        root->flag[i] = false;
    }
    
}
Dictionary::Dictionary(string file)
{
    string line;
    ifstream inFile;
    inFile.open(file);
    root = new NodeType;
    for(int i=0; i<26; i++)
    {
        root->flag[i] = false;
        root->next[i] = NULL;
    }
    while(!inFile.eof())
    {
        inFile >> line;
        addWord(line);
    }
    inFile.close();
}
void Dictionary::addWord(string word)
{
    int letter = 0; // index
    NodeType* currNode = root;
    for ( int i = 0; i < word.length(); i++)
    {
        char c = word[i]; //break word by array index and store each letter in c
        int charintvalue = (int)c; // convert character c into a integer value of c
        letter = charintvalue - (int)'a'; // subtract the charintvalue to see how far away it is from a (97)
        
        if (currNode->next[letter] == NULL) // if next[letter] is NULL ( doesnt exsist )
        {
            NodeType* newNode; // create a pointer for a node
            newNode = new NodeType; //dynamically allocate a pointer for a node
            for (int i = 0; i < 26; i++) // intialize the node you just created
            {
                newNode->next[i] = NULL;
                newNode->flag[i] = false;
            }
            currNode->next[letter] = newNode; // put the letter inside of the newNode we created
            currNode = currNode->next[letter]; // set currNode
        }
        else {
            currNode = currNode->next[letter]; //set currNode to letter[next]
        }
    }
    currNode->flag[letter] = true; // update the flag
    numWords++; //increase words
}
bool Dictionary::isWord(string word)
{
    int letter = 0; // index
    NodeType* currNode = root; //start at root
    for (int i = 0; i < word.length(); i++)
    {
        char c = word[i]; //store each character
        int charintvalue = (int)c; //convert to an int
        letter = charintvalue - (int)'a';//how far away it is from a
        
        if (currNode->next[letter] == NULL) //word doestn exsist
        {
            return false; //send back false
        }
        else
        {
            currNode = currNode->next[letter]; // set currNode
        }
    }
    
    return (currNode->flag[letter]); //send back flag
}

bool Dictionary::isPrefix(string word)
{
    int letter;
    NodeType* currNode = root;
    for (unsigned int i = 0; i < word.length(); i++)
    {
        char c = word[i];
        int charintvalue = (int)c;
        letter = charintvalue - (int)'a';
        
        if (currNode->next[letter] == NULL)
        {
            return false;
        }
        else
        {
            currNode = currNode->next[letter];
        }
    }
    
    return true;
}

int Dictionary::wordCount()
{
    return numWords;
}


/*
int main ()
{
    Dictionary test;
   // test.addWord("hello");
   // test.addWord("hell");
   // test.addWord("yes");
   // test.addWord("no");
    // cout<< test.wordCount()<<endl;
    //test.isWord("hello");
   // test.isWord("notaword");
   // test.isPrefix("hell");
    Dictionary dict("dictionaryfull.txt");
    
    cout << dict.wordCount() << " words loaded." << endl << endl;
    
    // Below is some code to help you test your dictionary...
    
    string word;
    while (true) {
        cout << "Enter string: ";
        cin >> word;
        
        if (dict.isWord(word)) {
            cout << word << " is a valid word" << endl;
        }
        else {
            cout << word << " is NOT a valid word" << endl;
        }
        
        if (dict.isPrefix(word)) {
            cout << word << " is a valid prefix" << endl;
        }
        else {
            cout << word << " is NOT a valid prefix" << endl;
        }
        
        cout << endl;
    }
 
    return 0;
    
}
*/



