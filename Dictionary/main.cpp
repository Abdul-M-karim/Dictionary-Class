//
//  main.cpp
//  Dictionary
//
//  Created by abdul karim on 8/24/17.
//  Copyright © 2017 Abdul Karim. All rights reserved.
//

#include <iostream>
#include "Dictionary.h"
using namespace std;

int main(int argc, const char * argv[]) 
    {
        Dictionary test;
         test.addWord("hello");
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