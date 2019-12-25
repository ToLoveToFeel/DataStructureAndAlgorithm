import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;

public class AlgoVisualizer {  // 控制层

    private MazeData data;        // 数据
    private AlgoFrame frame;    // 视图
    private static int DELAY = 1;
    private static int blockSide = 8;
    private static final int d[][] = {{-1,0},{0,1},{1,0},{0,-1}};  // 上，右，下，左

    public AlgoVisualizer(int N, int M){
        // 初始化数据
        data = new MazeData(N, M);
        int sceneWidth = data.M() * blockSide;
        int sceneHeight = data.N() * blockSide;

        // 初始化视图
        EventQueue.invokeLater(()->{  // GUI创建的代码放到了新的线程(事件分发线程，事件派生队列)中
            frame = new AlgoFrame("Maze Generalization DFS", sceneWidth, sceneHeight);

            new Thread(() -> {
                run();
            }).start();
        });
    }

    // 动画逻辑
    private void run(){
        setData(-1, -1);

        go(data.getEntranceX(), data.getEntranceY() + 1);

        setData(-1, -1);
    }

    private void go(int x, int y){
        if(!data.inArea(x,y))
            throw new IllegalArgumentException("x,y are out of index in go function!");

        data.visited[x][y] = true;
        for (int i = 0; i < 4; i++){
            int newX = x + d[i][0] * 2;
            int newY = y + d[i][1] * 2;
            if (data.inArea(newX, newY) && !data.visited[newX][newY]){
                setData(x + d[i][0], y + d[i][1]);
                go(newX, newY);
            }
        }
    }

    private void setData(int x, int y){
        if(data.inArea(x, y))
            data.maze[x][y] = MazeData.ROAD;
        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    public static void main(String[] args) {

        int N = 101;  // 行数
        int M = 101;  // 列数

        // TODO: 根据需要设置其他参数，初始化visualizer
        AlgoVisualizer visualizer = new AlgoVisualizer(N, M);
    }
}
