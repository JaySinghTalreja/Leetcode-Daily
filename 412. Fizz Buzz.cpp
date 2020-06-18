class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i=0;i<n;i++) {
            if((i+1)%3 != 0 && (i+1)%5 != 0) {
                res[i] = to_string(i+1);
            }
            else if((i+1)%3==0 && (i+1)%5==0) {
                res[i] = "FizzBuzz";
            }
            else if((i+1)%3 == 0) {
                res[i] = "Fizz";
            }
            else {
                res[i] = "Buzz";
            }
        }
        return res;
    }
};


//Alternative Without %
public List<String> fizzBuzz(int n) {
        
        List<String> result = new ArrayList<>();
        
        if(n < 1) return result;
        
        for(int i = 1, fizz = 3, buzz = 5; i <= n; i++) {
        
            String addVal = null;
            
            if(i == fizz && i == buzz) {
                addVal = "FizzBuzz"; 
                fizz += 3;
                buzz += 5;
            } else if(i == fizz) {
                addVal = "Fizz";
                fizz += 3;
            } else if(i == buzz) {
                addVal ="Buzz";
                buzz += 5;
            } else
                addVal = String.valueOf(i);
            
            result.add(addVal); 
        }
        
        return result;
    }


//Alternative Without if else
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 1;i <= n; i++) {
            res[i - 1] = to_string(i);
        }
        for(int i = 2;i < n; i += 3) {
            res[i] = "Fizz";
        }
        for(int i = 4;i < n; i += 5) {
            res[i] = "Buzz";
        }
        for(int i = 14;i < n; i += 15) {
            res[i] = "FizzBuzz";
        }
        return res;
    }
};
