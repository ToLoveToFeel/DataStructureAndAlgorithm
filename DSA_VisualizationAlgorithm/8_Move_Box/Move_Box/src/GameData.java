import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class GameData {

    private int maxTurn;  // 游戏最多移动次数
    private int N, M;  // 画面行数，列数，根据读取的文件内容确定
    private Board startBoard;  // 游戏初始画面
    private Board showBoard;  // 游戏展示画面

    public int clickx = -1, clicky = -1;

    public GameData(String filename){
        if (null == filename)
            throw new IllegalArgumentException("Filename cannot be null!");

        Scanner scanner = null;
        try {
            File file = new File(filename);
            if (!file.exists())
                throw new IllegalArgumentException("File " + filename + " doesn't exist!");

            FileInputStream fis = new FileInputStream(file);
            scanner = new Scanner(new BufferedInputStream(fis), "UTF-8");

            String turnLine = scanner.nextLine();
            this.maxTurn = Integer.parseInt(turnLine);

            ArrayList<String> lines = new ArrayList<String>();
            while (scanner.hasNextLine()){
                String line = scanner.nextLine();
                lines.add(line);
            }
            startBoard = new Board(lines.toArray(new String[lines.size()]));

            this.N = startBoard.N();
            this.M = startBoard.M();

            startBoard.print();

            showBoard = new Board(startBoard);
        }
        catch (IOException e){
            e.printStackTrace();
        }
        finally {
            if (null != scanner)
                scanner.close();
        }
    }


    public int N(){ return N; }
    public int M(){ return M; }
    public Board getShowBoard(){ return showBoard;}

    public boolean inArea(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    public boolean solve(){

        if(maxTurn < 0)
            return false;

        return solve(startBoard, maxTurn);
    }

    private static int d[][] = {{1, 0}, {0, 1}, {0,-1}};  // 下，右，左
    // 对于棋盘board，在turn步内是否可以解决这个问题，若能返回true，否则返回false
    private boolean solve(Board board, int turn){
        if(null == board || turn < 0)
            throw new IllegalArgumentException("board can not be null in solve function!");

        if (0 == turn)  // 如果步数用完，判断是否胜利
            return board.isWin();

        if (board.isWin())  // 否则，步数没用完，判断是否能成功，只要在步骤内消除所有物块就成功
            return true;

        for (int x = 0; x < N; x++)
            for (int y = 0; y < M; y++)
                if (Board.EMPTY != board.getData(x, y)){
                    for (int i = 0; i < 3; i++){
                        int newX = x + d[i][0];
                        int newY = y + d[i][1];
                        if (inArea(newX, newY)){
                            String swapString = String.format("swap (%d, %d) and (%d, %d)", x, y, newX, newY);
                            Board nextBoard = new Board(board, board, swapString);
                            nextBoard.swap(x, y, newX, newY);
                            nextBoard.run();
                            if (solve(nextBoard, turn - 1))
                                return true;
                        }
                    }
                }

        return false;
    }

}
