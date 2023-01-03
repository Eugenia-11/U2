package week11;

import java.util.Arrays;

public class Token {
	public static void main(String[] args) {
		
		String sentence = new String("you are opening up future doors and possibilities");
	
		String[] s = sentence.split(" ");
		Arrays.sort(s);
		
		System.out.println("입력 : " + sentence);
		System.out.println("단어 개수 : " + s.length);
		System.out.print("정렬된 토큰 : ");
		
		for (String s1 : s) {
		
			System.out.print(s1 + ", ");
			
		}
		
	}
}
