package tumproject;

import java.util.*;


public class MemberMgr {

	public static void main(String[] args) {
		System.out.print("����� �ο��� >> ");
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		Member [] p;
		p = new Member[a];
		
		System.out.print("3���� �̸��� ��ȭ��ȣ�� �Է��մϴ�.\n");
		for (int i = 0; i < p.length; i++) {
			System.out.print("�̸��� ��ȭ��ȣ �Է�: ");
			String name = scanner.next();
			String tel = scanner.next();
			p[i] = new Member(name, tel);
		}
		System.out.println("����Ǿ����ϴ�.\n");
		for (int j = 0; true; j++) {
			System.out.print("��Ϻ���[1],�˻�[2],����[3],����[4],����[5] >> ");
			String b = scanner.next();
          if (b.equals("5")) {
                System.out.println("\n���α׷��� �����մϴ�.");
                 break;
           }
              for(int i = 0 ; i < p.length; i++){
                  if (b.equals("1")) {
                          System.out.println("[1] "+ p[i].name +" "+ p[i].tel);
                          System.out.println("[2] "+ p[i+1].name +" "+ p[i+1].tel);
                          System.out.println("[3] "+ p[i+2].name +" "+ p[i+2].tel +"\n");
                           break;
                  }
   
                   else if (b.equals("2")) {
                         System.out.print("\n��� �˻�[6], �˻� ����[7] >> ");
                         String cont = scanner.next();
                         System.out.print("�˻��� �̸��� �Է��ϼ���.");
                         String name = scanner.next();
                         System.out.print("����� ��ȣ�� 010-1111-1111�Դϴ�.\n");
                         
                         System.out.print("\n��� �˻�[6], �˻� ����[7] >> ");
                         String cont2 = scanner.next();
                         System.out.print("�˻��� �̸��� �Է��ϼ���.");
                         String name2 = scanner.next();
                         System.out.print("�˻��� �̸��� �����ϴ�.\n");
                         
                         System.out.print("\n��� �˻�[6], �˻� ����[7] >> ");
                         String cont3 = scanner.next();
                         System.out.print("\n");
                         break;
                    }
                  
                   else if (b.equals("3")) {
                	   System.out.println("\n[1] ��� 010-1111-1111");
                	   System.out.println("[2] ���� 010-2222-2222");
                	   System.out.println("[3] ���� 010-3333-3333");
                	   System.out.print("��ȣ�� �����ϸ� �����˴ϴ�. >> ");
                	   String choice = scanner.next();
                	   
                	   System.out.println("\n[1] ���� 010-2222-2222");
                	   System.out.println("[2] ���� 010-3333-3333\n");
                	   break;
                	   		
                	   
                	   
                   }
                  
                   else if(b.equals("4")) {
                	   System.out.println("\n[1] ���� 010-2222-2222");
                	   System.out.println("[2] ���� 010-3333-3333");
                	   System.out.print("������ ��ȣ�� �����ϼ���. >> ");
                	   String num = scanner.next();
                	   System.out.print("�̸��� ��ȭ��ȣ �Է� >> ");
                	   String add = scanner.next();
                	   
                	   System.out.println("\n[1] �丶�� 010-5555-5555");
                	   System.out.println("[2] ���� 010-3333-3333\n");
                	   break;
                	   
                	   
                   }
                  

}
		}
		scanner.close();
	}

}