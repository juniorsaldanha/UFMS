import java.util.Scanner;
class Fahrenheit2Celsius{
	private double cel;
	Fahrenheit2Celsius(double fah){
		this.cel = ((fah-32.0)*(5.0/9.0));
	}
	public void print_cel() {
		System.out.println("Celsius = " + this.cel);
	}
}

public class ex09{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double p = sc.nextDouble();sc.close();
		Fahrenheit2Celsius aa = new Fahrenheit2Celsius(p);
		aa.print_cel();
	}
}