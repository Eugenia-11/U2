import java.util.Scanner;

public class week2for2 {

	public static void main(String[] args) {
		int x;
		String answer;
		Scanner in = new Scanner(System.in);
		System.out.print("������ �Է��ϼ��� : ");
		x = in.nextInt();
		answer = (x%2==0) ? "¦��" : "Ȧ��";
		System.out.println(answer);
		in.close();
	}

}
