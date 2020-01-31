package algo_basic.day5;

import java.util.Scanner;
import java.util.Stack;

public class SWEA1218_괄호짝짓기_D4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		for (int tc = 0; tc < 10; tc++) {


			int k = sc.nextInt();
			sc.nextLine();
			String str = sc.nextLine();
			Stack s = new Stack<>();
			String[] check = {"<>","{}","()","[]"};

			boolean flag = true;
			boolean match = false;
			for (int i = 0; i < str.length(); i++) {
				if(str.charAt(i) == '(' || str.charAt(i) == '[' || str.charAt(i) == '{' || str.charAt(i) == '<') {
					s.push(str.charAt(i));
				}
				else if(str.charAt(i) == ')' || str.charAt(i) == ']' || str.charAt(i) == '}' || str.charAt(i) == '>'){
					String add = s.peek()+""+str.charAt(i);
					match = false;
					for (int j = 0; j < check.length; j++) {

						if(check[j].equals(add)) {
							match = true;

						}
					}
					if(!s.isEmpty() && match) {
						s.pop();
					}else {
						flag = false;
						match = false;
						break;
					}

				}


			}
			int ans = 0;
			if(flag &&s.isEmpty()) ans = 1;
			System.out.println("#"+(tc+1)+" "+(ans));
		}
	}
}
