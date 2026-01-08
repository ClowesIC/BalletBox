package University;

import java.util.ArrayList;

/**
 * Department
 * Department class that enforces polymorphism to generate information pertaining to the usage of other objects
 * @author Ian Clowes
 */
public class Department{
   public ArrayList<Course> courses;
   public ArrayList<Faculty> faculties;
   public ArrayList<Staff> staff;

   private String departmentName;

    /**
     * Department
     * Department constructor
     * @param departmentName
     */
    public Department(String departmentName){
        this.departmentName = departmentName;
        this.faculties = new ArrayList<Faculty>();
        this.staff = new ArrayList<Staff>();
        this.courses = new ArrayList<Course>();
    }

    /**
     * add member
     * adds a member to department
     * @param member
     */
    public void addMember(Person member){
        if (member instanceof Faculty) {
            faculties.add((Faculty)member);
        } else if (member instanceof Staff) {
            staff.add((Staff)member);
        }
    }

    /**
     * addCourse
     * adds a course to department
     * @param course
     */
    public void addCourse(Course course) {
        if (course != null) {
            courses.add(course);
        }
    }

    @Override
    public String toString() {
        String output = "\nDepartment:\n" + departmentName + "\nMembers:\n";
        for (int i = 0; i < staff.size(); i++) {
            output += "    " + staff.get(i).getLastName() + ", " + staff.get(i).getName() + " - " + staff.get(i).getEmail() + "\n";
        }
        for (int i = 0; i < faculties.size(); i++) {
            output += "    " + faculties.get(i).getLastName() + ", " + faculties.get(i).getName() + " - " + faculties.get(i).getEmail() + "\n";
        }

        output += "Courses:\n";
        for (int i = 0; i < courses.size(); i++) {
            output += "    " + courses.get(i).getCourseID() + " - " + courses.get(i).getCourseName() + "\n";
        }
        return output.trim();
    }

}
