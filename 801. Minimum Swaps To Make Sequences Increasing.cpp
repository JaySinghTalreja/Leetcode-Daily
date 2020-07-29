class Solution {
    public int minSwap(int[] A, int[] B) {
        int len = A.length;
        int[] keep = new int[len];
        int[] swap = new int[len];
         
        // Init for max
        //
        for (int i = 0; i < len; i++)
        {
            keep[i] = Integer.MAX_VALUE;
            swap[i] = Integer.MAX_VALUE;
        }
         
        keep[0] = 0;
        swap[0] = 1;
         
        for (int i = 1; i < len; i++)
        {
            if (A[i] > A[i - 1] && B[i] > B[i - 1])
            {
                keep[i] = keep[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
             
            if (A[i] > B[i - 1] && B[i] > A[i - 1])
            {
                keep[i] = Math.min(keep[i], swap[i - 1]);
                swap[i] = Math.min(swap[i], keep[i - 1] + 1);
            }
        }
        for(int i=0;i<len;i++) {
            System.out.print(keep[i] + " ");
        }
        System.out.println("\n");
        for(int i=0;i<len;i++) {
            System.out.print(swap[i] + " ");
        }
        return Math.min(keep[len - 1], swap[len - 1]);
    }
}

/*
Keep:0 0 1 1 1 

Swap:1 1 1 2 2 
*/