package com.ex;

import java.util.Arrays;
import java.util.Scanner;

public class SWEA5603 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int T = sc.nextInt();

		for (int t = 0; t < T; t++) {

			int n = sc.nextInt();
			int[] arr = new int[n];

			int sum = 0;
			for (int i = 0; i < arr.length; i++) {
				arr[i] = sc.nextInt();
				sum+=arr[i];
			}
			int avr = sum/n;
			Arrays.sort(arr);
			int cnt = 0;

			for (int i = 0; i < arr.length; i++) {

				if(arr[i] < avr) {
					cnt += arr[i]-avr;
				}
			}


			System.out.println("#"+(t+1)+" "+cnt*-1);
			cnt = 0;

		}
	}
}
