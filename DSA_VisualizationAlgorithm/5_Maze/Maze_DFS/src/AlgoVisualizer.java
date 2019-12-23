import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;

public class AlgoVisualizer {  // 控制层

    private MazeData data;        // 数据
    private AlgoFrame frame;    // 视图
    private static int DELAY = 1;
    private static int blockSide = 8;
    private static final int d[][] = {{-1,0},{0,1},{1,0},{0,-1}};  // 左，下，右，上

    public AlgoVisualizer(String mazeFile){
        // 初始化数据
        data = new MazeData(mazeFile);
        int sceneWidth = data.M() * blockSide;
        int sceneHeight = data.N() * blockSide;

        // 初始化视图
        EventQueue.invokeLater(()->{  // GUI创建的代码放到了新的线程(事件分发线程，事件派生队列)中
            frame = new AlgoFrame("Maze", sceneWidth, sceneHeight);

            new Thread(() -> {
                run();
            }).start();
        });
    }

    // 动画逻辑
    private void run(){
        setData(-1, -1, false);

        data.path[data.getEntranceX()][data.getEntranceY()] = true;
        if (!go(data.getEntranceX(), data.getEntranceX()))
            System.out.println("The maze has no solution!");

        setData(-1, -1, false);
    }

    // 从(x,y)的位置开始求解迷宫，如果求解成功，返回true；否则返回false
    private boolean go(int x, int y){
        if(!data.inArea(x,y))
            throw new IllegalArgumentException("x,y are out of index in go function!");

        data.visited[x][y] = true;
        setData(x, y, true);

        if (x == data.getExitX() && y == data.getExitY())
            return true;

        for (int i = 0; i < 4; i++){
            int newX = x + d[i][0];
            int newY = y + d[i][1];
            if (data.inArea(newX, newY) &&  // 坐标合法
                    data.getMaze(newX, newY) == MazeData.ROAD &&  // 能走通
                    !data.visited[newX][newY])  // 没有访问过
                if (go(newX, newY))
                    return true;
        }

        // 回溯
        setData(x, y, false);

        return false;
    }

    private void setData(int x, int y, boolean isPath){
        if (data.inArea(x, y))
            data.path[x][y] = isPath;

        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    public static void main(String[] args) {

        String mazeFile = "maze_101_101.txt";

        // TODO: 根据需要设置其他参数，初始化visualizer
        AlgoVisualizer visualizer = new AlgoVisualizer(mazeFile);
    }
}
