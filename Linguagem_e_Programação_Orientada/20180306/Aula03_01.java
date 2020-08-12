import java.util.Scanner;
public class aula03_01{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		System.out.print("Entre com o valor da variavel 1: ");
		double var1 = sc.nextDouble(); //ou int var1 = sc.nextInt();
		System.out.print("Entre com o valor da variavel 2: ");
		String var2 = sc.nextLine();


		System.out.println("variavel var1 lida é: " + var1);
		System.out.println("variavel var2 lida é: " + var2);
		sc.close();//quando terminal a leitura;


	}
}