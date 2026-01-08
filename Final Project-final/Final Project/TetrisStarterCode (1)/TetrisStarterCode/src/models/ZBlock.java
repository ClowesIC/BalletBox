package models;

import java.awt.Point;
import java.awt.Color;
/**
 * ZBlock.java:
 * Creates a Z tetronimo
 *
 * @author Elijah Dick
 * @version 1.0 September 27, 2025
 *
 * @see java.awt.Point
 */
public class ZBlock extends Tetronimo
{
    /**
     * Creates the tetronimo in its default orientation
     */
    public ZBlock()
    {
        super.r1.setLocation( 0, 0 );
        super.r2.setLocation( Tetronimo.SIZE, 0 );
        super.r3.setLocation( Tetronimo.SIZE, Tetronimo.SIZE );
        super.r4.setLocation( Tetronimo.SIZE * 2, Tetronimo.SIZE );

        super.r1.setColor(Color.RED);   super.r1.setFrameColor(Color.BLACK);
        super.r2.setColor(Color.RED);   super.r2.setFrameColor(Color.BLACK);
        super.r3.setColor(Color.RED);   super.r3.setFrameColor(Color.BLACK);
        super.r4.setColor(Color.RED);   super.r4.setFrameColor(Color.BLACK);


        super.add( r1 );
        super.add( r2 );
        super.add( r3 );
        super.add( r4 );
    }

    /**
     * Rotates the tetronimo
     */
    @Override
    public void rotate()
    {
        super.rotate();

        Point curLoc = super.getLocation();
        super.setLocation( 0, 0 );

        if( super.curRotation % 2 == 1 ) // horizontal
        {
            super.r1.setLocation( 0, 0 );
            super.r2.setLocation( Tetronimo.SIZE, 0 );
            super.r3.setLocation( Tetronimo.SIZE, Tetronimo.SIZE );
            super.r4.setLocation( Tetronimo.SIZE * 2, Tetronimo.SIZE );
        }
        else // vertical
        {
            super.r1.setLocation( Tetronimo.SIZE, 0 );
            super.r2.setLocation( Tetronimo.SIZE, Tetronimo.SIZE );
            super.r3.setLocation( 0, Tetronimo.SIZE );
            super.r4.setLocation( 0, Tetronimo.SIZE * 2 );
        }

        super.setLocation( curLoc );
    }

    /**
     * Gets the height of the tetronimo based on the orientation
     *
     * @return The height of the tetronimo
     */
    @Override
    public int getHeight()
    {
        return ( this.curRotation % 2 == 1 ) ? Tetronimo.SIZE * 2 : Tetronimo.SIZE * 3;
    }

    /**
     * Gets the width of the tetronimo based on the orientation
     *
     * @return The width of the tetronimo
     */
    @Override
    public int getWidth()
    {
        return ( this.curRotation % 2 == 1 ) ? Tetronimo.SIZE * 3 : Tetronimo.SIZE * 2;
    }
}
