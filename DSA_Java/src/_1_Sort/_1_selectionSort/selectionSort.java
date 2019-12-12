package _1_Sort._1_selectionSort;
import _1_Sort.SortTestHelper;

public class selectionSort {

    public static void sort(Comparable[] arr){
        int n = arr.length;

        for (int i = 0; i < n; i++){
            int indexMin = i;
            for (int j = i+1; j < n; j++)
                if (arr[j].compareTo(arr[indexMin]) < 0)
                    indexMin = j;

            if (indexMin != i)
                swap(arr, i, indexMin);
        }
    }

    public static void swap(Object[] arr, int i, int j){
        Object t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public static void main(String[] args) {
        int n = 10000;  // 0.1s
        Integer[] arr =SortTestHelper.generateRandomArray(n, 0,100000);
        SortTestHelper.testSort("_1_Sort._1_selectionSort.selectionSort", arr);
    }
}
