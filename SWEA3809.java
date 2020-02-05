package com.ssafy.algo;

import java.util.Scanner;

public class SWEA3809 {
	static boolean flag;
	static int[] visit;
	static int test;
	
	public static void check(int k,int tc) {
		for (int i = 0; i < k; i++) {
			if(visit[i] == 0) {
				System.out.println("#"+(tc+1)+" "+i);
				flag = false;
				break;
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		test = sc.nextInt();
		for (int tc = 0; tc < test; tc++) {
		flag = true;
		visit = new int[100001];
		
		String str = "";
		int k = sc.nextInt();
		
		
		
		for (int i = 0; i < k; i++) {
			int n =sc.nextInt();
			str += Integer.toString(n);
		}
		
		
		int idx = 1;
		int range = 10;
		int length = str.length();
		while(flag) {
			for (int i = 0; i < length; i++) {
				visit[Integer.parseInt(str.substring(i,i+idx))] = 1;
				//System.out.println(str.substring(i,i+idx));
			}
			check(range,tc);
			range*=10;
			idx++;
			length--;
			
		}
		//System.out.println(idx);
	}
	}
}
