// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n= A.size();
        int prefix_sum[n+1];
       prefix_sum[0]=A[0];
        for(int i=1 ;i<A.size();i++){
            prefix_sum[i]=prefix_sum[i-1]+A[i];
        }
        
        map <int ,int > count;
        for(int i=0;i<n;i++){
            int remainder =(prefix_sum[i]%K +K)%K;
            count[remainder]++;
        }  
         int ans =0;
        for (map<int,int>::iterator it=count.begin(); it!=count.end(); ++it){
            int val =it->second;
            if (val>0)
            ans =ans +(val*(val-1))/2;
        }
        ans+=count[0];
                   return ans;
                  
        
    }
};