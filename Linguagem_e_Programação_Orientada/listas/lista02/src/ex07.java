import java.util.Scanner;
public class ex07 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int aa = a;
		int quociente = 0;
		for(;aa >= b && b != 0;){
			aa = aa - b;
			++quociente;
		}
		System.out.println("quociente	= "+ quociente);
		System.out.println("resto		= "+ aa);
		sc.close();
	}
}
