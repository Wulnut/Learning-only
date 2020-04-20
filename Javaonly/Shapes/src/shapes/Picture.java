package shapes;

import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;

// Picture是一个继承JFrame的一个类
public class Picture extends JFrame {

	// static表示不属于任何一个函数，而是一个类又称类变量，final表示无法被继承所以static final可以类似的表示为该类的静态变量

	private static final long serialVersionUID = 1L;
	private int width;
	private int height;

	// 构造了一个形状容器
	private ArrayList<Shape> listShape = new ArrayList<Shape>();
	
	private class ShapesPanel extends JPanel {
		private static final long serialVersionUID = 1L;

		// 虽然不能重写父类protected的函数，但是是可以重写子类的protected
		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			for ( Shape s : listShape )
			{
				s.draw(g);
			}			
		}
		
	}
	
	public void add(Shape s)
	{
		listShape.add(s);
	}

	public Picture(int width, int height)
	{
		add(new ShapesPanel());
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.width = width;
		this.height = height;
	}
	
	public void draw()
	{
		setLocationRelativeTo(null);
		setSize(width, height);
		setVisible(true);
	}
}