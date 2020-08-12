class Rectangle {
	int width = 0; 
	int height = 0; 
	Point origin; // construtores
	Rectangle() {
		origin = new Point(0, 0);
	}
	Rectangle(Point p) {
		origin = p;
	}
	Rectangle(int w, int h) {
		this(new Point(0, 0), w, h);
	}
	Rectangle(Point p,int w, int h){
		origin = p;
		width = w;
		height = h;
	}
// move o retângulo de posição 
	void move( int x,  int y) {
		origin.x = x;
		origin.y = y;
	}
// retorna a área do retângulo 
	int area() {
		return width * height;
	}
	public static void main(String[] args) {
		Rectangle myRect = new Rectangle();
		myRect.width = 40;
		myRect.height = 50;
		System.out.println("myRect's area is " + myRect.area());
	}
}