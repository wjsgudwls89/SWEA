package com.basic;

import java.util.Arrays;
import java.util.Scanner;

public class SWEA_1954_D3_달팽이숫자 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for (int t = 0; t < tc; t++) {
		int n;
		n = sc.nextInt();
		int cnt = 1;
		int[][] arr = new int[n][n];
		int dx = 0, dy= 0;
		int dir = 0;
		
			
		System.out.printf("#%d \n",t+1);
		while(true) {
//			if(dy >= 0 && dx >=0 && dy < n && dx < n) {
			arr[dy][dx] = cnt;
			cnt++;
			if(cnt == n*n+1)
				break;
			if(dir == 0) {
				dx++;
				if(dx>=n || arr[dy][dx] != 0) {
					dx--;
					dir =1;
					dy++;
				}
			}
			else if(dir == 1) {
				dy++;
				if(dy>=n || arr[dy][dx] != 0) {
					dy--;
					dir =2;
					dx--;
				}
			}
			else if(dir == 2) {
				dx--;
				if(dx<0 || arr[dy][dx] != 0) {
					dx++;
					dir =3;
					dy--;
				}
			}
			else if(dir == 3) 
			{
				dy--;
				if(dy<0 || arr[dy][dx] != 0) {
					dy++;
					dir =0;
					dx++;
				}
			}
			//}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.printf("%d ",arr[i][j]);
			}
			System.out.println();
		}
	}
	}
}
