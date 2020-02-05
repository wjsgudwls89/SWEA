import java.util.Scanner;

public class SWEA6805 {
    static int[] visit;
    static int[] avisit;
    static int[] temp;
    static int[] atemp;
    static int[] arr;
    static int a,b,acnt,bcnt;
    public static void DFS(int depth){
        if(depth == 9){
            a= 0; b=0;
            for (int i = 0; i < 9; i++) {
                if(atemp[i] > arr[i]){
                    a+=atemp[i] + arr[i];
                }
                else{
                    b+=atemp[i] + arr[i];
                }
            }
            if(a>b){acnt++;}
            else if(a<b){bcnt++;}
            else{
                return;
            }
            return;
        }
        for (int i = 0; i < 9; i++) {
            if(avisit[i] == 0){
                avisit[i] = 1;
                arr[depth] = temp[i];
                DFS(depth+1);
                avisit[i] = 0;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for (int tc = 1; tc <= T ; tc++) {
            visit = new int[19];
            avisit = new int[9];
            temp = new int[10];
            atemp = new int[9];
            arr = new int[9];


            for (int i = 0; i < 9; i++) {
                int ku = sc.nextInt();
                visit[ku] = 1;
                  atemp[i] = ku;
            }
            int idx = 0;
            for (int i = 1; i <= 18; i++) {
                if(visit[i] == 0){
                    temp[idx] = i;
                    idx++;
                }
            }
            DFS(0);
            System.out.println("#"+(tc)+" "+acnt+" "+bcnt);
            acnt = 0; bcnt = 0;
        }
    }
}
