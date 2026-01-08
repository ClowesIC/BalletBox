package University;

/**
 * Person
 * Person class to give identificational attributes to objects belonging to this class.
 * @author Ian Clowes
 */
public abstract class Person {
    private int ID = 100000000 + (int)(Math.random() * ((999999999 - 100000000) + 1));;
    private String Email;
    private String Name;
    private String lastName;

    /**
     * Person
     * Person constructor
     * @param lastName
     * @param Name
     * @param Email
     */
    Person(String lastName, String Name, String Email) {
        this.lastName = lastName;
        this.Email = Email;
        this.Name = Name;
    }

    //getters

    /**
     * getID
     * a getter method that gets ID
     * @return ID
     */
    public int getID() {
        return ID;
    }

    /**
     * getName
     * a getter method that gets name
     * @return Name
     */
    public String getName() {
        return Name;
    }

    /**
     * getEmail
     * getter method that returns email
     * @return email
     */
    public String getEmail() {
        return Email;
    }
    /**
     * getLastName
     * getter method to return lastName
     * @return lastName
     */
    public String getLastName() {
        return lastName;
    }
}

