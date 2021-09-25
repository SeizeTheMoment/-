class Node {
    int pos;
    int expense;
    int step;
    Node(int p, int e, int s)
    {
        pos = p;
        expense = e;
        step = s;
    }
}
class Solution {

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int matrix[][] = new int[n][n];
        for(int[] flight : flights){
            matrix[flight[0]][flight[1]] = flight[2];
        }

        //queue存储当前位置和价格
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(src, 0, 0));
        int ans = Integer.MAX_VALUE;
        int expenses[] = new int[n];
        for(int i = 0; i < n; i++)
            expenses[i] = Integer.MAX_VALUE;
        expenses[src] = 0;
        while(queue.size() != 0)
        {
            Node top = queue.poll();
            int pos = top.pos;
            int expense = top.expense;
            int step = top.step;
            if(step > k )
            { 
                break;
            }
            
                for(int i = 0; i < n; i++)
                {
                    if(matrix[pos][i] != 0 && expense + matrix[pos][i] < expenses[i])
                    {
                        expenses[i] = expense + matrix[pos][i];
                        queue.offer(new Node(i, expense + matrix[pos][i], step + 1));
                    }
                }
            
        }
        if(expenses[dst] == Integer.MAX_VALUE)
            return -1;
        return expenses[dst];
    }
}