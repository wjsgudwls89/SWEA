package com.ex;

import java.util.Arrays;
import java.util.Scanner;

public class SWEA1220 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		for (int tc = 0; tc < 10; tc++) {
			int n = sc.nextInt();
			int[][] map = new int[n][n];
			int[][] temp = new int[n][n];

			for (int i = 0; i < map.length; i++) {
				for (int j = 0; j < map.length; j++) {
					map[i][j] = sc.nextInt();
				}
			}
			int cnt = 0;


			for (int i = 0; i < n; i++) {
				int idx = 0;
				for (int j = 0; j < n; j++) {
					if(map[j][i] != 0) {
						temp[i][idx] = map[j][i];
						idx++;
					}
				}

			}
			for (int i = 0; i < temp.length; i++) {
				for (int j = 0; j < temp.length-1; j++) {

					if(temp[i][j] == 1 & temp[i][j+1] == 2) cnt++;
				}
			}
			System.out.println("#"+(tc+1)+" "+cnt);
		}
	}
}
