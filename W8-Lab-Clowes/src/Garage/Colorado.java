package Garage;

/**Colorado
 * class that resembles the Chevy Colorado truck
 */
public class Colorado extends Truck {
    public Colorado(){
        super(2025,"Chevy","Colorado", 5500, 6500);
    }

    /**
     * drive
     * overridden drive method that will print that Colorado is being driven
     */
    @Override
    public void drive(){
        System.out.println("Driving a " + getMakeYear() +" " + getMake()+ " " + getModel() +".");;
    }

    /**
     * haul
     * overridden haul method that will print what the Colorado can haul
     */
    @Override
    public void haul() {
        System.out.println("Hauling payload with tow capacity: " + getTowCapacity() + " lbs");
    }


    /**
     * fourWheelDrive
     * uniquely named feature of Colorado truck
     */
    public void fourWheelDrive(){
        System.out.printf("%d %s %s with four-wheel drive.", getMakeYear(), getMake() , getModel());
    }
}
