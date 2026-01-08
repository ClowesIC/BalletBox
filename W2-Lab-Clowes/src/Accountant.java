/**
 * Accountant.java:
 * A class with variables corresponding to accounting companies
 * also includes a method that calculates and prints the accountant's salary
 *
 *
 * @author Ian Clowes
 *
 */


public class Accountant {

    //class variables
    private String name;
    private int age;
    private String companyName;

    //class methods

    //get methods

    /**
     * getName:
     * Method to return accountant's name.
     */
    public String getName(){
        return name;
    }

    /**
     * getCompanyName:
     * Method to return CompanyName.
     *
     */
    public String getCompanyName(){
        return companyName;
    }

    /**
     * getAge:
     * Method to return accountant's age.
     *
     */
    public int getAge(){
        return age;
    }

    /**
     * salaryCalculation:
     * Salary calculation using a formula method
     */
    public double salaryCalculation(){
        return 40000 * Math.sqrt( Math.exp(0.04295 * age + 0.141));
    }

    /**
     * displayMethod:
     * a method that displays Accountant information
     *
     */
    public void displayMethod(){
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Company Name: " + companyName);

    }

    //class constructor
    public Accountant(String name, int age, String companyName){
        this.name = name;
        this.age = age;
        this.companyName = companyName;

    }
}
