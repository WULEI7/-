class MyRectangle {
	private double length;
	private double width;
	public MyRectangle(double length,double width) {
		this.length=length;
		this.width=width;
	}
	public double getLength() {
		return length;
	}
	public double getWidth() {
		return width;
	}
	public void setLength(double length) {
		this.length=length;
	}
	public void setWidth(double width) {
		this.width=width;
	}
	public double getArea() {
		return length*width;
	}
	public String toString()
	{
		return "矩形，长为："+getLength()+"，宽为："+getWidth()+"，面积为："+getArea();
	}
}

class MySquare extends MyRectangle{
	public MySquare(double sideLength) {
		super(sideLength,sideLength);
	}
	public double getSideLength() {
		return super.getLength();
	}
	public void setSideLength(double sideLength) {
		super.setLength(sideLength);
		super.setWidth(sideLength);
	}
	public String toString() {
		return "正方形，边长为："+getLength()+"，面积为："+getArea();
	}
}

public class Main {
	public static void main(String[] args) {
		MyRectangle rectangle=new MyRectangle(2,3);
		MySquare square=new MySquare(4);
		System.out.println(rectangle.toString());
		System.out.println(square.toString());
	}
}
