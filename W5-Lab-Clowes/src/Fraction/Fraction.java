/**
 * Fraction.java
 *
 * @author Ian Clowes
 */
package Fraction;


/**
 * Fraction
 *
 * A class that represents a rational number (numerator/denominator) and can reduce itself
 */
public class Fraction {

    //fields
    private int numerator;
    private int denominator;

    /**
     * Fraction Constructor
     * @param numerator numerator
     * @param denominator denominator
     */
    public Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    //getters

    /**
     * getNumerator returns numerator
     * @return numerator
     */
    public int getNumerator() {
        return numerator;
    }

    /**
     * getDenominator returns denominator
     * @return denominator
     */
    public int getDenominator() {
        return denominator;
    }

    //behavior methods

    /**
     * reduce
     * Computes the GCD iteratively and divides both parts by the GCD to reduce the fraction in place.
     */
    public void reduce(){

        if (denominator == 0){
            System.out.print("Denominator Cannot equal zero");
            return;
        }
        else{
            int i = getGCD(numerator, denominator);
            numerator /= i;
            denominator /= i;

        }




    }

    /**
     * getGCD uses a loop to determine the greatest common divisor
     * @param numerator
     * @param denominator
     * @return greatest common divisor
     */
    private int getGCD(int numerator, int denominator){

        if (numerator == 0){
            return denominator;
        }
        if(numerator > denominator) {
            int i = numerator;
            while (numerator % i != 0 || denominator % i != 0) {
                i--;
            }
            return i;
        }

        else if(denominator > numerator){
            int i = denominator;
            while (numerator % i != 0 || denominator % i != 0) {
                i--;
            }
            return i;
        }

        return 0;
    }


}
