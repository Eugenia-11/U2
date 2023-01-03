package week3;

class Triangle {
private double side;
private double height;

public Triangle (double height, double side) {
this.height = height;
this.side = side;
}

public double getSide() {
return side;
}

public double getHeight() {
return height;
}

public double findArea( ) {
return side * height * 0.5;
}
}

public class TriangleTest {

public static void main(String[] args) {
Triangle t1 = new Triangle (10.0, 5.0);
System.out.println(t1.findArea());

}

}

