import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;

public class AlgoVisualizer {  // 控制层

    private QuickSortData data;        // 数据
    private AlgoFrame frame;    // 视图
    private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N, QuickSortData.Type dataType){
        // 初始化数据
        data = new QuickSortData(N, sceneHeight, dataType);

        // 初始化视图
        EventQueue.invokeLater(()->{  // GUI创建的代码放到了新的线程(事件分发线程，事件派生队列)中
            frame = new AlgoFrame("Quick Sort Visualization with Three Ways", sceneWidth, sceneHeight);

            new Thread(() -> {
                run();
            }).start();
        });
    }

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N){
        this(sceneWidth, sceneHeight, N, QuickSortData.Type.Default);
    }

    // 动画逻辑
    private void run(){
        setData(-1, -1, -1, -1, -1, -1, -1);

        quickSort3Ways(0, data.N() - 1);

        setData(-1, -1, -1, -1, -1, -1, -1);
    }

    private void quickSort3Ways(int l, int r){
        if (l > r)
            return;

        if (l == r){
            setData(l, r, l, -1, -1, -1, -1);
            return;
        }

        // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
        int p = (int)(Math.random()*(r-l+1)) + l;
        setData(l, r, -1, p, -1, -1, -1);

        data.swap(l, p);
        int v = data.get(l);
        setData(l, r, -1, l, -1, -1, -1);

        int lt = l;     // arr[l+1...lt] < v
        int gt = r + 1; // arr[gt...r] > v
        int i = l+1;    // arr[lt+1...i) == v
        setData(l, r, -1, l, lt, -1, gt);
        while (i < gt){
            if (data.get(i) < v){
                data.swap(i, lt+1);
                i++;
                lt++;
            }
            else if (data.get(i) > v){
                data.swap(i, gt-1);
                gt--;
            }
            else
                i++;
            setData(l, r, -1, l, lt, i, gt);
        }

        data.swap( l, lt );
        setData(l, r, lt, -1, -1, -1, -1);

        quickSort3Ways(l, lt - 1);
        quickSort3Ways(gt, r);
    }

    private void setData(int l, int r, int fixedPivot, int curPivot, int lt, int curElement, int gt){
        data.l = l;
        data.r = r;
        if(fixedPivot != -1){
            data.fixedPivots[fixedPivot] = true;
            int i = fixedPivot;
            while(i < data.N() && data.get(i) == data.get(fixedPivot)){
                data.fixedPivots[i] = true;
                i ++;
            }
        }
        data.curPivot = curPivot;
        data.lt = lt;
        data.curElement = curElement;
        data.gt = gt;

        frame.render(data);
        AlgoVisHelper.pause(DELAY);
    }

    public static void main(String[] args) {

        int sceneWidth = 800;
        int sceneHeight = 800;
        int N = 100;

        // TODO: 根据需要设置其他参数，初始化visualizer
//        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, N);
//        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, N, QuickSortData.Type.Identical);
        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHeight, N, QuickSortData.Type.NearlyIdentical);

    }
}
