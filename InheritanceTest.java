package week6;

class Parent {
	String name = "����";
	void print() {
		System.out.println("����" + name + "�̴�.");
	}
}

class Child extends Parent {
	String name = "�絵����";
	
	@Override
	void print() {
		System.out.println("���� " + name + "�̴�.");
	}
}

public class InheritanceTest {
	public static void main(String[] args) {
		Parent p = new Child(); //��ȣ ���� ���ʰ� �������� �ٸ�  =>������ �θ�, �������� �ڽ�... upcasting �߻�
		
		System.out.println(p.name);
		p.print();
	}
}