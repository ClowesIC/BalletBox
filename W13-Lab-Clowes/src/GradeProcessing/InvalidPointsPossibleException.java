package GradeProcessing;

/**
 * InvalidPointsPossibleException
 * An exception that is thrown when there is an invalid number of points possible (when points possible is <= 0)
 * @author Ian Clowes
 */
public class InvalidPointsPossibleException extends Exception {
    /**
     * InvalidPointsPossibleException
     * constructor for exceptions
     * @param points
     */
    public InvalidPointsPossibleException(double points) {
        super("ERROR: THE POINTS POSSIBLE IS INVALID");
    }

}
