package algo_ad.day2;

import java.util.Scanner;

public class SWEA_2817_부분수열의합_D3 {
	static int n,k;
	static int[] arr;
	static boolean[] visit;
	static int cnt=0;
	public static void DFS(int depth,int sum) {
		if(sum == k) {
			cnt++;
			return;
		}
		for (int i = depth; i < n; i++) {
			if(!visit[i]) {
				visit[i] = true;
				sum+=arr[i];
				DFS(i+1,sum);
				sum-=arr[i];
				visit[i] = false;
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int t = 0; t < tc; t++) {


			n= sc.nextInt();
			k= sc.nextInt();
			arr = new int[n];
			visit = new boolean[n];
			for (int i = 0; i < n; i++) {
				arr[i] = sc.nextInt();
			}
			cnt=0;
			DFS(0,0);
			System.out.println("#"+(t+1)+" "+cnt);
		}
	}

}
