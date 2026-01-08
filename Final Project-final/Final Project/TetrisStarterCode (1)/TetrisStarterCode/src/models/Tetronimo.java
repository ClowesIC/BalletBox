// src/models/Tetronimo.java
package models;

import wheelsunh.users.Rectangle;
import wheelsunh.users.ShapeGroup;

import java.awt.Color;
import java.awt.Point;

/**
 * Tetronimo.java:
 * An abstract class to model the base capaabilities of a tetronimo
 *
 * @author Professor Rossi
 * @version 1.0 July 24, 2020
 *
 * @see java.awt.Color
 */
public abstract class Tetronimo extends ShapeGroup
{
    /**
     * Constant to represent the size of the tetronimo
     */
    public static final int SIZE= 20;

    protected Rectangle r1;
    protected Rectangle r2;
    protected Rectangle r3;
    protected Rectangle r4;

    protected int curRotation = 1;

    /**
     * Generates the four rectangles for the tetronino and puts them on the screen, they are at the default coordinates
     * to start
     */
    public Tetronimo()
    {
        super();
        this.r1 = new Rectangle();
        this.r1.setSize( Tetronimo.SIZE, Tetronimo.SIZE );
        this.r1.setFrameColor( Color.BLACK );

        this.r2 = new Rectangle();
        this.r2.setSize( Tetronimo.SIZE, Tetronimo.SIZE );
        this.r2.setFrameColor( Color.BLACK );

        this.r3 = new Rectangle();
        this.r3.setSize( Tetronimo.SIZE, Tetronimo.SIZE );
        this.r3.setFrameColor( Color.BLACK );

        this.r4 = new Rectangle();
        this.r4.setSize( Tetronimo.SIZE, Tetronimo.SIZE );
        this.r4.setFrameColor( Color.BLACK );
    }

    /**
     * Increments the rotation of the tetronimo, other classes need to override this to provide the full functionality
     */
    public void rotate()
    {
        this.curRotation++;
    }

    /**
     * Shifts the tetronimo left one row
     */
    public void shiftLeft()
    {
        super.setLocation( super.getXLocation() - Tetronimo.SIZE, super.getYLocation() );
    }

    /**
     * Shifts the tetronimo right one row
     */
    public void shiftRight()
    {
        super.setLocation( super.getXLocation() + Tetronimo.SIZE, super.getYLocation() );
    }

    // helpers for board-grid math (do not alter existing behavior)
    public Point getAnchorCell()
    {
        int col = ( getXLocation() - 40 ) / Tetronimo.SIZE;
        int row = ( getYLocation() ) / Tetronimo.SIZE;
        return new Point( col, row );
    }

    public Point[] getLocalCells()
    {
        int gx = getXLocation();
        int gy = getYLocation();

        return new Point[] {
                new Point( (this.r1.getXLocation() - gx) / Tetronimo.SIZE,
                        (this.r1.getYLocation() - gy) / Tetronimo.SIZE ),
                new Point( (this.r2.getXLocation() - gx) / Tetronimo.SIZE,
                        (this.r2.getYLocation() - gy) / Tetronimo.SIZE ),
                new Point( (this.r3.getXLocation() - gx) / Tetronimo.SIZE,
                        (this.r3.getYLocation() - gy) / Tetronimo.SIZE ),
                new Point( (this.r4.getXLocation() - gx) / Tetronimo.SIZE,
                        (this.r4.getYLocation() - gy) / Tetronimo.SIZE )
        };
    }

    public Color getColor() { return this.r1.getColor(); }



}


