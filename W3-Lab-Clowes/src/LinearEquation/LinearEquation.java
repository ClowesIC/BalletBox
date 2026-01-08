
package LinearEquation;

/**
 * LinearEquation.java
 * A class that holds information for and calculates linear equations
 *
 * @author Ian Clowes
 */
public class LinearEquation {
    private final double m; //slope
    private final double b; //y intercept

    /**
     * constructor for LinearEquation class
     * @param m slope
     * @param b y intercept
     */
    public LinearEquation(double m, double b) {
        this.m = m;
        this.b = b;
    }

    //Getters:

    /**
     * Gives value of M (slope)
     * @return m
     */
    public double getM(){
        return m;
    }

    /**
     * gives value of B (y-intercept)
     * @return b
     */
    public double getB(){
        return b;
    }

    /**
     * returns the value of y of a linear equation
     * @param x x-coordinate of point
     * @return y-coordinate of linear equation
     */
    public double yAT(double x){
        return m * x + b;
    }

    /**
     * calculates the intersection of two linear equations
     * @param e1 first linear equation
     * @param e2 second linear equation
     * @return null if lines are parallel, or an intercept
     */
    public static Point calculateIntercept(LinearEquation e1, LinearEquation e2){



        if(e1.m == e2.m){ //lines are parallel
            return null;
        }
        else {
            double xintercept = (e1.b - e2.b) / (e1.m - e2.m);
            double yintercept = e1.yAT(xintercept);
            return new Point(xintercept, yintercept);

        }
    }

}
