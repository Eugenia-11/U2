import java.util.Scanner;

public class week2for2 {

	public static void main(String[] args) {
		int x;
		String answer;
		Scanner in = new Scanner(System.in);
		System.out.print("정수를 입력하세요 : ");
		x = in.nextInt();
		answer = (x%2==0) ? "짝수" : "홀수";
		System.out.println(answer);
		in.close();
	}

}
