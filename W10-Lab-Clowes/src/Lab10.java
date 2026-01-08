import University.*;

/**
 * Lab10 demonstrates class relationships within a university domain.
 *
 * <p>This program creates objects representing faculty, staff, students, courses,
 * and a department. It simulates assigning faculty and courses to a department,
 * enrolling students into courses, and printing all details to the console.</p>
 *
 * <p>Key relationships demonstrated:</p>
 * <ul>
 *   <li>Aggregation — a Department aggregates Faculty, Staff, and Courses.</li>
 *   <li>Association — Students are associated with Courses through enrollment.</li>
 *   <li>Dependency — The Registrar class provides methods that coordinate assignments and enrollments.</li>
 * </ul>
 *
 * @author
 * James Lanham
 * @version
 * 1.0, October 2025
 */
public class Lab10 {

    /**
     * The entry point of the program.
     *
     * <p>Initializes arrays of Faculty, Staff, Students, and Courses.
     * Uses the Registrar utility to assign faculty to courses and
     * enroll students into courses. Finally, it prints all relevant
     * information to the console to show the established relationships.</p>
     *
     * @param args Command-line arguments (not used)
     */
    public static void main(String[] args) {

        // Create an array of Faculty members (aggregation into Department)
        Faculty[] faculty = {
                new Faculty(
                        "jis0294@psu.edu",
                        "Jeanne",
                        "Sigourney",
                        "Software Project Management"
                ),
                new Faculty(
                        "por0934@psu.edu",
                        "Joey",
                        "Rain",
                        "Robotics"
                ),
        };

        // Create a Staff member
        Staff staff = new Staff(
                "jod1234@psu.edu",
                "John",
                "Doe",
                "Admin Assistant"
        );

        // Create an array of Students (to be enrolled in Courses)
        Student[] students = {
                new Student(
                        "abc1234@psu.edu",
                        "Jane",
                        "Doe",
                        "Software Engineering"
                ),
                new Student(
                        "def5678@psu.edu",
                        "Jack",
                        "Smith",
                        "Computer Science"
                ),
                new Student(
                        "ghi9101@psu.edu",
                        "Anton",
                        "Desmond",
                        "Software Engineering"
                ),
                new Student(
                        "jkl1112@psu.edu",
                        "Daren",
                        "Deloris",
                        "Electrical Engineering"
                )
        };

        // Create a Department that aggregates faculty, staff, and courses
        Department department = new Department("Computer Science and Software Engineering");

        // Create an array of Courses offered in the department
        Course[] courses = {
                new Course("CMPSC 121", "Introduction to Programming", "Fall 2025"),
                new Course("CMPSC 122", "Intermediate Programming", "Fall 2025"),
                new Course("CMPSC 221", "Object Oriented Programming", "Fall 2025"),
                new Course("SWENG 311", "Object Oriented Design and Construction", "Fall 2025"),
                new Course("SWENG 411", "Software Engineering", "Fall 2025"),
        };

        // Add staff to the department
        department.addMember(staff);

        // Assign all courses to the department using the Registrar
        for (Course course : courses) {
            Registrar.assign(department, course);
        }

        // Assign faculty to specific courses (association through Registrar)
        Registrar.assign(faculty[0], courses[0]);
        Registrar.assign(faculty[0], courses[1]);
        Registrar.assign(faculty[1], courses[2]);
        Registrar.assign(faculty[0], courses[3]);
        Registrar.assign(faculty[1], courses[4]);

        // Enroll students into various courses (association between Student and Course)
        Registrar.enroll(students[0], courses[0]);
        Registrar.enroll(students[1], courses[0]);
        Registrar.enroll(students[2], courses[1]);
        Registrar.enroll(students[3], courses[1]);
        Registrar.enroll(students[0], courses[2]);
        Registrar.enroll(students[1], courses[2]);
        Registrar.enroll(students[2], courses[3]);
        Registrar.enroll(students[3], courses[3]);
        Registrar.enroll(students[3], courses[4]);
        Registrar.enroll(students[1], courses[4]);
        Registrar.enroll(students[2], courses[4]);

        // Add faculty members to the department and display their details
        for (Faculty fac : faculty) {
            department.addMember(fac);
            System.out.println(fac);
        }

        // Print staff details
        System.out.println(staff);
        System.out.println();

        // Print student details
        for (Student student : students) {
            System.out.println(student);
        }

        // Print department summary
        System.out.println(department);
        System.out.println();

        // Print course information (faculty assignments and enrolled students)
        for (Course course : courses) {
            System.out.println(course);
            System.out.println();
        }
    }
}

/*

SAMPLE OUTPUT

Faculty Member:
ID: 439970850
Name: Jeanne Sigourney
Email: jis0294@psu.edu
Research Interset: Software Project Management
Courses Taught:
	CMPSC 121 - Introduction to Programming
	CMPSC 122 - Intermediate Programming
	SWENG 311 - Object Oriented Design and Construction

Faculty Member:
ID: 854107773
Name: Joey Rain
Email: por0934@psu.edu
Research Interset: Robotics
Courses Taught:
	CMPSC 221 - Object Oriented Programming
	SWENG 411 - Software Engineering

Staff Member:
ID: 414143545
Name: John Doe
Email: jod1234@psu.edu
Role: Admin Assistant

Student:
ID: 229408577
Name: Jane Doe
Email: abc1234@psu.edu
Courses Enrolled:
	CMPSC 121 - Introduction to Programming
	CMPSC 221 - Object Oriented Programming

Student:
ID: 630098166
Name: Jack Smith
Email: def5678@psu.edu
Courses Enrolled:
	CMPSC 121 - Introduction to Programming
	CMPSC 221 - Object Oriented Programming
	SWENG 411 - Software Engineering

Student:
ID: 927810992
Name: Anton Desmond
Email: ghi9101@psu.edu
Courses Enrolled:
	CMPSC 122 - Intermediate Programming
	SWENG 311 - Object Oriented Design and Construction
	SWENG 411 - Software Engineering

Student:
ID: 138928599
Name: Daren Deloris
Email: jkl1112@psu.edu
Courses Enrolled:
	CMPSC 122 - Intermediate Programming
	SWENG 311 - Object Oriented Design and Construction
	SWENG 411 - Software Engineering

Department:
Computer Science and Software Engineering
Members:
	Doe, John - jod1234@psu.edu
	Sigourney, Jeanne - jis0294@psu.edu
	Rain, Joey - por0934@psu.edu
Courses:
	CMPSC 121 - Introduction to Programming
	CMPSC 122 - Intermediate Programming
	CMPSC 221 - Object Oriented Programming
	SWENG 311 - Object Oriented Design and Construction
	SWENG 411 - Software Engineering

Course:
CMPSC 121 - Introduction to Programming
Semester: Fall 2025
Teaching Faculty: Sigourney Jeanne
Students Enrolled:
	Doe, Jane
	Smith, Jack

Course:
CMPSC 122 - Intermediate Programming
Semester: Fall 2025
Teaching Faculty: Sigourney Jeanne
Students Enrolled:
	Desmond, Anton
	Deloris, Daren

Course:
CMPSC 221 - Object Oriented Programming
Semester: Fall 2025
Teaching Faculty: Rain Joey
Students Enrolled:
	Doe, Jane
	Smith, Jack

Course:
SWENG 311 - Object Oriented Design and Construction
Semester: Fall 2025
Teaching Faculty: Sigourney Jeanne
Students Enrolled:
	Desmond, Anton
	Deloris, Daren

Course:
SWENG 411 - Software Engineering
Semester: Fall 2025
Teaching Faculty: Rain Joey
Students Enrolled:
	Deloris, Daren
	Smith, Jack
	Desmond, Anton


Process finished with exit code 0

 */
