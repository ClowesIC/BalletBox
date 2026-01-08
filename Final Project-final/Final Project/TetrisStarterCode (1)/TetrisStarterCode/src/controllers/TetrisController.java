package controllers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

import models.Tetronimo;
import models.StraightLine;
import models.SquareBlock;
import models.TeeBlock;
import models.ElBlock;
import models.JayBlock;
import models.SBlock;
import models.ZBlock;

import views.TetrisBoard;
import wheelsunh.users.Rectangle;

import java.awt.Color;

/**
 * TetrisController.java:
 * Class to hold all the game logic for tetris
 *
 * Game logic: spawning, movement/collision, lock/clear, scoring.
 * Top-out rule: allow play at/above the top while falling,
 * but if a piece LOCKS and any cell is above row 0 => GAME OVER.
 *
 * @author Elijah Dick
 * @version 1.3 December 5, 2025
 */
public class TetrisController
{
    private final TetrisBoard TETRIS_BOARD;
    private int boardWidth()  { return TETRIS_BOARD.getPlayingField().length; }
    private int boardHeight() { return TETRIS_BOARD.getPlayingField()[0].length; }

    // scoring
    private int score = 0;
    private int highScore = 0;

    // preview piece
    private Tetronimo nextPreview;

    private static final int LEFT_MARGIN = 40;

    // Spawn one cell above the visible board
    private static final int SPAWN_X = LEFT_MARGIN + (4 * Tetronimo.SIZE);
    private static final int SPAWN_Y = -Tetronimo.SIZE;

    // frame geometry
    private static final int PREVIEW_LEFT  = 280;
    private static final int PREVIEW_TOP   = 10;
    private static final int PREVIEW_W     = 120;
    private static final int PREVIEW_H     = 110;
    private static final int NEXT_OFFSET_Y = 80;   // vertical shift for NEXT section
    // -------------------------------------------------------

    // Small exception so we can signal blocked rotates cleanly
    public static class MoveBlockedException extends RuntimeException
    {
        public MoveBlockedException( String msg ) { super( msg ); }
    }

    /**
     * Constructor to take in a tetris board so the controller and the board can communciate
     *
     * Initializes the preview piece and updates the score display.
     *
     * @param tetrisBoard A tetris board instance
     */
    public TetrisController(TetrisBoard tetrisBoard)
    {
        this.TETRIS_BOARD = tetrisBoard;

        this.nextPreview = randomTetronimo();
        placeInPreview(this.nextPreview);

        TETRIS_BOARD.updateScore(score, highScore);
    }



    /**
     * Randomly chooses the next tetronimo and returns it
     *
     * Uses the stored preview piece for spawning, then refreshes the preview.
     *
     * @return The next tetronimo to be played
     */
    public Tetronimo getNextTetromino()
    {
        Tetronimo t = this.nextPreview;

        this.nextPreview = randomTetronimo();
        placeInPreview(this.nextPreview);

        t.setLocation(SPAWN_X, SPAWN_Y);
        return t;
    }

    //split this from the getNextTeteromino, due to issues when viewing next piece
    /**
     * Helper method that returns a random tetronimo instance
     *
     * @return A random Tetronimo object
     */
    private Tetronimo randomTetronimo()
    {
        Random rand = new Random();
        int r = rand.nextInt(7);

        switch ( r )
        {
            case 0: return new StraightLine();
            case 1: return new SquareBlock();
            case 2: return new TeeBlock();
            case 3: return new ElBlock();
            case 4: return new JayBlock();
            case 5: return new SBlock();
            default: return new ZBlock();
        }
    }

    /**
     * Positions a tetronimo inside the preview frame
     *
     * @param t The Tetronimo to position inside the preview box
     */
    private void placeInPreview(Tetronimo t)
    {
        // Center the piece inside the (offset) preview frame
        int frameX = PREVIEW_LEFT;
        int frameY = PREVIEW_TOP + NEXT_OFFSET_Y;
        int px = frameX + (PREVIEW_W - t.getWidth())  / 2;
        int py = frameY + (PREVIEW_H - t.getHeight()) / 2;
        t.setLocation(px, py);
    }


    /**
     * Method to determine if the tetronimo has landed
     *
     * @param t The tetronimo to evaluate
     * @return True if the tetronimo can move down (i.e., has not landed), false otherwise
     */
    public boolean tetronimoLanded(Tetronimo t)
    {
        return canMove(t, 0, 1);
    }

    /**
     * Grid-aware move test in cell units (dx, dy)
     *
     * Rows < 0 are treated as empty, and horizontal bounds are enforced only once row >= 0.
     *
     * @param t  The tetronimo to test
     * @param dx The horizontal offset in cells
     * @param dy The vertical offset in cells
     * @return True if the move is valid, false if blocked
     */
    public boolean canMove(Tetronimo t, int dx, int dy)
    {
        Rectangle[][] grid = TETRIS_BOARD.getPlayingField();
        java.awt.Point[] locals = t.getLocalCells();

        int W = boardWidth();
        int H = boardHeight();

        int aCol = (t.getXLocation() - LEFT_MARGIN) / Tetronimo.SIZE;
        int aRow =  t.getYLocation()                / Tetronimo.SIZE;

        for (java.awt.Point p : locals)
        {
            int col = aCol + p.x + dx;
            int row = aRow + p.y + dy;

            // ALWAYS keep columns inside the board, even above the visible top
            if (col < 0 || col >= W) return false;

            // Block the floor
            if (row >= H) return false;

            // Treat rows < 0 as empty, but still obey walls (is checked above)
            if (row >= 0 && !isCellEmpty(grid, col, row)) return false;
        }
        return true;
    }
    /*
    This could not stay in movement logic as I was running into an issue
    where if a player tried to rotate the piece right as the game began the piece
    would lock into the upper left corner.
    This would not case to piece to turn red and not follow the collision logic,
    to the game it simply seemed that the piece was no longer on the board at all, moving this method out and having it do checks
    is the only way to remove this error.
    Used Chat GPT to debug this issue as it was a struggle to get it to constantly have this error,
    seem to be only me (ED).
     */
    public void tryRotate(Tetronimo t)
    {
        t.rotate();  // attempt the rotation in place

        if (canMove(t, 0, 0)) return;  // rotation is valid where it is

        // simple kicks: ±1, ±2 columns (use a List<Integer> for clarity)
        List<Integer> kicks = Arrays.asList(1, -1, 2, -2);
        for (Integer k : kicks)
        {
            if (canMove(t, k, 0))
            {
                t.setLocation(t.getXLocation() + k * Tetronimo.SIZE, t.getYLocation());
                return;
            }
        }

        // no kick worked, undo rotation and throws exception
        t.rotate(); t.rotate(); t.rotate();
        throw new MoveBlockedException("rotate blocked");
    }

    /**
     * Checks if a given cell in the grid is empty
     *
     * @param grid The grid of board rectangles
     * @param col  Column index
     * @param row  Row index
     * @return True if empty, false if occupied
     */
    private boolean isCellEmpty(Rectangle[][] grid, int col, int row)
    {
        // Only RED cells (locked stack) are treated as occupied.
        return !grid[col][row].getColor().equals(Color.RED);
    }



    /**
     * Locks the tetronimo into the playing field by coloring its cells red
     *
     * @param t The tetronimo to lock
     * @return True if any part of the piece was above the top of the visible grid
     */
    public boolean lockToGrid(Tetronimo t)
    {
        Rectangle[][] grid = TETRIS_BOARD.getPlayingField();
        java.awt.Point[] locals = t.getLocalCells();

        int W = boardWidth();
        int H = boardHeight();

        int aCol = (t.getXLocation() - LEFT_MARGIN) / Tetronimo.SIZE;
        int aRow =  t.getYLocation()                / Tetronimo.SIZE;

        boolean anyAboveTop = false;

        for (java.awt.Point p : locals)
        {
            int col = aCol + p.x;
            int row = aRow + p.y;

            if (row < 0) anyAboveTop = true;

            if (row >= 0 && row < H && col >= 0 && col < W)
            {
                grid[col][row].setColor(Color.RED);
            }
        }
        return anyAboveTop;
    }

    /**
     * Scans the grid for full rows, clears them, shifts rows above downward,
     * normalizes non-locked cells to white, and updates the score
     *
     * @return The number of lines cleared
     */
    public int clearFullLines()
    {
        Rectangle[][] grid = TETRIS_BOARD.getPlayingField();
        int W = boardWidth();
        int H = boardHeight();

        // compact the grid in one bottom-up pass to avoid stale row indices after shifts
        int write = H - 1;                // next row to write into
        int cleared = 0;

        for (int read = H - 1; read >= 0; read--)
        {
            boolean full = true;
            for (int c = 0; c < W; c++)
            {
                if (isCellEmpty(grid, c, read)) { full = false; break; }
            }

            if (full)
            {
                cleared++;
                continue; // skip copying this row; it gets deleted
            }

            // copy row 'read' down to 'write' if they differ
            if (write != read)
            {
                for (int c = 0; c < W; c++)
                    grid[c][write].setColor(grid[c][read].getColor());
            }
            write--;
        }

        // fill remaining rows above 'write' with WHITE
        for (int r = write; r >= 0; r--)
            for (int c = 0; c < W; c++)
                grid[c][r].setColor(Color.WHITE);

        // normalize any non-RED to WHITE
        for (int r = 0; r < H; r++)
            for (int c = 0; c < W; c++)
                if (!grid[c][r].getColor().equals(Color.RED))
                    grid[c][r].setColor(Color.WHITE);

        if (cleared > 0)
        {
            score += (cleared == 4) ? 800 : (100 * cleared);
            if (score > highScore) highScore = score;
            TETRIS_BOARD.updateScore(score, highScore);
        }
        return cleared;
    }



    /**
     * Resets the current score (high score persists)
     */
    public void resetScore()
    {
        score = 0;
        TETRIS_BOARD.updateScore(score, highScore);
    }

    /**
     * Getter method for the current score
     *
     * @return The player’s current score
     */
    public int getScore()     { return score; }

    /**
     * Getter method for the current high score
     *
     * @return The player’s highest score achieved
     */
    public int getHighScore() { return highScore; }
}
