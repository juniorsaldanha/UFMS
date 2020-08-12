import java.util.Scanner;
import java.text.DecimalFormat;
public class uri_1002 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double raio = sc.nextDouble();sc.close();
		pi(raio);
	}
	public static void pi(double raio){
		DecimalFormat df2 = new DecimalFormat(".####");
		double pi = 3.14159d;
		double area = (pi*(raio*raio));
		System.out.println("A=" + df2.format(area));
		//System.out.printf("A=%.4f%n", area);
	}
}
