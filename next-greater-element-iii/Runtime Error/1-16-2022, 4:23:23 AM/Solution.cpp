// https://leetcode.com/problems/next-greater-element-iii

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(s.size() ==1)
            return -1;
        int sz = s.size();
        bool flag = false;
        int index =0 ;
        
        // 9 8 7 6
        // ,............. 5 9 8 7 6 
        int i = sz-2;
        for( ;i>=0;i--){
            if(s[i]-'0' < s[i+1]-'0'){
                cout <<"here .."<< endl;
                index = i;
                flag =true;
                break;
            }
        }
        
       
        
        
        cout <<"index is "<< index << endl;
        cout <<"flag is "<< flag << endl;
        
        if(!flag)
            return -1;
        
        int nextindex = 0;

        for(int i = sz-1;i>=0;i--){
            if(s[index]-'0'< s[i]-'0'){
                nextindex = i;
                break;
            }
        }
        
       cout <<"necxtindex is "<<nextindex<<endl;
        
        
        
        swap(s[index],s[nextindex]);
        int start = index+1;int end = s.size()-1;
        while(start <end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
        
        
      cout <<"s now is"<< s<< endl;
       return stoi(s);
      
    }
};