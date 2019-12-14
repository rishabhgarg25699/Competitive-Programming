//                                                 MAZE PROGRAM USING BACKTRACKING ALGORITHMIC APPROACH


public class MazeBacktracking {

    final static int SIZE = 5;

    public static int[][] maze =
    {
        {0,1,0,1,1},
        {0,0,0,1,1},
        {0,1,0,0,1},
        {0,0,1,0,0},
        {1,0,0,1,0}
    };

    public static int[][] solution = new int[SIZE][SIZE];

    public static void printsolution() {
        int i, j;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++)
                System.out.print(solution[i][j]+"\t");

            System.out.println("");
        }
    }

    public static boolean solvemaze(int r, int c)
    {

        //if destination is reached, maze is solved
        if((r==SIZE-1) && (c==SIZE-1))
        {
            solution[r][c] = 1;
            return true;
        }
        

        //indices of the cell must be in (0,SIZE-1)
        //solution[r][c] == 0 is making sure that the cell is not already visited
        //maze[r][c] == 0 is making sure that the cell is not blocked
        if(r>=0 && c>=0 && r<SIZE && c<SIZE && solution[r][c] == 0 && maze[r][c] == 0)
        {
            //if safe to visit then visit the cell
            solution[r][c] = 1;

            //for going down
            if(solvemaze(r+1, c))
                return true;
            //for going right
            if(solvemaze(r, c+1))
                return true;
            //for going up
            if(solvemaze(r-1, c))
                return true;
            //for going left
            if(solvemaze(r, c-1))
                return true;

            //BACKTRACKING
            solution[r][c] = 0;
            return false;
        }
        return false;
    }





    public static void main(String[] args) {


        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
                solution[i][j] = 0;
        }

        if (solvemaze(0,0)){
            System.out.println("Solution to Maze:\n");
            printsolution();
            System.out.println("\nHere, 1 represents the path followed.");
        }
        else
            System.out.println("No possible solution");

    }



}
