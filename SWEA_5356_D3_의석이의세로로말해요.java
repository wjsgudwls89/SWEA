package com.basic;

import java.util.Scanner;

public class SWEA_5356_D3_의석이의세로로말해요 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		
		char[][] words;
		String[] str;
		sc.nextLine();
		
		for (int i = 0; i < T; i++) {
			String a="";
			words = new char[5][15];
			str = new String[5];
			int max = 0;
			for (int j = 0; j < str.length; j++) {
				str[j] = sc.nextLine();
				max = Math.max(max, str[j].length());
				words[j] = str[j].toCharArray();
			}
			for (int j = 0; j < max; j++) {
				for (int k = 0; k < 5; k++) {
					if(j >= words[k].length)
						continue;
					a += words[k][j];
				}
			}
			System.out.printf("#%d ",i+1);
			System.out.println(a);
		}
	
	}
}
