import java.util.Scanner;
public class Aula03_04{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Operação: ");
		char operacao = sc.next().charAt(0);
		int a = sc.nextInt();
		int b = sc.nextInt();

		switch(operacao){
			case '+':
				System.out.println("SOMA = " + (a + b));
				break;
			case '-':
				System.out.println("SUBTRAÇÃO = " + (a - b));
				break;
			case '*':
				System.out.println("MULTIPLICAÇÃO = " + (a * b));
				break;
			case '/':
				System.out.println("DIVISÃO = " + (a / b));
				break;

			default:
				System.out.println("ERROOO..");
				break;
		}

	}
}