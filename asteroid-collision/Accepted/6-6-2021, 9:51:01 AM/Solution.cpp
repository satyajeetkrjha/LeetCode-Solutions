// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector <int > ans;
        stack <int> s;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){ // no collision
                s.push(asteroids[i]);
            }
            else {
                while(s.size() >0  && s.top()>0 && s.top()< abs(asteroids[i])){
                    s.pop();
                }
                if(s.size() >0 && s.top() >0 && s.top()  == abs(asteroids[i])){
                    s.pop();
                }
                else if (s.size() > 0 && s.top() >0 && s.top() > abs(asteroids[i])){
                    //
                }
                else {
                    s.push(asteroids[i]);
                }
            }
        }
       
        cout <<s.size() <<endl;
        int sz = s.size();
        ans.resize(sz);
        while(s.size() >0){
             int val =s.top(); 
             s.pop();
             ans[sz-1]= val;
              sz--;
             cout <<"val is "<<val <<endl;
            
        }
         return ans ;
    }
};