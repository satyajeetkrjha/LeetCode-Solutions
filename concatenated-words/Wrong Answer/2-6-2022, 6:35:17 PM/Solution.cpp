// https://leetcode.com/problems/concatenated-words

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& w1, string& w2){
            return (w1.length() <= w2.length());
        });
        
        /*
        for(auto &word :words){
            cout << word << " ";
        }
        cout << endl;
        */
        vector<string> ret;
        unordered_set<string> m;
        
        for(string w : words) {
            vector<bool> dp(w.length()+1, false);
            dp[0] = true;
            for(int i = 0; i < w.length(); i++) {
                for(int j = i; j >= 0; j--) {
                    string s = w.substr(j, i-j+1); // O(length) operation
                 //   cout <<"string s is "<< s<< endl;
                    if(dp[j] && m.find(s) != m.end()) {
                        dp[i+1] = true;
                        break;
                    }
                }
            }
            
            if(dp[w.length()])
                ret.push_back(w);
            
            m.insert(w);
        }
        
        return ret;
    }
};