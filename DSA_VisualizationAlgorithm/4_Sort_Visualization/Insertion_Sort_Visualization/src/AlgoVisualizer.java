import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;

public class AlgoVisualizer {  // 控制层

    private InsertionSortData data;        // 数据
    private AlgoFrame frame;    // 视图
    private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N){
        // 初始化数据
        data = new InsertionSortData(N, sceneHeight);

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
        setData(0, -1);

        for (int i = 1; i < data.N(); i++){
            setData(i, i);
            for (int j = i; j > 0 && data.get(j) < data.get(j-1); j--){
                data.swap(j, j-1);
                setData(i+1, j-1);
            }
        }

//        for (int i = 1; i < data.N(); i++){
//            setData(i, i);
//            int element = data.get(i);
//            int j = i;
//            for (; j > 0 && data.get(j-1) > element; j--){
//                data.set(j, data.get(j-1));
//                setData(i+1, j-1);
//            }
//            data.set(j, element);
//            setData(i+1, j+1);
//        }

        setData(data.N(), -1);
    }

    private void setData(int orderedIndex, int currentIndex){
        data.orderedIndex = orderedIndex;
        data.currentIndex = currentIndex;

        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    public static void main(String[] args) {

        int sceneWidth = 800;
        int sceneHeight = 800;
        int N = 100;

        // TODO: 根据需要设置其他参数，初始化visualizer
        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, N);
    }
}
