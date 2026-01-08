/**
 * Garage.java
 *
 * Package that holds Car and Truck oriented classes
 *
 * @author Ian Clowes
 */
package Garage;

/**
 * Automobile
 * abstract class that holds a lot of the qualities of a vehicle
 */
public abstract class Automobile implements StartableIF, DriveableIF {
    private int makeYear;
    private String make;
    private String model;
    private double weight;


    /**
     * Automobile
     * Constructor for automobile method
     * @param makeYear
     * @param make
     * @param model
     * @param weight
     */
    public Automobile(int makeYear, String make, String model, double weight) {
        this.makeYear = makeYear;
        this.make = make;
        this.model = model;
        this.weight = weight;
    }


    //Accessors

    /**
     * getMakeYear
     * a getter method for makeYear
     * @return makeYear
     */
    public int getMakeYear() {
        return makeYear;
    }

    /**
     * getMake
     * a getter method for make
     * @return make
     */
    public String getMake() {
        return make;
    }

    /**
     * getModel
     * a getter method for model
     * @return model
     */
    public String getModel() {
        return model;
    }

    /**
     * getWeight
     * a getter method for weight
     * @return weight
     */
    public double getWeight() {
        return weight;
    }

    //implementation of start() and stop()
    public void start(){
        System.out.println("Starting an Automobile");
    }
    public void stop(){
        System.out.println("Stopping an Automobile");
    }
}
