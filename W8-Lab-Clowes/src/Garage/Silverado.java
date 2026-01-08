package Garage;

/**
 * Silverado
 * class that creates a Silverado truck
 */
public class Silverado extends Truck {

    /**
     * Silverado
     * Silverado constructor
     */
    public Silverado(){
        super(2005,"Chevy","Silverado", 5000, 5500);
    }

    //override drive() and haul()

    /**
     * drive
     * overridden drive method that will print that silverado is being driven
     */
    @Override
    public void drive(){
        System.out.println("Driving a " + getMakeYear() +" " + getMake()+ " " + getModel() +".");;
    }

    /**
     * haul
     * overridden haul method that will print what the silverado can haul
     */
    @Override
    public void haul() {
        System.out.print("Hauling payload with tow capacity: " + getTowCapacity() + " lbs");
    }

    /**
     * frontWinch
     * the unique feature of the Silverado
     */
    public void frontWinch(){
        System.out.printf("%d %s %s with a front winch.", getMakeYear(), getMake() , getModel());
    }

}
