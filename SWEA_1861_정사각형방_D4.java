package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class SWEA_1861_정사각형방_D4 {
	static int N;
	static int[][] map;
	static boolean[][] visit;
	static int cnt = 0;
	static List<POS> ans = new ArrayList<>();
	static int dx[] = {1,0,-1,0};

	static int dy[] = {0,-1,0,1};

	public static void BFS(int ay,int ax) {
		Queue<Integer> xq = new LinkedList<>();
		Queue<Integer> yq = new LinkedList<>();
		visit[ay][ax] = true;

		xq.offer(ax);
		yq.offer(ay);

		while(!xq.isEmpty()) {
			int qs = xq.size();

			while(qs>0) {
				int x = xq.poll();
				int y = yq.poll();

				for (int i = 0; i < 4; i++) {
					int nx  = x + dx[i];
					int ny  = y + dy[i];

					if(nx>=0 && ny>=0 && nx<N && ny<N && !visit[ny][nx] && 
							map[ny][nx] == map[y][x] +1) {
						visit[ny][nx] = true;
						xq.offer(nx);
						yq.offer(ny);

					}
				}
				qs--;
			}
			cnt++;
		}
		ans.add(new POS(map[ay][ax],cnt));
		cnt = 0;
		return;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
        int T = Integer.parseInt(br.readLine());
        for(int tc=1;tc<=T;tc++) {
            N = Integer.parseInt(br.readLine());
            map = new int[N][N];
           
            for(int i=0;i<N;i++) {
               
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					visit = new boolean[N][N];
					 BFS(i,j);
				}
			}
			//System.out.println(Arrays.deepToString(map));

			ans.sort(new Comparator<POS>() {

				@Override
				public int compare(POS o1, POS o2) {
					// TODO Auto-generated method stub
					int a = o1.cnt;
					int b = o2.cnt;
					if(a>b) return -1;
					else if(a==b){
						int c = o1.num;
						int d = o2.num;
						if(c>d) return 1;
						return -1;
					}
					else return 1;
				}
			});
			System.out.print("#"+(tc)+" "+ans.get(0).num+" "+ans.get(0).cnt+"\n");
			ans.clear();
		}
	}
	static class POS{
		int num;
		int cnt;
		public POS(int num, int cnt) {
			super();
			this.num = num;
			this.cnt = cnt;
		}
		@Override
		public String toString() {
			return "POS [num=" + num + ", cnt=" + cnt + "]";
		}

	}

}
