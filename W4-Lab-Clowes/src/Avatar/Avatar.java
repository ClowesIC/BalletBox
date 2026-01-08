package Avatar;

import javafx.scene.paint.Color;
import wheelsFX.users.Shapes.Ellipse;
import wheelsFX.users.Shapes.Rectangle;

/**
 * Avatar.java
 *
 * Class that creates an avatar
 */
public class Avatar {
    /**
     * Constructor for Avatar
     * @param x x coordinate for avatar
     * @param y y coordinate for avatar
     */
    public Avatar(int x, int y){
        makeAvatar(x,y);
    }

    /**
     * class method that makes the avatar created by wheelsFX shapes
     * @param x x coordinate
     * @param y y coordinate
     */
    private void makeAvatar(int x, int y){

        //face base
        Ellipse ellipse = new Ellipse(x,y);
        ellipse.setColor(Color.color(0,0,0));
        ellipse.setSize(100,100);

        Ellipse ellipse2 = new Ellipse(x,y);
        ellipse2.setColor(Color.color(1,1,0,1));
        ellipse2.setSize(90,90);

        //face eyes
        Ellipse eye1 = new Ellipse(x-50,y-25);
        eye1.setColor(Color.color(0,0,0));
        eye1.setSize(20,20);

        Ellipse eye2 = new Ellipse(x+40,y-25);
        eye2.setColor(Color.color(0,0,0));
        eye2.setSize(20,20);

        //mouth
        Ellipse mouth1 = new Ellipse(x,y+40);
        mouth1.setColor(Color.color(0,0,0));
        mouth1.setSize(20,20);

        Ellipse mouth2 = new Ellipse(x,y+40);
        mouth2.setColor(Color.color(1,1,1));
        mouth2.setSize(15,15);

        //hat
        Rectangle rectangle1 = new Rectangle(x-100,y-110);
        rectangle1.setColor(Color.color(0,0,0));
        rectangle1.setSize(200,40);

        Rectangle rectangle2 = new Rectangle(x-50,y-150);
        rectangle2.setColor(Color.color(0,0,0));
        rectangle2.setSize(110,60);


    }
}
