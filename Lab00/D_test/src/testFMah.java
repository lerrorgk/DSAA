import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class testFMah {
    public static void main(String[] args) {
        Random R=new Random();
        int T=2000000;
        System.out.println(T);

        for (int i = 0; i < T; i++) {
            for(int j = 0; j < 14; j++){
                char qt=trans(R.nextInt(4)+1);
                int qtn;
                if(qt=='z')
                    qtn=R.nextInt(7)+1;
                else qtn=R.nextInt(9)+1;
                System.out.print(""+qtn+qt);
            }
            System.out.println();

        }
    }

    static char trans(int a){
        if(a==1){
            return 'z';
        }else if(a==2){
            return 's';
        }else if(a==3){
            return 'w';
        }else{
            return 'b';
        }
    }


}

