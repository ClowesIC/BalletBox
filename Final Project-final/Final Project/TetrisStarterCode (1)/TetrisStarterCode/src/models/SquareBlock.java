package models;

import java.awt.Color;


/**
 * SquareBlock.java:
 * Creates a square tetronimo
 *
 * @author Elijah Dick
 * @version 1.0 September 27, 2025
 *
 * @see java.awt.Point
 */
public class SquareBlock extends Tetronimo
{
    /**
     * Creates the tetronimo in its default orientation
     */
    public SquareBlock()
    {
        super.r1.setLocation( 0, 0 );
        super.r2.setLocation( Tetronimo.SIZE, 0 );
        super.r3.setLocation( 0, Tetronimo.SIZE );
        super.r4.setLocation( Tetronimo.SIZE, Tetronimo.SIZE );

        super.r1.setColor(Color.YELLOW); super.r1.setFrameColor(Color.BLACK);
        super.r2.setColor(Color.YELLOW); super.r2.setFrameColor(Color.BLACK);
        super.r3.setColor(Color.YELLOW); super.r3.setFrameColor(Color.BLACK);
        super.r4.setColor(Color.YELLOW); super.r4.setFrameColor(Color.BLACK);


        super.add( r1 );
        super.add( r2 );
        super.add( r3 );
        super.add( r4 );
    }

    /**
     * Rotates the tetronimo
     * Square does not change shape when rotated
     */
    @Override
    public void rotate()
    {
        // no-op
    }

    /**
     * Gets the height of the tetronimo
     *
     * @return The height of the tetronimo
     */
    @Override
    public int getHeight() { return Tetronimo.SIZE * 2; }

    /**
     * Gets the width of the tetronimo
     *
     * @return The width of the tetronimo
     */
    @Override
    public int getWidth() { return Tetronimo.SIZE * 2; }
}
