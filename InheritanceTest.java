package week6;

class Parent {
	String name = "영조";
	void print() {
		System.out.println("나는" + name + "이다.");
	}
}

class Child extends Parent {
	String name = "사도세자";
	
	@Override
	void print() {
		System.out.println("나는 " + name + "이다.");
	}
}

public class InheritanceTest {
	public static void main(String[] args) {
		Parent p = new Child(); //등호 기준 왼쪽과 오른쪽이 다름  =>왼쪽은 부모, 오른쪽은 자식... upcasting 발생
		
		System.out.println(p.name);
		p.print();
	}
}