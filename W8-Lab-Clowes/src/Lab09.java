import Garage.*;

import java.util.ArrayList;

/**
 * Lab09
 * Default class used to utilize lab09 resources
 */
public class Lab09 {
    public static void main(String[] args){
            ArrayList<Automobile> garage= new ArrayList<Automobile>();

            Supra supra = new Supra();
            garage.add(supra);

            Colorado colorado = new Colorado();
            garage.add(colorado);

            Sienna sienna = new Sienna();
            garage.add(sienna);

            Silverado silverado = new Silverado();
            garage.add(silverado);

            System.out.print("Current Garage:\n");
            for(int i = 0; i < garage.size(); i++){
                System.out.println(garage.get(i).toString());
                if(garage.get(i) instanceof Automobile){
                    ((Automobile) garage.get(i)).drive();

                }
                if(garage.get(i) instanceof Truck) {
                    ((Truck) garage.get(i)).haul();

                }
                if(garage.get(i) instanceof Supra) {
                    ((Supra) garage.get(i)).twinTurbos();

                }
                if(garage.get(i) instanceof Colorado) {
                    ((Colorado) garage.get(i)).fourWheelDrive();

                }
                if (garage.get(i) instanceof Sienna) {
                    ((Sienna) garage.get(i)).surroundSoundsSpeakers();

                }
                if(garage.get(i) instanceof Silverado) {
                    ((Silverado) garage.get(i)).frontWinch();


                }
                System.out.println();
            }


    }
}
