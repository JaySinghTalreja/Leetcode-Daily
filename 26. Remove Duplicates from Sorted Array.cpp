//My Solution Much time Consuming 
//Time Complexity for erasing is O(N) and we N-1 Shits in the worst case; 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == nums[i-1]){
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};
//Erasing an element in a vector is O(n) as we have to remove the element and still need to shift all successive elements to fill the gap created. 
//If a vector has n elements, then in the worst case we will need to shift n-1 elemets, hence the complexity is O(n).




//Two Pointers

//Alternative 1 O(N)
int count = 0;
for(int i = 1; i < n; i++){
    if(A[i] == A[i-1]) count++;
    else A[i-count] = A[i];
}
return n-count;


//Alternative 2
public class Solution {
    public int removeDuplicates(int[] nums) {
    
        int i = 1; //iterator thru array
        int j = 0; //current index
        for (; i<nums.length; i++) { 
            if (nums[i] != nums[j]) { //new number
                j++; //move current index
                nums[j] = nums[i]; //fill current index with new number
            } 
        }
    return j+1;
   }
}