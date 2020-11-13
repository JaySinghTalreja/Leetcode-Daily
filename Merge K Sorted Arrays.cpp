#include<bits/stdc++.h>
using namespace std;

struct HeapNode {
    int val;
    int currentIndex;
    int nextIndex;
};

vector<HeapNode> HEAP;

void heapify(int size, int index) {

    int smallest = index;

    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    if( leftChild < size && HEAP[smallest].val > HEAP[leftChild].val ) smallest = leftChild;
    if( rightChild < size && HEAP[smallest].val > HEAP[rightChild].val ) smallest = rightChild;
    
    if(smallest != index) {

        swap(HEAP[smallest], HEAP[index]);
        heapify(size, smallest);

    } 

}

void buildHeap(vector<vector<int>> &A) {

    int rows = A.size();
    HeapNode temp;
    for(int i=0;i<rows;i++) {
        temp.val = A[i][0];
        temp.currentIndex = i;
        temp.nextIndex = 1;
        HEAP.push_back(temp);
    }
    for(int i=rows/2-1;i>=0;i--)
        heapify(rows, i);

}

bool validateCords(vector<vector<int>> &A,int &currentArray ,int &nextIndex) {
        int index = A[currentArray].size();
        if(index <= nextIndex) {
            return false;
        }
        return true;

}

void solve(vector<vector<int>> &A, vector<int> &ans) {
    buildHeap(A);
    int rows = A.size();
    int total = rows * A[0].size();
    int index = 0;
    while(index < total) {
        /*cout<<"Printing Heap:";
        for(auto C: HEAP) {
            cout<<C.val<<" "<<"CurrentArray:"<<C.currentIndex<<" "<<"Next Index:"<<C.nextIndex<<"\n";
        }
        cout<<endl;
        */
        int val = HEAP[0].val;
        int currentArray = HEAP[0].currentIndex;
        int nextIndex = HEAP[0].nextIndex;

        //Check for nextIndex Validity;
        if(validateCords(A, currentArray, nextIndex) ) {

            HEAP[0].val = A[currentArray][nextIndex];
            HEAP[0].currentIndex = currentArray;
            HEAP[0].nextIndex = nextIndex + 1;

        }
        else{
            HEAP[0].val = INT_MAX;
        }
        /*
        cout<<"\nRECHECK:";
        for(auto C: HEAP) {
            cout<<C.val<<" "<<C.currentIndex<<" "<<C.nextIndex;
            cout<<endl;
        }
        cout<<endl;
        */
        ans.push_back(val);
        heapify(HEAP.size(), 0);
        index++;
    }
}
int main()
{
    vector<vector<int>> A{ {0, 1, 5, 7}, {2, 4, 6, 8}, {3, 10, 11, 13} };
    vector<int> ans;
    solve(A, ans);
    for(auto element: ans) {
        cout<<element<<" ";
    }
    return 0;
}