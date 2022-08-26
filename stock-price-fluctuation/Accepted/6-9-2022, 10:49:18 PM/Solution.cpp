// https://leetcode.com/problems/stock-price-fluctuation


/*
Think Satya think .
we are going to use a map <int ,int>m and this is going to store the price against timestamp .
We use a multiset too but why ? Note that a multiset can contain duplicates .
So this may be the situation 
at timestamp 1 -> 10 
again timestmap 1 -> 15
so you will delette 10 because 15 is the new one .
but hey it can be that two timestamps have same price 
i.e. timestamp 1 = 10
     timestamp 2 = 10





*/




class StockPrice {
public:
    map <int ,int> m ;
    multiset <int> prices;
    int latest = -1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        // check if we already have this timestamp mapped 
        if(m.count(timestamp)>0){
            prices.erase(prices.find(m[timestamp]));
        }
        m[timestamp] = price;
        latest = max(latest,timestamp);
        prices.insert(price);
    }
    
    int current() {
        return m[latest];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return  *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */