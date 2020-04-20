package shapes;


/***
 * 抽象函数：表达概念而无法实现具体代码的函数
 * 抽象类：表达概念而无法构造出实体的类， 如果一个类里面有一个抽象函数，那么这个类就是一个抽象类
 * 带有abstract修饰的函数
 */


import java.awt.Graphics;

public abstract class Shape {
	
	public abstract void draw(Graphics g);
	
}
