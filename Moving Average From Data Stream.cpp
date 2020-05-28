class MovingAverage {
public:
    /** Initialize your data structure here. */
    double runningTotal;
    unsigned int windowSize;
    std::queue<int> buffer;
    
    MovingAverage(unsigned int inputSize) {
        /*initialize values*/
        runningTotal = 0.0;
        windowSize = inputSize;
    }
    
    double next(int inputValue) {
        /*check if buffer is full*/
        if (buffer.size() == windowSize)
        {
            /*subtract front value from running total*/
            runningTotal -= buffer.front();
            /*delete value from front of std::queue*/
            buffer.pop();
        }
        /*add new value*/
        buffer.push(inputValue);
        /*update running total*/
        runningTotal += inputValue;
        /*calculate average*/
        return static_cast<double>(runningTotal / buffer.size());
    }
};


/**
 Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
 * 