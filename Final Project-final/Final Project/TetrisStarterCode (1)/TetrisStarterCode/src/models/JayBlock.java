package models;

import java.awt.Color;
import java.awt.Point;

public class JayBlock extends Tetronimo
{
    public JayBlock()
    {
        super.r1.setLocation( Tetronimo.SIZE, 0 );
        super.r2.setLocation( Tetronimo.SIZE, Tetronimo.SIZE );
        super.r3.setLocation( Tetronimo.SIZE, Tetronimo.SIZE * 2 );
        super.r4.setLocation( 0, Tetronimo.SIZE * 2 );

        Color JBLUE = new Color(0,102,204);
        r1.setFillColor(JBLUE); r1.setFrameColor(Color.BLACK);
        r2.setFillColor(JBLUE); r2.setFrameColor(Color.BLACK);
        r3.setFillColor(JBLUE); r3.setFrameColor(Color.BLACK);
        r4.setFillColor(JBLUE); r4.setFrameColor(Color.BLACK);


        super.add( r1 );
        super.add( r2 );
        super.add( r3 );
        super.add( r4 );
    }

    @Override
    public void rotate()
    {
        super.rotate();
        Point curLoc = super.getLocation();
        super.setLocation( 0, 0 );

        Color JBLUE = new Color(0,102,204);
        int k = super.curRotation % 4;
        if( k == 1 ) // up
        {
            super.r1.setLocation( Tetronimo.SIZE, 0 );
            super.r2.setLocation( Tetronimo.SIZE, Tetronimo.SIZE );
            super.r3.setLocation( Tetronimo.SIZE, Tetronimo.SIZE * 2 );
            super.r4.setLocation( 0, Tetronimo.SIZE * 2 );
        }
        else if( k == 2 ) // right
        {
            super.r1.setLocation( 0, 0 );
            super.r2.setLocation( Tetronimo.SIZE, 0 );
            super.r3.setLocation( Tetronimo.SIZE * 2, 0 );
            super.r4.setLocation( Tetronimo.SIZE * 2, Tetronimo.SIZE );
        }
        else if( k == 3 ) // down
        {
            super.r1.setLocation( Tetronimo.SIZE, 0 );
            super.r2.setLocation( 0, 0 );
            super.r3.setLocation( 0, Tetronimo.SIZE );
            super.r4.setLocation( 0, Tetronimo.SIZE * 2 );
        }
        else // left
        {
            super.r1.setLocation( 0, 0 );
            super.r2.setLocation( Tetronimo.SIZE, 0 );
            super.r3.setLocation( Tetronimo.SIZE, Tetronimo.SIZE );
            super.r4.setLocation( Tetronimo.SIZE, Tetronimo.SIZE * 2 );
        }



        super.setLocation( curLoc );
    }

    @Override
    public int getHeight() {
        int k = this.curRotation % 4;
        return (k == 2) ? Tetronimo.SIZE * 2 : Tetronimo.SIZE * 3;
    }

    @Override
    public int getWidth() {
        int k = this.curRotation % 4;
        return (k == 2) ? Tetronimo.SIZE * 3 : Tetronimo.SIZE * 2;
    }

}
