#include <bits/stdc++.h>
using namespace std;

int found = 0;

void sumSubset(int set[],int n,int index,int currSum, int t,int sol[],int solIndex){
    if(currSum == t){
        cout << "[";
        for(int i =0;i<solIndex;i++){
            cout << sol[i];
            if(i < solIndex-1) cout<<",";
        }
        cout << "]\n";
        found = 1;
        return;
    }
    if(index>=n || currSum > t) return;
    sol[solIndex] = set[index];
    sumSubset(set,n,index+1,currSum + set[index],t,sol,solIndex + 1);
    sumSubset(set,n,index+1,currSum,t,sol,solIndex);

}

int main(){
    int n, t;
    cout << "Enter number of elements in set and target: ";
    cin >> n >> t; 
    int set[n],sol[n];
    for(int i = 0;i < n;i++) cin>>set[i];
    sumSubset(set, n, 0, 0, t, sol, 0);
    if(!found) cout << "No solution found";
}