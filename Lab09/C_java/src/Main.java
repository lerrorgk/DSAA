import java.util.*;

public class Main {
    static class Node {
        int color = -1;
        List<Integer> children = new ArrayList<>();
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int m = scan.nextInt();
        int k = scan.nextInt();
        int c = scan.nextInt();

        int[][] data = new int[n][k];
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
        }

        List<Integer>[] colors = new List[k];
        for (int i = 0; i < k; i++) {
            colors[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            int temp = scan.nextInt() - 1;
            nodes[i].color = temp;
            colors[temp].add(i);
        }

        for (int i = 0; i < m; i++) {
            int index1 = scan.nextInt() - 1;
            int index2 = scan.nextInt() - 1;
            nodes[index1].children.add(index2);
            nodes[index2].children.add(index1);
        }

        for (int i = 0; i < k; i++) {
            boolean[] visited = new boolean[n];
            Queue<Integer> que = new LinkedList<>();
            for (int node : colors[i]) {
                data[node][i] = 0;
                que.offer(node);
                visited[node] = true;
            }
            while (!que.isEmpty()) {
                int cur = que.poll();
                for (int child : nodes[cur].children) {
                    if (visited[child]) continue;
                    data[child][i] = data[cur][i] + 1;
                    que.offer(child);
                    visited[child] = true;
                }
            }
        }

        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            Arrays.sort(data[i]);
            int sum = 0;
            for (int j = 0; j < c; j++) {
                sum += data[i][j];
            }
            result[i] = sum;
        }
        for (int i = 0; i < n; i++) {
            System.out.print(result[i] + " ");
        }
    }
}
