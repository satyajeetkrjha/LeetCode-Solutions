// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    
    //O(N)
    int findKthPositive(vector<int>& arr, int k) {
        /*
        Let us suppose that we have to find the 3rd missing positive integer and the first element in arr is 9 now in this case we see that k is less than (9-1) i.e k lies before our first positive number in the arr     
         */   
        if(k <= arr[0]-1){
            return k;
        }
        /*
          let us suppose that we need to find the 15 th missing positive numbers so 
          (15-(9-1)) i.e we already had 7 positive numbersv before arr[0] so decrease k by 8
        
        */
     
        k = k- (arr[0]-1); 
        // u do 5-(2-1) i.e 5-1 and not 5-2-1 =3-1 =2 
       // cout<<"k here is "<<k <<endl;
        int n = arr.size();
        for(int i =0 ;i<n-1;i++){
            /* this gives us the missing numbers between arr[i] and arr[i+1]
            so if currMissing is 10 and you have k left as say 6 now then 
            just do arr[i]+6 because arr[i]+6 will lie between arr[i] and arr[i+1] 
            */
            int currMissing = arr[i+1]- arr[i]-1;
            //cout <<"k is "<<k<<endl;
            //cout<<"currMissing is "<<currMissing <<endl;
            //cout<<" a[i] is "<<arr[i]<<endl;
            if(k <=currMissing){
                return arr[i]+k;
            }
            
                k = k- currMissing;
        }
        //last case
        return arr[n-1]+k;    
    }
};