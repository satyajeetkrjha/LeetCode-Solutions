// https://leetcode.com/problems/path-with-maximum-minimum-value

class Solution {
public:
    const int neigh[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    typedef tuple<int, int, int> cij;
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        priority_queue<cij> pq;
        pq.push({A[0][0],0,0});
        vector<vector<int>> seen(m,vector<int>(n));
        seen[0][0]=1;

        int ret = INT_MAX;
        while(!pq.empty()){
            auto [c,i,j] = pq.top();pq.pop();
            ret = min(ret, c);
			     if(i==m-1 && j==n-1) break;
            for(auto[di,dj]: neigh){
                int ii = i+di, jj=j+dj;
                if(ii>= 0 and ii<m and jj>=0 and jj<n and !seen[ii][jj]) {
                  seen[ii][jj] = 1;
                  pq.push({A[ii][jj],ii,jj});
                }
            }
        }
        return ret;
    }
};