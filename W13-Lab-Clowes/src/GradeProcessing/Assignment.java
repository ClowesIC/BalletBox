/**
 * GradeProcessing.java
 * package that holds tests and Analyzes data from a given "Assignment text file"
 * @author Ian Clowes
 */
package GradeProcessing;

/**
 * Assignment.java
 *Validates the assignments given from the assignment text file, throws exceptions if some validations are not met.
 */
public class Assignment {
    public double pointsPossible;
    public double pointsEarned;
    public String assignmentName;
    public int percentage;
    public int index;

    /**
     * Assignment constructor
     * @param index
     * @param assignmentName
     * @param pointsPossible
     * @param pointsEarned
     * @param percentage
     * @throws InvalidPointsPossibleException
     * @throws InvalidPointsEarnedException
     */
    public Assignment(int index, String assignmentName, double pointsPossible, double pointsEarned,int percentage) throws InvalidPointsPossibleException,InvalidPointsEarnedException {
        this.pointsPossible = pointsPossible;
        this.pointsEarned = pointsEarned;
        this.assignmentName = assignmentName;
        this.percentage = percentage;
        this.index = index;

        if(pointsPossible <= 0){
            throw new InvalidPointsPossibleException(pointsPossible);
        }
        else if(pointsEarned < 0){
            throw new InvalidPointsEarnedException(pointsEarned);
        }
    }

    @Override
    /**
     * toString function
     * overrided to fit Assignment class
     */
    public String toString() {
        return ("Index: " + index +"\nAssignment Name: " + assignmentName + "\nPoints Possible: " + pointsPossible + "\nPoints Earned: " + pointsEarned + "\nPercentage: " + percentage);
    }

}
