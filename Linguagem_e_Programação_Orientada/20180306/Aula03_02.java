import java.util.Scanner;
public class Aula03_02{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Entrar com valor: ");
		int a = sc.nextInt();

		if(a % 2 == 1){
			System.out.println("O valor é Impar!");
		}else{
			System.out.println("O valor é Par!");
		}
	}
}