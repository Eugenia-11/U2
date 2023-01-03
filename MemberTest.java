package week3;

class Member {
    private String name;
    private String id;
    private String pw;
    private int age;

    public Member(String name, String id, String pw, int age) {
        this.name = name;
        this.id = id;
        this.pw = pw;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }
    public String getPw() {
        return pw;
    }

    public int getAge() {
        return age;
    }
    
    public void setName(String name) {
    this.name = name;
    }
    
    public void setPw(String pw) {
    this.pw = pw;
    }
    
    public void setAge(int age) {
    this.age = age;
    }
}
public class MemberTest{
public static void main(String[] args) {
Member mem1 = new Member("대한민국","apple","1234",20);
System.out.println("이름:대한민국");
System.out.println("아이디:apple");
System.out.println("나이:20");
}
}
