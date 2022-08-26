// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector <string > res ;
        
        int i =0 ;
        while( i < words.size()){
            int wc = words[i].size();
            int j = i+1;
            
            int can =0;
            int n = words.size();
            while( j < n && wc+words[j].size()+1+can <= maxWidth){
                wc += words[j].size();
                can++;
                j++;
            }
            
            int vac = maxWidth - wc ;
            int atleast = can == 0 ? 0: vac / can ;
            int extra = can ==0 ? 0 : vac % can;
            
            if(j == words.size()){
                atleast =1 ;
                extra =0;
            }
            
            string s;
            for(int k = i ;k < j ;k++){
                s = s+ words[k];
                if(k == j-1) break;
                for(int e = 0 ;e < atleast ;e++){
                    s+= " ";
                }
                if(extra>0){
                    s+=" ";
                    extra--;
                }
            }
            while(s.size() < maxWidth){
                s+=" ";
            }
            res.push_back(s);
            
            i =j;
        }
        return res ;
        
        
        
    }
};