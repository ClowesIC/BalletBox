import BankAccount.BankAccount;

import java.util.Scanner;

/**
 * Lab07
 *
 * A class that implements console runner code to use Bank Account class
 *
 * @author Ian Clowes
 */
public class Lab07 {

    public static void main(String[] args){
        int initialDeposit = -1;
        int choice = 0;
        Scanner scanner = new Scanner(System.in); //create scanner

        while(initialDeposit < 0) {
            System.out.println("Welcome to the Bank of Behrend!");
            System.out.println("Please enter your initial deposit");
            initialDeposit = scanner.nextInt();
            if (initialDeposit < 0) {
                System.out.println("Deposit must be positive!");
                continue;
            }
            else {
                break;
            }
        }

        BankAccount bankAccount = new BankAccount(initialDeposit);
        System.out.println("Your new account number is: " + bankAccount.getAccountNumber());
        System.out.printf("Your balance is: %.2f", bankAccount.getBalance());

        do {
            System.out.println("\nPlease select an option: ");
            System.out.println("1: View Account Balance.");
            System.out.println("2: Deposit funds.");
            System.out.println("3: Withdraw funds. ");
            System.out.println("-1: Quit. ");
            //setup switch case to prompt continuation of app
            int num;
            switch (num = scanner.nextInt()) {
                case 1:
                    System.out.printf("Your account Balance is: %.2f", bankAccount.getBalance());
                    break;
                case 2:
                    System.out.println("Please enter your deposit amount: ");
                    double depositAmount = scanner.nextDouble();
                    bankAccount.deposit(depositAmount);
                    break;
                case 3:
                    System.out.println("Please enter your withdrawal amount: ");
                    double withdrawAmount = scanner.nextDouble();
                    bankAccount.withdraw(withdrawAmount);
                    break;
                case -1:
                    choice = -1;
                    break;
                default:

            }
        }while(choice != -1);


    }
}
