import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;
import java.util.Arrays;

public class AlgoVisualizer {  // 控制层

    private int[] money;        // 数据
    private AlgoFrame frame;    // 视图
    private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight){
        // 初始化数据
        money = new int[100];
        for (int i = 0; i < money.length; i++)
            money[i] = 50;

        // 初始化视图
        EventQueue.invokeLater(()->{  // GUI创建的代码放到了新的线程(事件分发线程，事件派生队列)中
            frame = new AlgoFrame("Money Problem", sceneWidth, sceneHeight);
            new Thread(() -> {
                run();
            }).start();
        });
    }

    // 动画逻辑
    private void run(){
        while (true){
            Arrays.sort(money);
            frame.render(money);
            AlgoVisHelper.pause(DELAY);

            for (int k = 0; k < 50; k++)
                for (int i = 0; i < money.length; i++){
                    int j = (int)(Math.random() * money.length);
                    money[j] += 1;
                    money[i] -= 1;
                }
        }

    }

    public static void main(String[] args) {

        int sceneWidth = 800;
        int sceneHeight = 800;

        // TODO: 根据需要设置其他参数，初始化visualizer
        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight);
    }
}
