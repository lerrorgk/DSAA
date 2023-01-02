import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String inputStr = input.nextLine();
        String[] strArray = inputStr.split(" ");
        int[] num = new int[strArray.length];
        for (int i = 0; i < num.length; i++) {
            num[i] = Integer.parseInt(strArray[i]);
        }

        int dx = num[2] - num[0];
        int dy = num[3] - num[1];
        int max = dx + dy;
        BigInteger a = new BigInteger("1");
        BigInteger b = new BigInteger("1");

        if ((dx == 0) && (dy == 0)) {
            System.out.println("1");
        } else if ((dx == 0) || (dy == 0)) {
            System.out.println(Math.max(dx, dy));
        } else {
            for (int i = 1; i <= Math.min(dx, dy); i++) {
                a = a.multiply(BigInteger.valueOf(max - i + 1));
                b = b.multiply(BigInteger.valueOf(i));
            }
            BigInteger c = a.divide(b);
            System.out.println(c.remainder(BigInteger.valueOf(num[4])));
        }
    }
}
