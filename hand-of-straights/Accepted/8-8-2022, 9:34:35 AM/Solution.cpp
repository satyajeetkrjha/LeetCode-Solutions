// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
         map <int ,int> m;
       
        if(hand.size() % groupSize !=0)
            return false ;
        
        
        for(auto &it:hand){
            m[it]++;
        }
        
        while(m.size() >0){
            int val = m.begin()->first ;
            int endpart = val+groupSize-1;
            for(int j = val ;j<=endpart;j++){
                if(m[j] == 0)
                    return false;
                else if(--m[j] ==0) 
                    m.erase(j);
            }
        }
        
        return true ;  
    }
};