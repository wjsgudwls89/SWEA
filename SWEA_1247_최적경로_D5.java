package algo_ad.day2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class SWEA_1247_최적경로_D5 {
	static int n;
	static List<cus> list = new ArrayList<>();
	static boolean visit[];
	static int[] temp;
	static int ans;
	public static int getAns() {
		int sum = 0;
		for (int i = 1; i < temp.length-1; i++) {
			sum +=getLen(list.get(temp[i-1]).y,list.get(temp[i-1]).x,list.get(temp[i]).y,list.get(temp[i]).x);
		}
		sum+=getLen(list.get(temp[n]).y, list.get(temp[n]).x, list.get(list.size()-1).y, list.get(list.size()-1).x);
		return sum;
	}
	public static int getLen(int y1,int x1,int y2,int x2) {
		int sum = Math.abs(x1-x2) + Math.abs(y1-y2);
		
		return sum;
	}
	public static void DFS(int depth,int start) {
		if(depth == list.size()-1) {
			//System.out.println(getAns());
			ans = Math.min(ans, getAns());
			return;
		}
		for (int i = 1; i < visit.length-1; i++) {
			if(!visit[i]) {
				visit[i] = true;
				temp[depth] = i;
				DFS(depth+1,i+1);
				visit[i] = false;
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int tc =sc.nextInt();
		
		for (int test = 0; test < tc; test++) {
			n = sc.nextInt();
			int sx = sc.nextInt();
			int sy = sc.nextInt();
			list.add(new cus(sx,sy));
			int ex = sc.nextInt();
			int ey = sc.nextInt();
			
			for (int i = 0; i < n; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				list.add(new cus(x,y));
			}
			list.add(new cus(ex,ey));
			temp = new int[list.size()];
			visit = new boolean[list.size()];
			ans = Integer.MAX_VALUE;
			DFS(1,1);
			System.out.println("#"+(test+1)+" "+ans);
			list.clear();
		}
	}
	static class cus{
		int x;
		int y;
		public cus(int x, int y) {
			super();
			this.y = y;
			this.x = x;
		}
		@Override
		public String toString() {
			return "cus [x=" + x + ", y=" + y + "]";
		}
		
	}

}
