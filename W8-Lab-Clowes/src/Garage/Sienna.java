package Garage;

/**
 * Sienna
 * class that resembles the Sienna car
 */
public class Sienna extends Car {
    private int numberOfDoors;

    /**
     * Sienna
     * Sienna Constructor
     *
     */
    public Sienna(){
        super(2014,"Toyota","Sienna",3600,4);
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
     * overriden drive method that prints that the Sienna is being driven
     */
    @Override
    public void drive(){
        System.out.println("Driving a " + getMakeYear() + " " + getMake() +" "+ getModel() + ".");
    }

    /**
     * surroundSoundSpeakers
     * unique feature of Toyota SiennaSurr
     */
    public void surroundSoundsSpeakers(){
        System.out.printf("%d %s %s with surround sound speakers", getMakeYear(), getMake() , getModel());
    }

}
