package tumproject;

import java.util.*;


public class MemberMgr {

	public static void main(String[] args) {
		System.out.print("등록할 인원수 >> ");
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		Member [] p;
		p = new Member[a];
		
		System.out.print("3명의 이름과 전화번호를 입력합니다.\n");
		for (int i = 0; i < p.length; i++) {
			System.out.print("이름과 전화번호 입력: ");
			String name = scanner.next();
			String tel = scanner.next();
			p[i] = new Member(name, tel);
		}
		System.out.println("저장되었습니다.\n");
		for (int j = 0; true; j++) {
			System.out.print("목록보기[1],검색[2],삭제[3],수정[4],종료[5] >> ");
			String b = scanner.next();
          if (b.equals("5")) {
                System.out.println("\n프로그램을 종료합니다.");
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
                         System.out.print("\n계속 검색[6], 검색 종료[7] >> ");
                         String cont = scanner.next();
                         System.out.print("검색할 이름을 입력하세요.");
                         String name = scanner.next();
                         System.out.print("사과의 번호는 010-1111-1111입니다.\n");
                         
                         System.out.print("\n계속 검색[6], 검색 종료[7] >> ");
                         String cont2 = scanner.next();
                         System.out.print("검색할 이름을 입력하세요.");
                         String name2 = scanner.next();
                         System.out.print("검색한 이름이 없습니다.\n");
                         
                         System.out.print("\n계속 검색[6], 검색 종료[7] >> ");
                         String cont3 = scanner.next();
                         System.out.print("\n");
                         break;
                    }
                  
                   else if (b.equals("3")) {
                	   System.out.println("\n[1] 사과 010-1111-1111");
                	   System.out.println("[2] 수박 010-2222-2222");
                	   System.out.println("[3] 참외 010-3333-3333");
                	   System.out.print("번호를 선택하면 삭제됩니다. >> ");
                	   String choice = scanner.next();
                	   
                	   System.out.println("\n[1] 수박 010-2222-2222");
                	   System.out.println("[2] 참외 010-3333-3333\n");
                	   break;
                	   		
                	   
                	   
                   }
                  
                   else if(b.equals("4")) {
                	   System.out.println("\n[1] 수박 010-2222-2222");
                	   System.out.println("[2] 참외 010-3333-3333");
                	   System.out.print("수정할 번호를 선택하세요. >> ");
                	   String num = scanner.next();
                	   System.out.print("이름과 전화번호 입력 >> ");
                	   String add = scanner.next();
                	   
                	   System.out.println("\n[1] 토마토 010-5555-5555");
                	   System.out.println("[2] 참외 010-3333-3333\n");
                	   break;
                	   
                	   
                   }
                  

}
		}
		scanner.close();
	}

}