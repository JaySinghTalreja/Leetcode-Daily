// Plain backtracking
class Solution {
    int min = Integer.MAX_VALUE;
    public int assignBikes(int[][] workers, int[][] bikes) {
        int m = bikes.length;
        boolean[] used = new boolean[m];
        dfs(0, workers, bikes, 0, used);
        return min;
    }

    private void dfs(int workerIndex, int[][] workers, 
        int[][] bikes, int sum, boolean[] used) {
        if (workerIndex == workers.length) {
            min = Math.min(min, sum);
            return;
        }

        if (sum > min) return;

        for (int i = 0; i < bikes.length; i++) {
            if (!used[i]) {
                used[i] = true;
                dfs(workerIndex + 1, workers, bikes, sum +
                   distance(workers[workerIndex], bikes[i]), used);
                used[i] = false;
            }
        }
    }

    private int distance(int[] worker, int[] bike) {
        return Math.abs(worker[0] - bike[0]) + Math.abs(worker[1] - bike[1]);
    }
}



// State reducing dynamic programming
class Solution {
    public int assignBikes(int[][] workers, int[][] bikes) {
        int n = bikes.length;
        int[] dp = new int[1 << n];
        return dfs(workers, bikes, 0, 0, dp);
    }

    private int dfs(int[][] workers, int[][] bikes, 
        int workerIndex, int state, int[] dp) {
        if (workerIndex == workers.length) return 0;
        if (dp[state] != 0) return dp[state];
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < bikes.length; i++) {
            if ((state & (1 << i)) == 0) {
                min = Math.min(min, Math.abs(workers[workerIndex][0] - bikes[i][0]) +
                Math.abs(workers[workerIndex][1] - bikes[i][1]) +
                dfs(workers, bikes, workerIndex + 1, state | (1 << i), dp));
            }
        }

        dp[state] = min;
        return min;
    }
}
