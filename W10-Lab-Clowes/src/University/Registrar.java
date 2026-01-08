package University;

/**
 * Registrar
 * Class that heavily utilizes polymorphism to assign specific objects to each other in groups
 * @author Ian Clowes
 */
public class Registrar {
    /**
     * Assigns a course to a department.
     *
     * @param department the Department offering the course
     * @param course     the Course to be added
     */
    public static void assign(Department department, Course course) {
        if (department != null && course != null) {
            department.addCourse(course);
        }
    }

    /**
     * Assigns a faculty member to teach a course.
     *
     * @param faculty
     * @param course
     */
    public static void assign(Faculty faculty, Course course) {
        if (faculty != null && course != null) {
            faculty.addCourse(course);
            course.setInstructor(faculty);
        }
    }

    /**
     * Enrolls a student into a specific course.
     *
     * @param student
     */
    public static void enroll(Student student, Course course) {
        if (student != null && course != null) {
            student.addCourse(course);
            course.addStudent(student);
        }
    }
}
