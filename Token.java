package week11;

import java.util.Arrays;

public class Token {
	public static void main(String[] args) {
		
		String sentence = new String("you are opening up future doors and possibilities");
	
		String[] s = sentence.split(" ");
		Arrays.sort(s);
		
		System.out.println("�Է� : " + sentence);
		System.out.println("�ܾ� ���� : " + s.length);
		System.out.print("���ĵ� ��ū : ");
		
		for (String s1 : s) {
		
			System.out.print(s1 + ", ");
			
		}
		
	}
}
