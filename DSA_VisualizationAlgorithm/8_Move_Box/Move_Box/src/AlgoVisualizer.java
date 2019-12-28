import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class AlgoVisualizer {  // 控制层

    private GameData data;        // 数据
    private AlgoFrame frame;    // 视图

    private static int DELAY = 5;
    private static int blockSize = 80;

    public AlgoVisualizer(String filename){
        // 初始化数据
        data = new GameData(filename);
        int sceneWidth = data.M() * blockSize;
        int sceneHeight = data.N() * blockSize;

        // 初始化视图
        EventQueue.invokeLater(()->{  // GUI创建的代码放到了新的线程(事件分发线程，事件派生队列)中
            frame = new AlgoFrame("Move Box", sceneWidth, sceneHeight);

            frame.addMouseListener(new AlgoMouseListener());
            new Thread(() -> {
                run();
            }).start();
        });
    }

    // 动画逻辑
    private void run(){
        setData(-1, -1);

        if(data.solve())
            System.out.println("The game has a solution!");
        else
            System.out.println("The game does NOT have a solution.");

        setData(-1, -1);

    }

    private void setData(int clickx, int clicky){
        data.clickx = clickx;
        data.clicky = clicky;

        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    private Position clickPos1 = null;
    private Position clickPos2 = null;
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

            if (SwingUtilities.isLeftMouseButton(event)){
                if (data.inArea(x, y)){
                    setData(x, y);
                    if (null == clickPos1){
                        clickPos1 = new Position(x, y);
                    } else {
                        clickPos2 = new Position(x, y);
                        if (clickPos2.nextTo(clickPos1)){
                            data.getShowBoard().swap(clickPos1.getX(), clickPos1.getY(), clickPos2.getX(), clickPos2.getY());
                            data.getShowBoard().run();
                        }
                        clickPos1 = null;
                        clickPos2 = null;
                    }
                }
            }
            else {
                setData(-1, -1);
                clickPos1 = null;
                clickPos2 = null;
            }
        }
    }

    public static void main(String[] args) {

        String filename = "level/osaka_05.txt";

        // TODO: 根据需要设置其他参数，初始化visualizer
        AlgoVisualizer visualizer = new AlgoVisualizer(filename);
    }
}
