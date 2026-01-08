package views;

import controllers.TetrisController;
import controllers.TetrisController.MoveBlockedException;
import models.Tetronimo;
import wheelsunh.users.*;
import wheelsunh.users.Frame;
import wheelsunh.users.Rectangle;
import wheelsunh.users.Line;

import java.awt.Color;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

/**
 * TetrisBoard.java:
 * Class to model the tetris board.
 *
 * Board view (grid + HUD) and simple game loop/controls.
 * Uses a 40px left margin and Tetronimo.SIZE cells.
 *
 * @author Elijah Dick
 * @version 1.3 December 5, 2025
 *
 * @see java.awt.Color
 * @see java.awt.event.KeyListener
 * @see java.awt.event.KeyEvent
 */
public class TetrisBoard implements KeyListener
{
    /**
     * Constant to represent the width of the board
     */
    public static final int WIDTH  = 10;

    /**
     * Constant to represnet the height of the board
     */
    public static final int HEIGHT = 24;

    private TetrisController CONTROLLER;
    private Tetronimo tetronimo;
    private Rectangle[][] playingField;

    // HUD
    private TextBox scoreBox;
    private TextBox hsBox;
    private TextBox gameOverBox;
    private TextBox nextLabel;      // "NEXT" text
    private Rectangle nextTitleBox; // little box around "NEXT"
    private Rectangle nextFrame;    // frame around preview area

    // positions (shared with controller)
    private static final int PREVIEW_LEFT  = 280;
    private static final int PREVIEW_TOP   = 10;
    private static final int PREVIEW_W     = 120;
    private static final int PREVIEW_H     = 110;
    private static final int NEXT_OFFSET_Y = 80; // move the whole NEXT section down

    // game state
    private boolean gameOver = false;
    private volatile boolean resetRequested = false; //fix failure to reset mid game

    // thread for the game loop
    private Thread loopThread;

    /**
     * Constructor to initialize the board
     * Adds this object as a key listener, builds the board, grid overlay, and HUD,
     * creates the controller, syncs score labels, and starts the main loop.
     *
     * @param frame The wheelsunh frame (so we can add this class as a key listener for the frame)
     */
    public TetrisBoard(Frame frame)
    {
        frame.addKeyListener(this);

        /* this has to be done first, if not the merged pieces will bind to the board
        when rows are cleared they will remove the board as well
         */
        buildBoard();
        buildGridOverlay();
        buildHUD();

        this.CONTROLLER = new TetrisController(this);
        updateScore(CONTROLLER.getScore(), CONTROLLER.getHighScore());

        // run() executes on its own thread so the UI stays responsive
        //used ChatGPT to debug, there was inconsistency in when these would fire using the same thread

        loopThread = new Thread( new Runnable()
        {
            public void run()
            {
                TetrisBoard.this.run();
            }
        } );
        loopThread.start();
    }



    /**
     * Builds the playing field for tetris
     */
    private void buildBoard()
    {
        playingField = new Rectangle[WIDTH][HEIGHT];

        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = 0; j < HEIGHT; j++)
            {
                playingField[i][j] = new Rectangle();
                playingField[i][j].setLocation(i * Tetronimo.SIZE + 40, j * Tetronimo.SIZE);
                playingField[i][j].setSize(Tetronimo.SIZE, Tetronimo.SIZE);
                playingField[i][j].setColor(Color.WHITE);
                playingField[i][j].setFrameColor(Color.BLACK);
            }
        }
    }

    /**
     * Draws a thin grid overlay on top of the board (visual only)
     * keeps the board visible when the pieces merge together after colliding
     */
    private void buildGridOverlay()
    {
        final int left   = 40;
        final int top    = 0;
        final int right  = left + WIDTH  * Tetronimo.SIZE;
        final int bottom = top  + HEIGHT * Tetronimo.SIZE;

        for (int c = 0; c <= WIDTH; c++)
        {
            int x = left + c * Tetronimo.SIZE;
            Line v = new Line(x, top, x, bottom);
            v.setColor(Color.BLACK);
        }

        for (int r = 0; r <= HEIGHT; r++)
        {
            int y = top + r * Tetronimo.SIZE;
            Line h = new Line(left, y, right, y);
            h.setColor(Color.BLACK);
        }
    }



    /**
     * Builds the HUD elements (preview title box and label, preview frame,
     * score/high score labels, reset hint, and game over banner)
     */
    private void buildHUD()
    {

        int frameX = PREVIEW_LEFT;
        int textY = PREVIEW_TOP + NEXT_OFFSET_Y;

        // box around the text "Next"
        nextTitleBox = new Rectangle();
        nextTitleBox.setLocation(280, 60);
        nextTitleBox.setSize(120, 100);
        nextTitleBox.setColor(Color.WHITE);
        nextTitleBox.setFrameColor(Color.BLACK);
        // code for the "Next" text above the piece
        nextLabel = new TextBox("NEXT");
        nextLabel.setLocation(320, 64);
        nextLabel.setSize(65, 28);
        nextLabel.setFrameColor(Color.WHITE);
        nextLabel.setColor(Color.WHITE);

        // Box going around the next piece frame
        nextFrame = new Rectangle();
        nextFrame.setLocation(280, 96);
        nextFrame.setSize(120, 100);
        nextFrame.setColor(Color.WHITE);
        nextFrame.setFrameColor(Color.BLACK);


        //location for the current/high score
        int textX = frameX + PREVIEW_W + 16;

        /*  these have white backgrounds so it blends in with the playing field
            if you feel these need to be moved please be careful as they will cover other
            things present in the game board
         */

        scoreBox = new TextBox("Score: 0");
        scoreBox.setLocation(textX, textY);
        scoreBox.setSize(180, 24);
        scoreBox.setFrameColor(Color.BLACK);
        scoreBox.setColor(Color.WHITE);

        hsBox = new TextBox("High: 0");
        hsBox.setLocation(textX, textY + 26);   // original position
        hsBox.setSize(180, 24);
        hsBox.setFrameColor(Color.BLACK);
        hsBox.setColor(Color.WHITE);

        // Always-visible reset hint under the frame

        TextBox resetHint = new TextBox("Press R to Reset");
        resetHint.setLocation(frameX, textY + PREVIEW_H + 200);
        resetHint.setSize(180, 28);                 // taller to avoid clipping
        resetHint.setFrameColor(Color.WHITE);
        resetHint.setColor(Color.WHITE);

        // Game Over message box — placed further down
        gameOverBox = new TextBox("");
        gameOverBox.setLocation(frameX - 20, textY + PREVIEW_H + 68);
        gameOverBox.setSize(260, 60);
        gameOverBox.setFrameColor(Color.WHITE);
        gameOverBox.setColor(Color.WHITE);
    }

    /**
     * Shows a game over message and red frame with a reset hint
     *
     * @param message The message to display
     */
    public void showGameOver(String message)
    {
        if (gameOverBox != null)
        {
            gameOverBox.setColor(Color.WHITE);
            gameOverBox.setFrameColor(Color.RED);
            gameOverBox.setText((message + " - Press R to Reset").toUpperCase());
        }
    }

    /**
     * Hides the game over message
     */
    public void hideGameOver()
    {
        if (gameOverBox != null)
        {
            gameOverBox.setText("");
            gameOverBox.setFrameColor(Color.WHITE);
        }
    }



    /**
     * Starts gameplay and is responsible for keeping the game going
     */
    public void run()
    {
        while (true)
        {
            if (resetRequested)
            {
                resetGame();
                resetRequested = false;
                Utilities.sleep(50);
                continue;
            }

            if (gameOver) { Utilities.sleep(120); continue; }

            tetronimo = CONTROLLER.getNextTetromino();

            // Spawn safety: nudge upward until at least one free downward step
            int safetyRows = 6;
            while (!CONTROLLER.canMove(tetronimo, 0, 1) && safetyRows-- > 0)
            {
                tetronimo.setLocation(
                        tetronimo.getXLocation(),
                        tetronimo.getYLocation() - Tetronimo.SIZE
                );
            }

            if (!CONTROLLER.canMove(tetronimo, 0, 1))
            {
                showGameOver("Game Over");
                gameOver = true;
                continue;
            }

            // Let it fall while it can
            while (CONTROLLER.tetronimoLanded(tetronimo))
            {
                if (resetRequested) break;

                tetronimo.setLocation(
                        tetronimo.getXLocation(),
                        tetronimo.getYLocation() + Tetronimo.SIZE
                );
                Utilities.sleep(500);
            }

            if (resetRequested) continue;

            boolean topOut = CONTROLLER.lockToGrid(tetronimo);
            tetronimo.setLocation(-1000, -1000);

            //cascade clears so that newly-fallen rows that become full are also cleared
            int cleared;
            do {
                cleared = CONTROLLER.clearFullLines();
            } while (cleared > 0);

            if (topOut)
            {
                showGameOver("Game Over");
                gameOver = true;
            }
            else
            {
                Utilities.sleep(200);
            }
        }
    }



    /**
     * Getter method for the array representing the playing field, not used yet but will be needed by the controller later
     *
     * @return The playing field
     */
    public Rectangle[][] getPlayingField() { return playingField; }

    /**
     * Called by controller after scoring changes
     *
     * @param score The current score
     * @param highScore The current high score
     */
    public void updateScore(int score, int highScore)
    {
        if (scoreBox != null) scoreBox.setText("Score: " + score);
        if (hsBox    != null) hsBox.setText("High: "  + highScore);
    }

    /**
     * Resets the board and HUD to a clean state
     */
    private void resetGame()
    {
        for (int i = 0; i < WIDTH; i++)
            for (int j = 0; j < HEIGHT; j++)
            {
                playingField[i][j].setColor(Color.WHITE);
                playingField[i][j].setFrameColor(Color.BLACK);
            }

        hideGameOver();
        gameOver = false;

        if (tetronimo != null)
            tetronimo.setLocation(-1000, -1000);
        tetronimo = null;

        CONTROLLER.resetScore();   // keep high score persistent
    }


    /**
     * This method is not used in this program
     *
     * @param e The key event
     */
    @Override
    public void keyTyped( KeyEvent e )
    {
        //not in use
    }

    /**
     * Handles the key events by the user (INCOMPLETE)
     *
     * @param e The key event
     */
    @Override
    public void keyPressed(KeyEvent e)
    {
        int key = e.getKeyCode();

        if (key == KeyEvent.VK_R) { resetRequested = true; return; }
        if (gameOver) { return; }
        if (tetronimo == null) { return; }

        /*
         *   Changed the case number itself to using the keyevent from the docs
         *   this allows for faster debugging of keystrokes as well as adding/removing
         *   unnecessary actions that the keys do.
         *
         *   Illegal rotates now throw a small MoveBlockedException from the controller.
         *   We catch and ignore it, which allows for same action as before simply doing nothing.
         *   This allows for more robustness in the code.
         */
        try
        {
            switch (key)
            {
                case KeyEvent.VK_UP:
                    CONTROLLER.tryRotate(tetronimo);
                    break;

                case KeyEvent.VK_LEFT:
                    if (CONTROLLER.canMove(tetronimo, -1, 0))
                        tetronimo.shiftLeft();
                    break;

                case KeyEvent.VK_RIGHT:
                    if (CONTROLLER.canMove(tetronimo, 1, 0))
                        tetronimo.shiftRight();
                    break;

                case KeyEvent.VK_DOWN: // soft drop
                    if (CONTROLLER.canMove(tetronimo, 0, 1))
                    {
                        tetronimo.setLocation(
                                tetronimo.getXLocation(),
                                tetronimo.getYLocation() + Tetronimo.SIZE
                        );
                    }
                    break;

                case KeyEvent.VK_SPACE: // hard drop
                    while (CONTROLLER.canMove(tetronimo, 0, 1))
                    {
                        tetronimo.setLocation(
                                tetronimo.getXLocation(),
                                tetronimo.getYLocation() + Tetronimo.SIZE
                        );
                    }
                    break;
            }
        }
        catch ( MoveBlockedException ignore )
        {
            // do nothing
        }
        catch ( Exception unexpected )
        {
            System.err.println("Unexpected input error: " + unexpected.getMessage());
        }
    }

    /**
     * This method is not used in this program
     *
     * @param e The key event
     */
    @Override public void keyReleased(KeyEvent e) { /* not used */ }
}
