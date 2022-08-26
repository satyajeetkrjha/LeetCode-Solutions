// https://leetcode.com/problems/snapshot-array

class SnapshotArray {
public:

    /*
    
    Let us suppose that you are index 1 and in the first snapshot,the value was 10 
    and at same index ,now it's second snapshot and value is 20.
    so we have
    map <int ,map <int,int> > snaps ; 
    for index 1  and snapshot id 2 , you have value 10 so map inside a map .
    Think hard satya when you see this again.Nothing fancy

    */
    map <int ,map <int ,int > > m;
    int snapId =0;
    SnapshotArray(int length) {
        for(int i =0 ;i< length ;i++){
            map <int ,int> temp ; // this is for hey at this snapid ,value is 10;
            temp[0] =0;
            m[i] = temp;
        }
    }
    
    void set(int index, int val) {
        m[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        return m[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */