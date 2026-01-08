package GradeProcessing;

/**
 * InvalidPointsEarnedException.java
 * This class is an exception class, the exception is thrown when the points earned for an assignment is < 0
 *
 * @author Ian Clowes
 */
public class InvalidPointsEarnedException extends Exception {
    /**
     * InvalidPointsEarnedException
     * constructor for exceptions
     * @param points
     */
    public InvalidPointsEarnedException(double points) {
        super("ERROR: THE POINTS EARNED IS INVALID");
    }
}
