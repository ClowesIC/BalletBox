import Fraction.Fraction;
import java.util.Scanner;

/**
 * Lab05
 *
 * class used to test and utilize Fraction Package and Fraction Class.
 */
public class Lab05 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numerator = 1;
        int denominator = 1;

        while (numerator != 0 && denominator != 0) {

            System.out.print("Enter a numerator and denominator (0 0 to quit): ");
            numerator = scanner.nextInt();
            denominator = scanner.nextInt();

            //check if quitting
            if(numerator == 0 && denominator == 0){
                System.out.print("quitting...");
                break;
            }

            //check if denominator is zero
            if (denominator == 0){
                System.out.println("Denominator Cannot equal zero");
                //change denominator so while loop can continue
                denominator = 1;

            }
            else { //if denominator is not zero

                //construct fraction
                Fraction fraction = new Fraction(numerator, denominator);

                //print users fraction
                System.out.println("The original fraction is: " + fraction.getNumerator() + " / " + fraction.getDenominator());

                //call reduce
                fraction.reduce();

                if (fraction.getDenominator() == 1) {
                    System.out.println("The reduced fraction is a whole number : " + fraction.getNumerator());
                } else {
                    System.out.println("The reduced fraction is: " + fraction.getNumerator() + " / " + fraction.getDenominator());
                }

            }

        }
    }



}
