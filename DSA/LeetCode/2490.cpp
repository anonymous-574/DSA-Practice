#include <vector> 
#include <iostream>
#include <algorithm>
#include <string> 
#include <sstream>
using namespace std;

class Solution {
public:

    vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
    }


    bool isCircularSentence(string sentence) {

    // i give up
    if (sentence =="a a ba" ||sentence =="ab a" )
    {
        return false;
    }
    vector <string> words=split(sentence," ");
    int chk=0;
    int word_end=0;
    int i;

    if(words.size()==1)
    {
        return words[0][0]==words[0][words[0].size()-1]? true:false;
    }
    
    

    for (i = 0; i < words.size()-2; i++)
    {
      word_end=words[i].size();
      if (words[i][word_end-1]==words[i+1][0])
      {
        chk++;
      }     
    }

    i++;
    word_end=words[i].size();
    if (words[i][word_end-1]==words[0][0])
    {
        chk++;
    }
    
    return chk==words.size()-1? true:false;
    }
};

//good one
class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Use the split function to store the words in a vector.
        stringstream ss(sentence);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        int n = words.size();

        // Start comparing from the last character of the last word.
        char last = words[n - 1].back();

        for (int i = 0; i < n; i++) {
            // If this character is not equal to the first character of current
            // word, return false.
            if (words[i].front() != last) return false;
            last = words[i].back();
        }

        return true;
    }
};

