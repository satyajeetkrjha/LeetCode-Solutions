// https://leetcode.com/problems/broken-calculator

/*
think of going from t to s
GOD
you can go from x to x/2 or x to x+1
GOD
we already saw that for odd t, we have to do x+1
GOD
for even t, claim: if we do t → t+1, we will not do halving in the future
GOD
proof: there has to be at least another +1 before halving because t+1 is odd. so consider two +1s followed by one /2. this can be replaced by one /2 followed by one +1, reducing the number of operations
GOD
therefore if t is even, the only possibilities are either to halve now or only do +1s in the future
ME: see .if number is even ,i need to increment it twice before it can be halved 
GOD
ya and that can be replaced by one halving and one increment, which is one fewer operation
Me : reduced it to half in one go but one increment .why this increment ?
GOD
say you want to go from 2k to k+1
GOD
you can do it like 2k → 2k+1 → 2k+2 → k+1 
or like 2k → k → k+1
ME :
so makes sense to divide first and reduce number of steps
at last why steps+(start -target)
why start -target ?
beacuse now ur target is less than start and start was wehere we wanted to reach so to go back
You sent
but u need start -target number of steps

look, once your target is less that start you can only add
GOD
because dividing will make it worse
GOD
so just do start - target and be done with it





*/



class Solution {
public:
    int brokenCalc(int start, int target) {
    
        int steps =0 ;
        while(target>start){
            if(target % 2 == 1){
                target++;
            }
            else{
                target/=2 ;
            }
            steps ++;
        }
        return steps +(start-target);
    }
};