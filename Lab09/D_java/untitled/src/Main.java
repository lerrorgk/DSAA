import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    static class Node {
        int scc = -1;
        ArrayList<Integer> children = new ArrayList<>();
    }

    static void reverseDFS(int cur, Node[] nodes, boolean[] visited, int[] data, int idx) {
        if (visited[cur]) {
            return;
        }
        visited[cur] = true;
        for (int child : nodes[cur].children) {
            reverseDFS(child, nodes, visited, data, idx);
        }
        data[--idx] = cur;
    }

    static void sccDFS(int cur, Node[] nodes, boolean[] visited, int sccCount) {
        if (visited[cur]) {
            return;
        }
        visited[cur] = true;
        nodes[cur].scc = sccCount;
        for (int child : nodes[cur].children) {
            sccDFS(child, nodes, visited, sccCount);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int S = sc.nextInt();
        S--;
        Node[] inputGraph = new Node[n];
        Node[] reverseGraph = new Node[n];
        for (int i = 0; i < n; i++) {
            inputGraph[i] = new Node();
            reverseGraph[i] = new Node();
        }
        for (int i = 0; i < m; i++) {
            int index1 = sc.nextInt();
            int index2 = sc.nextInt();
            index1--;
            index2--;
            inputGraph[index1].children.add(index2);
            reverseGraph[index2].children.add(index1);
        }

        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        int[] data = new int[n];
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            reverseDFS(i, reverseGraph, visited, data, n);
        }

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
        int sccCount = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }
            sccDFS(i, inputGraph, visited, sccCount);
            sccCount++;
        }

        int[] inDegree = new int[sccCount];
        for (int i = 0; i < sccCount; i++) {
            inDegree[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int child : inputGraph[i].children){
                if (inputGraph[i].scc != inputGraph[child].scc){
                    inDegree[inputGraph[child].scc]++;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < sccCount; i++) {
            if (inDegree[i] == 0) {
                count++;
            }
        }
        if (inDegree[inputGraph[S].scc] ==0){
            System.out.println(count - 1);
        } else{
            System.out.println(count);
        }
    }
}
