package University;

/**
 * Staff
 * Staff class creates an object of a staff memeber in the department
 * @author Ian Clowes
 */
public class Staff extends Person{
    private String role;
    private String lastName;
    private String Name;
    private String Email;

    /**
     * Staff constructor
     * @param lastName
     * @param Name
     * @param Email
     * @param role
     */
    public Staff(String Email, String Name, String lastName, String role){
        super(lastName, Name, Email);
        this.Name = Name;
        this.Email = Email;
        this.role = role;
        this.lastName = lastName;
    }
    /**
     * toString()
     * overriden toString() function for Staff class
     */
    @Override
    public String toString(){
        return ("\nStaff Member:\n" + "ID: " + getID() + "\nName: " + getName() +" " +  getLastName() +"\nEmail: " + getEmail() + "\nRole: " + getRole() );
    }

    /**
     * getResearch
     * @return role
     */
    public String getRole() {
        return role;
    }
}


