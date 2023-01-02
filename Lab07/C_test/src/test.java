import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int xxx = 0; xxx < 10000; xxx++) {


            int N = in.nextInt();
            int[] a = new int[N];
            for (int i = 0; i < N; i++) {
                a[i] = in.nextInt();
            }

            int index = -1;


            for (int xx = 0; xx < N - 1; xx++) {


                index = -1;
                int min = Integer.MAX_VALUE;
                for (int i = 0; i < N; i++) {
                    if (a[i] != -1 && a[i] < min) {
                        min = a[i];
                        index = i;
                    }
                }
                int left = index - 1;
                while (left != -1) {
                    if (a[left] == -1) {
                        left--;
                    } else break;
                }
                int right = index + 1;
                while (right != N) {
                    if (a[right] == -1) {
                        right++;
                    } else break;
                }
                //   System.out.println(Arrays.toString(a));
                //  System.out.println(index);
                if (left != -1 && (right == N || (a[index] ^ a[left]) >= (a[index] ^ a[right]))) {
                    a[index] = (a[index] ^
                            a[left]) + 1;
                    a[left] = -1;
                } else {
                    a[index] = (a[index] ^ a[right]) + 1;
                    a[right] = -1;
                }
            }
            System.out.println(a[index]);
        }


    }
}
