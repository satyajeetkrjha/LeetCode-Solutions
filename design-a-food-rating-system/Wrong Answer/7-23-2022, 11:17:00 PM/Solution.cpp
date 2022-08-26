// https://leetcode.com/problems/design-a-food-rating-system

class FoodRatings {
public:
    map <string ,int> foodrating;
    map <string,vector <string> > cuisinefoodmap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i =0 ;i<foods.size();i++){
            string food = foods[i];
            int rating = ratings[i];
            string cuisine = cuisines[i];
            foodrating[food] = rating ;
            cuisinefoodmap[cuisine].push_back(food);
            
        }
        
        
    }
    
    void changeRating(string food, int newRating) {
        
        foodrating[food] = newRating ;
    }
    
    string highestRated(string cuisine) {
        int maxval = INT_MIN;
        string item=" ";
        vector <string> res;
        
        for(auto &it :cuisinefoodmap[cuisine]){
            int val = foodrating[it];
            if(val >= maxval){
                maxval = val;
            }
        }
        vector <string> ans ;
        for(auto &it:foodrating){
           if(it.second == maxval){
               ans.push_back(it.first);
           }
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */