/**
 * Provides the necessary classes to manage our linear equations and points.
 */
package LinearEquation;

/**
 * Point.java
 * The point class contains the x,y coordinates for a point on the Cartesian plane.
 *
 * @author Ian Clowes
 */
public class Point {

    private final double x;
    private final double y;

    /**
     * constructor to create a point on the Cartesian plane
     * @param x stores the x-coordinate of our point
     * @param y stores the y-coordinate of our point
     */
    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Getter for the X value of our point
     * @return x value
     */
    public double getX(){
        return x;
    }

    /**
     * Getter for the Y value of our point
     * @return Y value
     */
    public double getY(){
        return y;
    }
}
