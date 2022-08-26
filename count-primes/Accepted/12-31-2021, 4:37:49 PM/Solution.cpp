// https://leetcode.com/problems/count-primes

class Solution {
public:
    
    int countPrimes(int n) {
        vector <bool> isprime(n+1,true);
        isprime[0] = isprime[1] = false ;
        for(int i =2 ;i<=n;i++){
            if(isprime[i] && (long long) i*i<=n){
                for(int j = i*i ;j<=n ;j+=i){
                    isprime[j] = false;
                }
            }
        }
        
        int count =0;
        for(int i = 1 ;i<n;i++){
            if(isprime[i] == true)
                count++;
        }
    
        return count;
        
        
        
    }
};