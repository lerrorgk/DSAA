import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;

class Node {
    int idx;
    int inDegree;
    List<Node> children;
    Node(int idx, int inDegree) {
        this.idx = idx;
        this.inDegree = inDegree;
        children = new ArrayList<>();
    }
}

class heapNode implements Comparable<heapNode> {
    int idx;
    Node node;
    heapNode(int idx, Node node) {
        this.idx = idx;
        this.node = node;
    }

    @Override
    public int compareTo(heapNode other) {
        return this.idx - other.idx;
    }
}
public class Main {
    static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static int nextInt() throws Exception{
        in.nextToken();
        return (int)in.nval;

    }
    static int n,m;
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node(i, 0);
            }
            for (int i = 0; i < m; i++) {
                int A = sc.nextInt();
                int B = sc.nextInt();
                A--;
                B--;
                nodes[A].children.add(nodes[B]);
                nodes[B].inDegree++;
            }
            PriorityQueue<heapNode> heapNodes = new PriorityQueue<>();
            for (int i = 0; i < n; i++) {
                if (nodes[i].inDegree == 0) {
                    heapNodes.offer(new heapNode(i, nodes[i]));
                }
            }
            List<Integer> result = new ArrayList<>();
            while (!heapNodes.isEmpty()) {
                Node cur = heapNodes.poll().node;
                result.add(cur.idx + 1);
                for (Node child : cur.children) {
                    child.inDegree--;
                    if (child.inDegree == 0) {
                        heapNodes.offer(new heapNode(child.idx, child));
                    }
                }
            }
            if (result.size() != n) {
                out.println("impossible");
                out.flush();
            } else {
                for (int i : result) {
                    out.print(i + " ");
                    out.flush();
                }
                out.println();
                out.flush();
            }
        }
    }
}


