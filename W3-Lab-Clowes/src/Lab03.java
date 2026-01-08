import LinearEquation.LinearEquation;

import LinearEquation.Point;

import java.util.Scanner;

/**
 * Class used to test Point and Linear Equation Classes.
 *
 * @author Ian Clowes
 */
public class Lab03 {

    /**
     * main used to test inputs and outputs
     * @param args
     */
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);


        System.out.print("Enter the Slope and Y-Intercept for Equation 1: ");
        double m1 = scanner.nextDouble();
        double b1 = scanner.nextDouble();
        System.out.print("Enter the Slope and Y-Intercept for Equation 2: ");
        double m2 = scanner.nextDouble();
        double b2 = scanner.nextDouble();

        LinearEquation e1 = new LinearEquation(m1, b1);
        LinearEquation e2 = new LinearEquation(m2, b2);

        if(LinearEquation.calculateIntercept(e1,e2) != null) {
            Point point =  LinearEquation.calculateIntercept(e1,e2);
            System.out.print("Intercept: " + "(" + point.getX() + ", " + point.getY() + ")");
        }
        else{
            System.out.print("No Intercept");
        }




    }
}
