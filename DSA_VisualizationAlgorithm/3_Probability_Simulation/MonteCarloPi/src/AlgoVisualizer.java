import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;

public class AlgoVisualizer {  // 控制层
    private MonteCarloPiData data;      // 数据
    private int N;
    private AlgoFrame frame;            // 视图
    private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N){
        // 初始化数据
        if(sceneWidth != sceneHeight)
            throw new IllegalArgumentException("This demo must be run in a square window!");

        this.N = N;
        Circle circle = new Circle(sceneWidth/2, sceneHeight/2, sceneHeight/2);
        data = new MonteCarloPiData(circle);

        // 初始化视图
        EventQueue.invokeLater(()->{  // GUI创建的代码放到了新的线程(事件分发线程，事件派生队列)中
            frame = new AlgoFrame("Welcome", sceneWidth, sceneHeight);
            new Thread(() -> {
                run();
            }).start();
        });
    }

    // 动画逻辑
    private void run(){
        for (int i = 0; i < N; i++){
            if (i % 100 == 0){
                frame.render(data);
                AlgoVisHelper.pause(DELAY);
                System.out.println(data.estimatePi());
            }

            int x = (int)(Math.random() * frame.getCanvasWidth());
            int y = (int)(Math.random() * frame.getCanvasHeight());
            data.addPoint(new Point(x, y));
        }

    }

    public static void main(String[] args) {

        int sceneWidth = 800;
        int sceneHeight = 800;
        int N = 20000;

        // TODO: 根据需要设置其他参数，初始化visualizer
        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, N);
    }
}
