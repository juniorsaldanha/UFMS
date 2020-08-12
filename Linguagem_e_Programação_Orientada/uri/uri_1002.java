import java.util.*;
public class uri_1002{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		double pi = 3.14159d;
		double raio = scanner.nextDouble();
		double area = (pi*(raio*raio));
		System.out.printf("A=%.4f%n", area);
	}
}