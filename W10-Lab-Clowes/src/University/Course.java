package University;

import java.util.ArrayList;

/**
 * Course
 * class used to create a course object, utilizes polymorphism to generate attributes based on other objects.
 * @author Ian Clowes
 */
public class Course{
    private String courseID;
    private String courseName;
    private String courseSession;
    private Faculty instructor;

    private ArrayList<Student> students;

    /**
     * Course constructor
     * @param courseID
     * @param courseName
     * @param courseSession
     */
    public Course(String courseID, String courseName, String courseSession) {
        this.courseID = courseID;
        this.courseName = courseName;
        this.courseSession = courseSession;
        this.students = new ArrayList<Student>();
    }

    /**
     * method that adds student to list of course's students
     * @param student
     */
    public void addStudent(Student student) {
        if(students != null) {
            students.add(student);
        }
    }

    /**
     * setInstructor
     * sets an instructor for course
     * @param faculty
     */
    public void setInstructor(Faculty faculty) {
        this.instructor = faculty;
    }

    /**
     * getCourseName
     * getter method for course name
     * @return
     */
    public String getCourseName(){
        return  courseName;
    }

    /**
     * getCourseID
     * method that returns course ID
     * @return
     */
    public String getCourseID(){
        return courseID;
    }

    /**
     * getCourseSession
     * method that returns course session
     * @return
     */
    public String getCourseSession(){
        return courseSession;
    }

    /**
     * getCourseInstructor
     * getter method to obtain instructor name
     * @return
     */
    public String getCourseInstructor(){
        return instructor.getName() + " " + instructor.getLastName();
    }

    /**
     * getStudentsEnrolled
     * method that returns list of students in course
     * @return
     */
    public String getStudentsEnrolled(){
        String output = "Students Enrolled:\n";
        if (students.size() > 0) {
            for (int i = 0; i < students.size(); i++) {
                output += students.get(i).getLastName() + ", " + students.get(i).getName() + "\n";
            }
            return output;
        }
        return "";
    }
    /**
     * overriden toString for Course class
     * @return string of course attributes
     */
    @Override
    public String toString() {
        return "Course: \n" +getCourseID() + " - " +
                getCourseName()+ "\n" + getCourseSession() + "\nTeaching Faculty: "
                +getCourseInstructor() +"\n" + getStudentsEnrolled() ;
    }
}
