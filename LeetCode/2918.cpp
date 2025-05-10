#include <bits/stdc++.h>
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

using namespace std;
using vi = vector<int>;

class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            int z1=0,z2=0;
            int sum1=0,sum2=0;
    
            for (int i = 0; i < nums1.size(); i++){
                sum1+=nums1[i];
                if (nums1[i]==0){
                    z1++;
                }
            }
            
            for (int i = 0; i < nums2.size(); i++){
                sum1+=nums2[i];
                if (nums2[i]==0){
                    z2++;
                }
            }

            //3 cases
            long long ans=0;
            int diff;
            if (z1==0 && z2!=0){
                diff=sum1-sum2;
                if (diff<0){
                    return -1;
                }
                

            }
            else if (z1!=0 && z2==0){
                diff=sum2-sum1;
                if (diff<0){
                    return -1;
                }


            }
            else{
                
            }
            
            
            return ans;
        }
    };