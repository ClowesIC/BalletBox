package University;

import java.util.ArrayList;

/**
 * Student
 * creates a Student object that is capable of being utilized within the department
 * @author Ian Clowes
 */
public class Student extends Person {
    private String major;
    private String Name;
    private String Email;
    private String lastName;

    private ArrayList<Course> courses;

    /**
     * Student constructor
     *
     * @param lastName
     * @param Name
     * @param Email
     * @param major
     */
    public Student(String Email, String Name, String lastName, String major) {
        super(lastName, Name, Email);
        this.Name = Name;
        this.Email = Email;
        this.major = major;

        this.courses = new ArrayList<Course>();

    }

    /**
     * toString()
     * overriden toString() function for Staff class
     */
    @Override
    public String toString() {
        return ("Student:\n" + "ID: " + getID() + "\nName: " + getName() + " " +  getLastName() + "\nEmail: " + getEmail() + "\nMajor: " + getMajor() +"\n" + getCourses());
    }

    /**
     * getMajor
     *
     * @return major
     */
    public String getMajor(){
        return major;
    }

    /**
     * public method that adds course to list of student courses
     * @param course
     */
    public void addCourse(Course course) {
        if(courses != null) {
            courses.add(course);
        }
    }

    /**
     * getCourses
     * getter method that returns list of courses belonging to student
     */
    public String getCourses(){
            if(courses != null) {
                String output = "Courses Enrolled:\n";
                for (int i = 0; i < courses.size(); i++) {
                     output += courses.get(i).getCourseID() + " - " + courses.get(i).getCourseName() + "\n";
                }
                return output;
            }
            return "";
    }



}



