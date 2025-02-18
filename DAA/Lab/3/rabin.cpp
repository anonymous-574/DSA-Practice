#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

int search(const string& text, const string& pattern) {
    int n=text.length(),m=pattern.length();
    int txt_val=0,pat_val=0;
    //a large prime no , size of chars in input (ascii) 
    int q =INT_MAX,d=256;

    int hash=1;
    for (int i = 0; i < m; i++){
        hash = (hash*d)%q;
    }
    
    //the initial values
    for (int i = 0; i < m; i++){
        txt_val=(txt_val*d + text[i])%q;
        pat_val=(pat_val*d + pattern[i])%q;
    }
    
    int y;
    for (int x = 0; x < n-m; x++){
        if (pat_val==txt_val){
            //check the chars
            for (y = 0; y < m; y++){
                if (text[x+y]!=pattern[y]){
                    break;
                }
            }

            if (y==m){
                return x;
            }
        }
        if (x<n-m){
            txt_val=(d*(txt_val-text[x]*hash) + text[x+m])%q;

            if (txt_val<0){
                txt_val+=q;
            }
            
        }
        

    }
    return -1;
}

void benchmarkSearch(const string& filename) {
    ifstream file(filename);
    ofstream resultOutput("results.csv");

    if (!file || !resultOutput) {
        cerr << "Error opening file!" << endl;
        return;
    }

    vector<int> sizes = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    vector<int> patternLengths = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    string text;

    srand(time(0));

    // Write CSV header
    resultOutput << "n,m,time_ns,index\n";

    for (int n : sizes) {
        file.seekg(0);
        text.resize(n);
        file.read(&text[0], n);

        for (int m : patternLengths) {
            if (m > n) break;
            int randomIndex = rand() % (n - m + 1);
            string pattern = text.substr(randomIndex, m);

            auto start1 = high_resolution_clock::now();
            int index = search(text, pattern);
            auto end1 = high_resolution_clock::now();

            auto timeTaken = duration<long long, nano>(end1 - start1).count();

            // Write results in CSV format
            resultOutput << n << "," << m << "," << timeTaken << "," << index << "\n";
        }
    }
    file.close();
    resultOutput.close();
}

int main() {
    benchmarkSearch("big.txt");
    cout << "Benchmark completed. Check results.csv for results." << endl;
    return 0;
}