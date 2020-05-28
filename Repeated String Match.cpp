class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string dRep = A;
        int noOfReps = 1;
        while(A.length() < B.length()) {
            A.append(dRep);
            noOfReps++;
        }
        if(A.find(B) != string::npos) {
            return noOfReps;
        }
        A.append(dRep);
        noOfReps++;
        if(A.find(B) != string::npos) {
            return noOfReps;
        }
        return -1;
    }
};