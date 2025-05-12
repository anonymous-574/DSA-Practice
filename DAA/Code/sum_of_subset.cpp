#include <bits/stdc++.h>
using namespace std;

int found = 0;

void sumSubset(int set[],int n,int Setindex,int currSum, int target,int sol[],int solIndex){
    if(currSum == target){
        cout << "[";
        for(int i =0;i<solIndex;i++){
            cout << sol[i];
        }
        cout << "]\n";
        found = 1;
        return;
    }

    if(Setindex>=n || currSum > target) return;
    sol[solIndex] = set[Setindex];
    sumSubset(set,n,Setindex+1,currSum + set[Setindex],target,sol,solIndex + 1);
    sumSubset(set,n,Setindex+1,currSum,target,sol,solIndex);

}

int main(){
    int n, target;
    cout << "Enter number of elements in set and target: ";
    cin >> n >> target; 
    int set[n],sol[n];
    for(int i = 0;i < n;i++) cin>>set[i];
    sumSubset(set, n, 0, 0, target, sol, 0);
    if(!found) cout << "No solution found";
}