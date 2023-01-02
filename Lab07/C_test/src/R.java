import java.util.Random;

public class R {
    public static void main(String[] args) {
        Random in=new Random();
        for (int xx = 0; xx < 10000; xx++) {


            int n = in.nextInt(100) + 50;
            System.out.println(n);
            for (int i = 0; i < n; i++) {
                System.out.print(in.nextInt(n) + " ");
            }
            System.out.println();
        }
    }
}
