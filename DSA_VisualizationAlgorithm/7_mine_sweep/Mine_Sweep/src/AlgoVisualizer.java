import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class AlgoVisualizer {  // 控制层
    // TODO：创建自己的数据
    private MineSweepData data;        // 数据
    private AlgoFrame frame;    // 视图
    private static int DELAY = 40;
    private static int blockSide = 32;

    public AlgoVisualizer(int N, int M, int mineNumber){
        // 初始化数据
        data = new MineSweepData(N, M, mineNumber);
        int sceneWidth =  M * blockSide;
        int sceneHeight = N * blockSide;

        // 初始化视图
        EventQueue.invokeLater(()->{  // GUI创建的代码放到了新的线程(事件分发线程，事件派生队列)中
            frame = new AlgoFrame("Welcome", sceneWidth, sceneHeight);

            frame.addMouseListener(new AlgoMouseListener());  // 通知AlgoFrame监听鼠标事件
            new Thread(() -> {
                run();
            }).start();
        });
    }

    // 动画逻辑
    private void run(){

        this.setData(false, -1, -1);

    }

    private void setData(boolean isLeftClicked, int x, int y){
        if (isLeftClicked){  // 左键点击
            if (data.inArea(x, y))
                if (data.isMine(x, y)){  // 是雷
                    // Game Over
                    data.open[x][y] = true;
                }
                else  // 不是雷
                    data.open(x, y);
        }
        else {  //右键点击
            if (data.inArea(x, y)){
                data.flags[x][y] = !data.flags[x][y];
            }
        }

        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    // frame监听鼠标事件
    private class AlgoMouseListener extends MouseAdapter {
        @Override
        public void mouseReleased(MouseEvent event){
            event.translatePoint(
                    -(int)(frame.getBounds().width - frame.getCanvasWidth()),
                    -(int)(frame.getBounds().height - frame.getCanvasHeight())
            );

            Point pos = event.getPoint();
            int w = frame.getCanvasWidth() / data.M();
            int h = frame.getCanvasHeight() / data.N();

            int x = pos.y / h;
            int y = pos.x / w;

            if (SwingUtilities.isLeftMouseButton(event))
                setData(true, x, y);
            else if (SwingUtilities.isRightMouseButton(event))
                setData(false, x, y);
        }
    }

    public static void main(String[] args) {

        int N = 20;
        int M = 20;
        int mineNumber = 20;

        // TODO: 根据需要设置其他参数，初始化visualizer
        AlgoVisualizer visualizer = new AlgoVisualizer(N, M, mineNumber);
    }
}
