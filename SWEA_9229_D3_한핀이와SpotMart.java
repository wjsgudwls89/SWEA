package com.basic;

import java.util.Scanner;

public class SWEA_9229_D3_한핀이와SpotMart {
//	static int cookie[];
//	static int visit[];
//	static int depth;
//	static int n,m;
//	static int ans = 0;
//	static int cnt = 0;
//	public static void DFS(int start, int depth,int sum) {
//		
//		if (sum>m) return;
//		if(depth == 2 && sum <= m) {
//			cnt++;
//			ans = Math.max(ans, sum);
//			return;
//		}
//		if(start == n) return;
//		
//					DFS(start+1,depth+1,sum+cookie[start]);
//					DFS(start+1,depth,sum);
//		}
//		
//	
//	public static void main(String[] args) {
//		// TODO Auto-generated method stub
//		Scanner sc = new Scanner(System.in);
//		int tc = sc.nextInt();
//		for (int time = 0; time < tc; time++) {
//			ans = -1;
//			n = sc.nextInt();
//			m = sc.nextInt();
//			cookie = new int[n];
//			visit = new int[n];
//			for (int i = 0; i < n; i++) {
//				cookie[i] = sc.nextInt();
//			}
//			DFS(0,0,0);
//			System.out.printf("#%d ",time+1);
//			System.out.println(ans);
//			System.out.println(cnt);
//		}
//	}
//	 static int cookie[];
//	    static int visit[];
//	    static int subset[][];
//	    static int depth;
//	    static int n,m;
//	    static int ans = 0;
//	    static int cnt = 0;
//	    public static void DFS(int start, int depth,int sum) {
//	    	if(sum>m)
//	    		return;
//	        if(depth == 2 && sum <= m) {
//	        	for (int i = 0; i < cookie.length; i++) {
//					System.out.printf("%d ",visit[i]);
//				}
//		    	System.out.println();
//	            ans = Math.max(ans, sum);
//	            cnt++;
//	            return;
//	        }
//	        else {
//	            for (int i = start; i < cookie.length; i++) {
//	                if(visit[i] == 0) {
//	                    visit[i] = 1;
//	                    DFS(i+1,depth+1,sum+cookie[i]);
//	                 
//	                    visit[i] = 0;
//	                }
//	            }
//	        }
//	    }
//	    public static void main(String[] args) {
//	        // TODO Auto-generated method stub
//	        Scanner sc = new Scanner(System.in);
//	        int tc = sc.nextInt();
//	        for (int time = 0; time < tc; time++) {
//	            ans = 0;
//	            n = sc.nextInt();
//	            m = sc.nextInt();
//	            cookie = new int[n];
//	            visit = new int[n];
//	            subset = new int[n][n];
//	            for (int i = 0; i < n; i++) {
//	                cookie[i] = sc.nextInt();
//	            }
//	            DFS(0,0,0);
//	            System.out.printf("#%d ",time+1);
//	            if(ans == 0) ans = -1;
//	            System.out.println(ans);
//	            System.out.println(cnt);
//	        }
//	    }

}
