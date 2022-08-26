// https://leetcode.com/problems/logger-rate-limiter

class Logger {
public:
    map <string ,int> m ;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        // check uniqueness first 
        if(m.find(message) == m.end()){
            m[message] = timestamp ;
            return true ;
        }
        else {
            
            // check and update
            if(m.find(message)!=m.end() && abs(m[message] -timestamp) >= 10){
                cout << message<< " "<<timestamp << endl;
                m[message]  = timestamp;
                return true ;
            }
        }
        return false ;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */