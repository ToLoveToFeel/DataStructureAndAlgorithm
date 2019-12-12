package _1_Sort._2_insertionSort;
import _1_Sort.SortTestHelper;

public class insertionSort {

    // 我们的算法类不允许产生任何实例
    private insertionSort(){}

    public static void sort(Comparable[] arr){
        int n = arr.length;

        for (int i = 1; i < n; i++){
            Comparable e = arr[i];
            int j = i;
            for ( ; j > 0 && arr[j-1].compareTo(e) > 0; j--)
                arr[j] = arr[j-1];
            arr[j] = e;
        }
    }

    public static void swap(Object[] arr, int i, int j){
        Object t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public static void main(String[] args) {
        int n = 10000;  // 0.1s
        Integer[] arr = SortTestHelper.generateRandomArray(n, 0,100000);
        SortTestHelper.testSort("_1_Sort._2_insertionSort.insertionSort", arr);
    }

}
