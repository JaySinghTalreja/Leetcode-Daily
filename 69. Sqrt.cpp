//Binary Search Solution  100% memory 62% space
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x==1?1:0;
        }
        int left = 0;
        int right = INT_MAX;
        unsigned int mid;
        while(left < right){
            mid = left+(right-left)/2;
            if(mid * mid <= x) {
                if((mid+1)*(mid+1) > x){
                    return mid;
                }
                else if(mid * mid == x){
                    return mid;
                }
                else{
                    left = mid+1;
                }
            }
            else{
               right = mid-1; 
            }
        }
        return right;
    }
};

//Naive Solution
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x == 1 ? 1: 0; 
        }
        
        for(unsigned int i=2;;i*i<=x;++i){}
        return --i;
    }
};


//Binary Search Revised
public int sqrt(int x) {
    if (x == 0)
        return 0;
    int left = 1, right = Integer.MAX_VALUE;
    while (true) {
        int mid = left + (right - left)/2;
        if (mid > x/mid) {
            right = mid - 1;
        } else {
            if (mid + 1 > x/(mid + 1))
                return mid;
            left = mid + 1;
        }
    }
}

//BIT Manipulation
public int sqrt(int x) {
    if(x==0)
        return 0;
    int h=0;
    while((long)(1<<h)*(long)(1<<h)<=x) // firstly, find the most significant bit
        h++;
    h--;
    int b=h-1;
    int res=(1<<h);
    //Check adding each bit after the MSB and see if the sqaure is less than or equal to x;
    while(b>=0){  // find the remaining bits
        if((long)(res | (1<<b))*(long)(res |(1<<b))<=x)
            res|=(1<<b);
        b--;
    }
    return res;
}
