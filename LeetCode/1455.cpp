#include <vector>
#include <iostream>
#include <bits/stdc++.h> 
#include <string>
using namespace std;

class Solution {
public:

    vector<string> split_sentence(string sen) {
  
    // Create a stringstream object
    stringstream ss(sen);
    
    // Variable to hold each word
    string word;
    
    // Vector to store the words
    vector<string> words;
    
    // Extract words from the sentence
    while (ss >> word) {
      
        // Add the word to the vector
        words.push_back(word);
    }
    
    return words;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words = split_sentence(sentence);
        auto it =  searchWord.insert( searchWord.begin() + 0, ' ');
        cout<<searchWord;
        for(int i=0 ; i< words.size();i++)
        {
            auto it = words[i].insert(words[i].begin() + 0, ' ');
            if (words[i].find(searchWord)!=-1)
            {
                return i+1;
            }
        }
        return -1;
    }
};

//better
/*
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Split the sentence into words
        istringstream stream(sentence);
        string word;
        int index = 1; // 1-based index
        
        while (stream >> word) {
            // Check if the word starts with the searchWord
            if (word.find(searchWord) == 0) {
                return index;
            }
            index++;
        }
        
        // Return -1 if no word starts with the searchWord
        return -1;
    }
};

*/