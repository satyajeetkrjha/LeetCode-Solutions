// https://leetcode.com/problems/detect-squares

class DetectSquares {
public:
    vector <pair <int ,int> > vec;
    map<pair<int ,int> ,int> m;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        vec.push_back({point[0],point[1]});
        m[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        
        int ans =0;
        int qx = point[0] ; // query x
        int qy = point[1] ; // query y 
        
        for(auto[x,y]:vec){
            if(abs(qx-x)!=abs(qy-y)){
                continue ;
            }
            pair <int ,int> topleft = make_pair(x,qy);
            pair <int ,int> bottomleft = make_pair(qx,y);
            ans += m[topleft]*m[bottomleft];
        }
        return ans ;
        
        
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */