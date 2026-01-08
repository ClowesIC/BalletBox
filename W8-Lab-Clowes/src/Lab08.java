import Garage.Silverado;
import Garage.Supra;


/**
 * Lab08
 * Class that is used to test classes within Garage Package
 */
public class Lab08 {
    /**
     * main
     * main method for console tests
     * @param args
     */
    public static void main(String[] args) {
        Supra toyota = new Supra();
        Silverado silverado = new Silverado();

        toyota.start();
        toyota.drive();
        toyota.stop();

        silverado.start();
        silverado.drive();
        silverado.haul();
        silverado.stop();



    }
}
