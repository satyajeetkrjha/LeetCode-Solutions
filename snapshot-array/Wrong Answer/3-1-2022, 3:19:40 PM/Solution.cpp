// https://leetcode.com/problems/snapshot-array

class SnapshotArray {
public:

   
    map <int ,map <int ,int > > m;
    int snapId =0;
    SnapshotArray(int length) {
        for(int i =0 ;i< length ;i++){
            map <int ,int> temp ; // this is for hey at this snapid ,value is 10;
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
         map <int ,int> temp  = m[index];
         auto it = m[index].lower_bound(snap_id+1);
         return it->second-1;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */