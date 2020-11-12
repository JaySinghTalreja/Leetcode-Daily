#include<bits/stdc++.h>
using namespace std;


int mergeCount(vector<int> &A, int left, int mid, int right) {
    vector<int> leftArr, rightArr;

    for(int i=left;i<=mid;i++) {
        leftArr.push_back(A[i]);
    }
    for(int i = mid+1;i<=right;i++) {
        rightArr.push_back(A[i]);
    }

    int i = 0;
    int j = 0;
    int totalInverts = 0;
    int k=left;
    while(i<=leftArr.size()-1 && j <= rightArr.size()-1) {

        if(leftArr[i] <= rightArr[j]) {
            A[k++] = leftArr[i];
            //totalInverts += j-i;
            i++;
        }
        else if(rightArr[j] < leftArr[i]) {
            
            A[k++] = rightArr[j];
            //REMEBER THIS FORMULA TOO IMPORTANT
            int counts = (mid+1) - (left+i);
            totalInverts += counts;
            //IMP STEP NOTE THIS
            j++;
        }

    }

    while(i<=leftArr.size()-1) {
        A[k++] = leftArr[i];
        i++;
    }

    while(j<=rightArr.size()-1) {
        A[k++] = rightArr[j];
        j++;
    }
    return totalInverts;
}

int countInversion(vector<int> &A, int left, int right) {
    if(left >= right) return 0;
    int mid = left + (right-left)/2;
    int leftCount = countInversion(A, left, mid);
    int rightCount = countInversion(A, mid+1, right);
    int mergedCounts = mergeCount(A, left, mid, right);
    return leftCount + rightCount + mergedCounts;
}

void solve() {
    vector<int> A{8, 4, 2, 1};
    cout<<countInversion(A, 0, A.size()-1)<<endl;
    for(auto C: A){
        cout<<C<<" ";
    }
}

int main()
{
    solve();
    return 0;
}