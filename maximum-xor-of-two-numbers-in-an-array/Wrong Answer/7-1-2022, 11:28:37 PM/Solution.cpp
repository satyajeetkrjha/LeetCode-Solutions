// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array


struct Node{
     
    Node *links[2];
    
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int index ,Node* node){
        links[index] = node ;
    } 
};


class Trie{
   
    private:
        Node* root ;
    public:
         Trie(){
             root = new Node();
         }
    
     
       void insert(int num){
           Node* node = root ;
           for(int i = 31;i>=0 ;i--){
               int bit = (num >> i) & 1;
           if(!node->containsKey(bit)){
               node->put(bit,new Node());
           }
           node = node->get(bit);
           }
           
       }
       
       int findmax(int num){
           Node* node = root ;
           int maxnum =0 ;
           for(int i = 31 ;i>=0 ;i--){
               int bit = (num >> i) & 1 ;
               if(node->containsKey(!bit)){
                   maxnum = maxnum | (1 << i);
                   node = node->get(!bit);
               }
               else{
                   node = node->get(bit);
               }
           }
           return maxnum ;
       }
    
    
    
    
    
    
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie ;
        for(int i =0 ;i<nums.size();i++){
            int val = nums[i];
            trie.insert(val);
        }
        int maxans ;
        for(int i =0 ;i< nums.size();i++){
            maxans = max(maxans,trie.findmax(nums[i]));
        }
        return maxans ;
    }
};