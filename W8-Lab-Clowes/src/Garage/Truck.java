package Garage;

/**
 * Truck
 * Truck class that extends automobile class to create a Truck object
 */
public abstract class Truck extends Automobile implements HaulableIF {
    private int towCapacity;

    /**
     * Truck
     * Truck constructor
     * @param makeYear
     * @param make
     * @param model
     * @param weight
     * @param towCapacity
     */
    public Truck(int makeYear, String make, String model, double weight, int towCapacity) {
        super(makeYear,make,model,weight);
        this.towCapacity = towCapacity;
    }

    /**
     * start
     * start method that tells whether the truck has started
     */
    @Override
    public void start(){
        System.out.println("Starting Truck");
    }

    /**
     * stop
     * stop method that tells whether the truck has stopped
     */
    @Override
    public void stop(){
        System.out.println("Stopping Truck");
    }

    //getter

    /**
     * getTowCapacity
     * a getter method for tow capacity
     * @return towCapacity
     */
    public int getTowCapacity() {
        return towCapacity;
    }

    @Override
    public String toString(){
        return "\n" + getMakeYear() +" "+getMake() + " " + getModel() +"\nCurb Weight: " + getWeight() + "\nTowing Capacity: " + getTowCapacity();
    }
}
