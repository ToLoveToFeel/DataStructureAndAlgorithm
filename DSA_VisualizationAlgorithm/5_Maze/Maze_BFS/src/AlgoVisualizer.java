import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;
import java.util.LinkedList;

public class AlgoVisualizer {  // 控制层

    private MazeData data;        // 数据
    private AlgoFrame frame;    // 视图
    private static int DELAY = 1;
    private static int blockSide = 8;
    private static final int d[][] = {{-1,0},{0,1},{1,0},{0,-1}};  // 上，右，下，左

    public AlgoVisualizer(String mazeFile){
        // 初始化数据
        data = new MazeData(mazeFile);
        int sceneWidth = data.M() * blockSide;
        int sceneHeight = data.N() * blockSide;

        // 初始化视图
        EventQueue.invokeLater(()->{  // GUI创建的代码放到了新的线程(事件分发线程，事件派生队列)中
            frame = new AlgoFrame("Maze BFS", sceneWidth, sceneHeight);

            new Thread(() -> {
                run();
            }).start();
        });
    }

    // 动画逻辑
    private void run(){
        setData(-1, -1, false);

        // 广度优先遍历
        LinkedList<Position> queue = new LinkedList<>();
        Position entrance = new Position(data.getEntranceX(), data.getEntranceY());
        queue.addLast(entrance);
        data.visited[data.getEntranceX()][data.getEntranceY()] = true;

        boolean isSolved = false;

        while (0 != queue.size()){
            Position curPos = queue.pop();
            setData(curPos.getX(), curPos.getY(), true);

            if (curPos.getX() == data.getExitX() && curPos.getY() == data.getExitY()){
                isSolved = true;
                findPath(curPos);
                break;
            }

            for (int i = 0; i < 4; i++){
                int newX = curPos.getX() + d[i][0];
                int newY = curPos.getY() + d[i][1];
                if (data.inArea(newX, newY) &&
                        !data.visited[newX][newY] &&
                        data.getMaze(newX, newY) == MazeData.ROAD){
                    queue.addLast(new Position(newX, newY, curPos));
                    data.visited[newX][newY] = true;
                }
            }
        }

        if (!isSolved)
            System.out.println("The maze has no Solution!");

        setData(-1, -1, false);
    }

    private void findPath(Position des){
        Position cur = des;
        while (null != cur){
            data.result[cur.getX()][cur.getY()] = true;
            cur = cur.getPrev();
        }
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
