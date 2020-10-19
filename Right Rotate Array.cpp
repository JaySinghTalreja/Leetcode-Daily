#include<bits/stdc++.h>
using namespace std;
void rotateArray(vector<int> &A, int rotateIndex) {
    int n = A.size();
    if(rotateIndex == 0  || rotateIndex == n) return;
    int currentElement = A[0];
    int rotateCount = 0;
    int startingIndex = 0;
    int init = 0;
    while(rotateCount < n) {

        do{
            //rotateIndex = (rotateIndex < 0) ? ( rotateIndex + A.size() ) % A.size() : (rotateIndex % A.size());
            startingIndex = (startingIndex - rotateIndex) < 0 ? ((startingIndex - rotateIndex) + A.size()) % A.size() : (startingIndex - rotateIndex) % A.size();
            int temp = A[startingIndex];
            A[startingIndex] = currentElement;
            currentElement = temp;
            rotateCount++;

        }while(startingIndex != init);
        
        if(startingIndex == init) {
            init++;
            startingIndex = init;
            currentElement = A[init];
        }
    }
}
int main()
{
    vector<int> A{1, 2, 3, 4, 5, 6, 7};
    int rotateIndex = 7;
    rotateArray(A, rotateIndex);
    for(auto C: A) {
        cout<<C<<" ";
    }
    return 0;
}