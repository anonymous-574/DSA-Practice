#include <bits/stdc++.h>
using namespace std;

#define RADIX 10
#define PRIME 101

void rabinKarp(const string& text, const string& pattern){
    int m = pattern.length();
    int n = text.length();

    if (m > n){
        cout << "The pattern is longer than the text. No match possible.\n";
        return;
    }

    int patternHash = 0, textHash = 0;
    int h = 1;
    for(int i = 0; i< m-1; i++){
        h = (h*RADIX) % PRIME;
    }
    for(int i = 0; i < m ;i++){
        patternHash = (patternHash * RADIX + pattern[i] ) % PRIME;
        textHash = (textHash * RADIX + text[i] ) % PRIME;
    }

    for(int i =0 ; i < n-m+1; i++){
        if(patternHash == textHash){
            int j;
            for(j = 0; j < m;j++){
                if(pattern[i]!=text[i+j]) break;
            }
            cout << "Pattern found at index " << i << "\n"; 
        }
        if(i < n-m){
            textHash = (RADIX*(textHash - h*text[i]) + text[i+m]) % PRIME;
            if(textHash < 0) textHash += PRIME;
        }
    }
}

int main(){
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin,text);
    cout << "Enter the pattern: ";
    getline(cin,pattern);
    rabinKarp(text,pattern);
    return 0;
}