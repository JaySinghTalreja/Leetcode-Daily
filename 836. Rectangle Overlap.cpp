class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (rec1[2] > rec2[0] && rec1[3] > rec2[1] && rec1[0] < rec2[2] && rec1[1] < rec2[3]);
    }
};


//Good Alternative
De Morgan's Law tells us that the following are equivalent. An easy way to remember De Morgan's is by the saying to split the bar and change the operation; that is to distribute negation and change the boolean operator in this example.

    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(rec1[2] <= rec2[0] ||   // left
                 rec1[3] <= rec2[1] ||   // bottom
                 rec1[0] >= rec2[2] ||   // right
                 rec1[1] >= rec2[3]);    // top
    }
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return   rec1[2] > rec2[0] &&   // left
                 rec1[3] > rec2[1] &&   // bottom
                 rec1[0] < rec2[2] &&   // right
                 rec1[1] < rec2[3];     // top
    }
