import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.MouseAdapter;
import java.util.Arrays;

public class AlgoVisualizer {  // 控制层
    // TODO：创建自己的数据
    private MergeSortData data;        // 数据
    private AlgoFrame frame;    // 视图
    private static int DELAY = 40;

    public AlgoVisualizer(int sceneWidth, int sceneHeight, int N){
        // 初始化数据
        data = new MergeSortData(N, sceneHeight);

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
        setData(-1, -1, -1);

        mergeSort(0, data.N() - 1);

        setData(0, data.N() - 1, data.N()-1);

    }
    private void mergeSort(int l, int r){
        if (l >= r)
            return;

        setData(l, r, -1);

        int mid = (r - l) / 2 + l;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, mid, r);
    }

    private void merge(int l, int mid, int r){
        int[] aux = Arrays.copyOfRange(data.numbers, l, r+1);

        int i = l;
        int j = mid + 1;
        for (int k = l; k <= r; k++){
            if (i > mid){  // 如果左半部分元素已经全部处理完毕
                data.numbers[k] = aux[j - l];
                j++;
            }
            else if (j > r){  // 如果右半部分元素已经全部处理完毕
                data.numbers[k] = aux[i - l];
                i++;
            }
            else if (aux[i - l] < aux[j - l]){  // 左半部分所指元素 < 右半部分所指元素
                data.numbers[k] = aux[i - l];
                i++;
            }
            else {  // 左半部分所指元素 >= 右半部分所指元素
                data.numbers[k] = aux[j - l];
                j++;
            }
            setData(l, r, k);
        }
    }

    private void setData(int l, int r, int mergeIndex){
        data.l = l;
        data.r = r;
        data.mergeIndex = mergeIndex;

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
