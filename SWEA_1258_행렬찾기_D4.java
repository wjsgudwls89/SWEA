package com.ssafy.algo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class SWEA_1258_행렬찾기_D4 {

	static int[][] map = new int[101][101];
	static int[][] visit = new int[101][101];
	static int n;
	static int nx = 1,ny = 1;
	static List<ma> ans = new ArrayList<>();
	public static void find(int y,int x) {
		ny = 1;
		nx = 1;
		int a = x;
		int b = y;
		while(true) {
			a++;
			if(map[y][a] == 0) break;
			nx++;
		}
		while(true) {
			b++;
			if(map[b][x] == 0) break;
			ny++;
		}
		for (int i = y; i < y+ny; i++) {
			for (int j = x; j < x+nx; j++) {
				visit[i][j] = 1;
			}
		}
		ans.add(new ma(ny,nx));
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int time = 0; time < tc; time++) {

			visit = new int[101][101];
			n = sc.nextInt();

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					map[i][j] = sc.nextInt();
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if(map[i][j] != 0 && visit[i][j] == 0) {
						find(i,j);
					}
				}
			}
			ans.sort(new Comparator<ma>() {

				@Override
				public int compare(ma o1, ma o2) {
					// TODO Auto-generated method stub
					int a = o1.y * o1.x;
					int b = o2.y * o2.x;
					if(a>b) return 1;
					else if(a==b) {
						if(o1.y>o2.y)
							return 1;
						return -1;
					}
					else
						return -1;
				}
			});
			System.out.print("#"+(time+1)+" "+ans.size()+" ");
			for (int i = 0; i < ans.size(); i++) {
				System.out.print(ans.get(i).y +" " + ans.get(i).x+" ");
			}
			System.out.println();
			ans.clear();

		}
	}
	static class ma{
		int y;
		int x;
		public ma(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
		@Override
		public String toString() {
			return "ma [y=" + y + ", x=" + x + "]";
		}
	}

}
