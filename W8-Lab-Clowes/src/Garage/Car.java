package Garage;

/**
 * car
 * class that extends Automobile class, creating a car.
 */
public abstract class Car extends Automobile {
    private int numberOfDoors;


    /**
     * Car
     * Car constructor
     * @param makeYear
     * @param make
     * @param model
     * @param weight
     * @param numberOfDoors
     */
    public Car(int makeYear, String make, String model, double weight, int numberOfDoors) {
        super(makeYear, make, model, weight);
        this.numberOfDoors = numberOfDoors;
    }

    /**
     * getNumberOfDoors
     * getter method to return number of doors
     * @return numberOfDoors
     */
    public int getNumberOfDoors() {
        return numberOfDoors;
    }

    /**
     * start
     * start method that prints whether the car is started
     */
    @Override
    public void start(){
        System.out.println("Starting Car");
    }


    /**
     * stop
     * stop method that tells whether the car is stopped
     */
    @Override
    public void stop(){
        System.out.println("Stopping Car");
    }

    //override to-string
    @Override
    public String toString(){
       return "\n" + getMakeYear()+ " " + getMake()+ " " + getModel() + "\nCurb Weight: " + getWeight();
    }
}
