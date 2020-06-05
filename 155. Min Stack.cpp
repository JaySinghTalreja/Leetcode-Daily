class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    MinStack() {
    }
    
    void push(int x) {
        stack.push_back(x);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return *min_element(stack.begin(), stack.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


////ALTERNATIVE

I decided to post this solution as I found in the discussion tab that mainly people discussed about solutions using 2 stacks or using 2 lists or using structs along with list.
This solution is 100% TIME and SPACE efficient and uses a simple trick to get us the minimum element in the stack using O(1) time. See the top( ), pop( ) and push( ) methods to see the little tweak used.

Instead of pushing in the element which is smaller than the current minimum we push in 2 * x - min
(where x is the element we are currently pushing and min is the current minimum) and update the variable min. Similarly,
when we pop, if the top element is smaller than the current min, we update min by, min = 2 * min - s.top() and then pop the element. 
We also have to keep in mind that in the top( ) function if the current top element is smaller than min then we need to return min.




class MinStack {
public:
    /** initialize your data structure here. */
    stack< long double > s ;
    long double min ;
    MinStack() {
        
    }
    
    void push(long double x) {
        if( s.empty() == true ){
           s.push(x) ;
           min = x ;
        }else{
           if( x < min ){
               s.push( 2 * x - min ) ;
               min = x ;
               
           }else{
              s.push( x ) ;
           }
        }
    }
    
    void pop() {
        if( s.empty() == false ){
            if( s.top() > min ){
                s.pop() ;
            }else{
                min = 2 * min - s.top() ;
                s.pop() ;
            }
        }
    }
    
    int top() {
        if( s.top() > min )
            return s.top() ;
        else
            return min ;
    }
    
    int getMin() {
        return min ;
    }
};