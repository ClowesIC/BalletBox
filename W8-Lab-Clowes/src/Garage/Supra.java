package Garage;

/**
 * Toyota
 * class that creates a Toyota Car
 */
public class Supra extends Car{

    private int numberOfDoors;

    /**
     * Supra
     * Supra Constructor
     *
     */
    public Supra(){
        super(1999,"Toyota","Supra",2000,2);
    }

    /**
     * getNumberOfDoors
     * getterMethod that returns number of Doors
     * @return numberOfDoors
     */
    public int getNumberOfDoors() {
        return numberOfDoors;
    }

    //overriders

    /**
     * drive
     * overriden drive method that prints that the Toyota is being driven
     */
    @Override
    public void drive(){
        System.out.println("Driving a " + getMakeYear() + " " + getMake() +" "+ getModel() + ".");
    }

    /**
     * twinTurbos
     * unique Supra feature
     */
    public void twinTurbos(){
        System.out.printf("%d %s %s with twin turbo.", getMakeYear(), getMake() , getModel());
    }



}
