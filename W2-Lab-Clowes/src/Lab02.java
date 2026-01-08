import java.util.Scanner;

/**
 * Lab02.java:
 * Lab02 class used to further develop and test Accountant.java class.
 *
 * @author Ian Clowes
 */

public class Lab02 {
    /**
     * main
     * @param args
     */
    public static void main(String[] args){
        //variables for Class
        int age;
        String name;
        String companyName;


        //scanner object
        Scanner scanner = new Scanner(System.in);

        //terminal prints
        System.out.print("Enter your name: ");
        name = scanner.nextLine();
        System.out.print("Enter your age: ");
        age = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter your company name: ");
        companyName = scanner.nextLine();

        //create Accountant Object using constructor
        Accountant Accountant = new Accountant(name, age, companyName);

        //test display method
        Accountant.displayMethod();

        //test Salary Calculation method
        System.out.printf("Salary: %.2f\n", Accountant.salaryCalculation());
    }
}
