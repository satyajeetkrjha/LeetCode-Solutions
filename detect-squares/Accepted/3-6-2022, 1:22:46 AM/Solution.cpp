// https://leetcode.com/problems/detect-squares

class DetectSquares {
public:
    
    vector <pair <int ,int> > vec;
    map <pair <int ,int> ,int> m;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        vec.push_back({point[0],point[1]});
        pair <int,int> temp = {point[0],point[1]};
        m[temp]++;
    }
    
    int count(vector<int> point) {
        int qx = point[0];
        int qy = point[1];
        int ans =0;
        for(auto &[x,y] : vec){
            if(abs(qx-x) != abs(qy-y) || abs(qx-x) == 0){
                continue;
            }
            pair <int ,int> firstpair = {x,qy};
            pair <int,int> secondpair = {qx,y};
            ans += m[firstpair]*m[secondpair];
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