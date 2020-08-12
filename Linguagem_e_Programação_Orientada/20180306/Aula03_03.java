import java.util.Scanner;
public class Aula03_03{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Entrar com valor: ");
		int a = sc.nextInt();

		String p = a % 2 == 0 ? "Par" : "Impar";
		System.out.println(p);

	}
}