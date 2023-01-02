import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int th = 0; th < T; th++) {
            String text = sc.next();
            int n = sc.nextInt();
            String []patterns = new String[n];
            for (int i = 0; i < n; i++) {
                patterns[i] = sc.next();
            }

            int [] bestSubstr = new int[text.length()];
            for(int i = 0; i < text.length(); i++){
                int maxL = 0, index = -1;
                for(int j = 0; j < n; j++){
                    int pSize = patterns[j].length();
                    int endIndex = i + pSize - 1;
                    if(endIndex > text.length() - 1){
                        continue;
                    }
                    String pa = text.substring(i, endIndex + 1);
                    if(pSize > maxL && patterns[j].equals(pa)){
                        maxL = pSize;
                        index = j;
                    }
                }
                bestSubstr[i] = index;
            }

//            for(int k = 0; k < text.length(); k++){
//                System.out.print(bestSubstr[k]);
//                System.out.print(" ");
//            }
//            System.out.println();

            int count = 0;
            int [][] results = new int[text.length()][2];
            int left = -1, right = - 1;
            while(right < text.length() - 1){
                int substrIndex = -1, startIndex = -1;
                int maxEndIndex = right;
                for(int i = left + 1; i <= right + 1; i++){
                    if(bestSubstr[i] == -1){
                        continue;
                    }
                    int index = i + patterns[bestSubstr[i]].length() - 1;
                    if(index > maxEndIndex){
                        maxEndIndex = index;
                        substrIndex = bestSubstr[i];
                        startIndex = i;
                    }
                }
                if(maxEndIndex == right){
                    count = -1;
                    break;
                }
                results[count][0] = substrIndex + 1;
                results[count][1] = startIndex + 1;
                count++;
                left = startIndex;
                right = maxEndIndex;
            }
            if(count == -1){
                System.out.println(count);
                continue;
            }
            System.out.println(count);
            for(int i = 0; i < count; i++){
                System.out.print(results[i][0]);
                System.out.print(" ");
                System.out.println(results[i][1]);
            }
        }
    }
}
