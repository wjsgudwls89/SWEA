package com.ex;

import java.util.Arrays;
import java.util.Scanner;

public class SWEA1234 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		for (int tc = 0; tc < 10; tc++) {


			String str = "";

			int n = sc.nextInt();

			int[] pw = new int[n];
			int[] temp = new int[n];
			int[] visit = new int[n];
			//sc.next();

			str = sc.nextLine();
			for (int i = 1; i < str.length(); i++) {
				pw[i-1] = str.charAt(i) - '0';
			}
			for (int as = 0; as < pw.length/2; as++) {
				for (int i = 0; i < pw.length-1; i++) {
					if((pw[i] == pw[i+1]) && visit[i] == 0) {
						visit[i] = 1;
						visit[i+1] = 1;
						int left = i;
						int right = i+1;
						while(true) {
							left --; right++;
							if(left<0 || right>pw.length-1) break;

							if(pw[left] == pw[right] && (visit[left] != 1 && visit[right]!=1)) {
								visit[left] = 1;
								visit[right] = 1;
							}
							else {
								break;
							}
						}
					}
				}
				int idx = 0;
				
				for (int i = 0; i < pw.length; i++) {
					if(visit[i] == 0) {
						temp[idx] = pw[i];
						idx++;
					}
				}
				System.out.println(idx);
				//System.out.println(Arrays.toString(temp));
				pw = new int[idx];
				for (int i = 0; i < idx; i++) {
					pw[i] = temp[i];
				}
				System.out.println(Arrays.toString(pw));
				//System.out.println(pw.length);
				visit = new int[idx];
				
			}
			System.out.printf("#%d ",tc+1);
			for (int i = 0; i < pw.length; i++) {
				
				//ystem.out.printf("%d",pw[i]);
			}
			System.out.println();
		}
	}
}
//#1 1234
//#2 4123
//#3 123123
//#4 1234123123
//#5 12341
//#6 123535
//#7 123432141
//#8 231231321
//#9 12312323
//#10 9823