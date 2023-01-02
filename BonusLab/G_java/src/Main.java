import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            boolean[] trees = new boolean[2 * n + 3];
            for (int i = 1; i <= n; i++) {
                trees[i] = false;
            }
            for (int i = 1; i <= n; i++) {
                int left = sc.nextInt();
                int right = sc.nextInt();
                if (left != 0) trees[2 * i] = true;
                if (right != 0) trees[2 * i + 1] = true;
            }
            boolean result = true;
            boolean existZero = false;
            for (int i = 1; i <= n; i++) {
                if (trees[i] && !existZero) {
                    existZero = true;
                }
                if (trees[i] && existZero) {
                    result = false;
                    break;
                }
            }
            if (result) System.out.println("Yes");
            else System.out.println("No");
        }
    }
}
