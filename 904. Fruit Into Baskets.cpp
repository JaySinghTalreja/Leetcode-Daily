class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if(tree.size() <= 2){
            return tree.size();
        }
        int left = 0;
        int right = left +1;
        unordered_set<int> s;
        s.insert(tree[left]);
        int maxSum = INT_MIN;
        int currentSum = 1;
        while(right < tree.size()) {
            auto it = s.find(tree[right]);
            if(it == s.end() && s.size() < 2) {
                s.insert(tree[right]);
                maxSum = max(maxSum, right-left+1);
                right++;
                continue;
            }
            else if(it == s.end() && s.size() == 2) {
                s.clear();
                s.insert(tree[++left]);
                right = left + 1;
            }
            else{
                maxSum = max(maxSum, right-left+1);
                right++;
            }
        }
        return maxSum;
    }
};


//Alternative HashMap Better Time O(N) and O(N)
class Solution {
public:
    int totalFruit(vector<int> &tree) {
            unordered_map<int, int> count;
            int i, j;
            for (i = 0, j = 0; j < tree.size(); ++j) {
                count[tree[j]]++;
                if (count.size() > 2) {
                    if (--count[tree[i]] == 0)count.erase(tree[i]);
                    i++;
                }
            }
            return j - i;
    }
};


//Alternative HashMap Better Time O(N) and O(1)
class Solution {
    public int totalFruit(int[] tree) {
        // track last two fruits seen
        int lastFruit = -1;
        int secondLastFruit = -1;
        int lastFruitCount = 0;
        int currMax = 0;
        int max = 0;
        
        for (int fruit : tree) {
            if (fruit == lastFruit || fruit == secondLastFruit)
                currMax++;
            else
                currMax = lastFruitCount + 1; // last fruit + new fruit
            
            if (fruit == lastFruit)
                lastFruitCount++;
            else
                lastFruitCount = 1; 
            
            if (fruit != lastFruit) {
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }
            
            max = Math.max(max, currMax);
        }
        
        return max;
    }
}
 