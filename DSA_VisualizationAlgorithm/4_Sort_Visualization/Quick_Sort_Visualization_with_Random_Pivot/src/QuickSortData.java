import java.util.Arrays;

public class QuickSortData {

    public enum Type{
        Default,
        NearlyOrdered
    }

    private int[] numbers;
    public int l, r;
    public boolean[] fixedPivots;  // fixedPivots[i] = true表示第i个元素已经找好位置
    public int curPivot;  // 当前标定点
    public int curElement;  // 当前考察的元素

    public QuickSortData(int N, int randomBound, Type dataType){
        numbers = new int[N];
        fixedPivots = new boolean[N];

        for (int i = 0; i < N; i++){
            numbers[i] = (int)(Math.random() * randomBound) + 1;
            fixedPivots[i] = false;
        }

        if (dataType == Type.NearlyOrdered){
            Arrays.sort(numbers);
            int swapTime = (int)(0.02 * N);
            for (int i = 0; i < swapTime; i++){
                int a = (int)(Math.random() * N);
                int b = (int)(Math.random() * N);
                swap(a, b);
            }
        }
    }

    public int N(){
        return numbers.length;
    }

    public int get(int index){
        if (index < 0 || index >= numbers.length)
            throw new IllegalArgumentException("Invalid index to access Sort Data.");

        return numbers[index];
    }

    public void swap(int i, int j){
        if (i < 0 || i >= numbers.length || j < 0 || j >= numbers.length)
            throw new IllegalArgumentException("Invalid index to access Sort Data.");

        int t = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = t;
    }

}
