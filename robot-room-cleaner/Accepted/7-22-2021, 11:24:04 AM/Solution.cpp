// https://leetcode.com/problems/robot-room-cleaner

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
   vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    set <pair <int,int> > visited ;
    
    
   void backtrack(Robot& robot, int i ,int j ,int dir){
        visited.insert(make_pair(i ,j));
        robot.clean();
        for(int k =0 ;k<4;k++){
            int newdir = (dir+k)%4 ;
            
            int newr = i + directions[newdir][0];
            int newc = j + directions[newdir][1];
            if(visited.find(make_pair(newr,newc)) == visited.end() && robot.move()){
                backtrack(robot ,newr,newc,newdir);
                // go back part
                 robot.turnRight();
                 robot.turnRight();
                 robot.move();
                 robot.turnRight();
                 robot.turnRight();
                // over
            }
            robot.turnRight();   
        }
    }
    
    void cleanRoom(Robot& robot) {
        backtrack(robot, 0 ,0, 0); // Robot, i, j and direction 
    }
};