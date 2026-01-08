package University;

import java.util.ArrayList;

/**
 * Faculty class that defines a faculty object
 *
 * @author Ian Clowes
 */
public class Faculty extends Person{
   private String research;
   private String lastName;
   private String Name;
   private String Email;

   private ArrayList<Course> courses;

    /**
     * faculty constructor
     * @param lastName
     * @param Name
     * @param Email
     * @param research
     */
    public Faculty(String Email, String Name, String lastName, String research){
        super(lastName, Name, Email);
        this.lastName = lastName;
        this.Name = Name;
        this.Email = Email;
        this.research = research;
        this.courses = new ArrayList<Course>();
    }
    /**
     * toString()
     * overriden toString() function for Faculty class
     */
    @Override
    public String toString(){
        return ("\nFaculty Member:\n" + "ID: " + getID() + "\nName: " + getName() + " " +  getLastName() + "\nEmail: " + getEmail() + "\nResearch Interest: " + getResearch() +"\n" + getCourses() );
    }

    /**
     * getResearch
     * @return research
     */
    public String getResearch() {
        return research;
    }

    /**
     * adds course to course list
     * @param course
     */
    public void addCourse(Course course) {
        if(courses != null) {
            courses.add(course);
        }
    }

    /**
     * returns courses taught
     * @return
     */
    public String getCourses() {
        if(courses != null) {
            String output = "Courses Taught:\n";
            for (int i = 0; i < courses.size(); i++) {
                output += courses.get(i).getCourseID() + " - " + courses.get(i).getCourseName() +"\n";
            }
            return output;
        }
        return "";
    }
}
