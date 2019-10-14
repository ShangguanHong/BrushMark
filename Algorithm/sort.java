import java.util.ArrayList;
import java.util.Arrays;

/**
 * @author sgh
 * @date 2019/10/14 9:05
 */
class Sort {

    /**
     * 冒泡算法
     */
    void bubbleSort(int[] array) {
        int len = array.length;
        if (len == 0) {
            return;
        }
        boolean needOrder;
        for (int i = 0; i < len; i++) {
            needOrder = false;
            for (int j = 0; j < len - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    needOrder = true;
                    swap(array, j, j + 1);
                }
            }
            if (!needOrder) {
                break;
            }
        }
    }

    /**
     * 选择排序
     */
    void selectionSort(int[] array) {
        int len = array.length;
        if (len == 0) {
            return;
        }
        for (int i = 0; i < len; i++) {
            int minIndex = i;
            for (int j = i; j < len; j++) {
                if (array[minIndex] > array[j]) {
                    minIndex = j;
                }
            }
            swap(array, i, minIndex);
        }
    }

    /**
     * 插入排序
     */
    void insertionSort(int[] array) {
        int len = array.length;
        if (len == 0) {
            return;
        }
        int current, preIndex;
        for (int i = 1; i < len; i++) {
            current = array[i];
            preIndex = i - 1;
            while (preIndex >= 0 && array[preIndex] > current) {
                array[preIndex + 1] = array[preIndex];
                preIndex--;
            }
            array[preIndex + 1] = current;
        }
    }

    /**
     * 希尔排序
     */
    void ShellSort(int[] array) {
        int len = array.length;
        if (len == 0) {
            return;
        }
        int current, gap = len / 2, preIndex;
        while (gap > 0) {
            for (int i = gap; i < len; i++) {
                current = array[i];
                // 每次步长为gap
                preIndex = i - gap;
                while (preIndex >= 0 && array[preIndex] > current) {
                    array[preIndex + gap] = array[preIndex];
                    preIndex -= gap;
                }
                array[preIndex + gap] = current;
            }
            gap /= 2;
        }
    }

    /**
     * 归并排序
     */
    int[] mergeSort(int[] array) {
        int len = array.length;
        if (len < 2) {
            return array;
        }
        int mid = len / 2;
        int[] left = Arrays.copyOfRange(array, 0, mid);
        int[] right = Arrays.copyOfRange(array, mid, len);
        return merge(mergeSort(left), mergeSort(right));
    }

    /**
     * 归并排序——将两段排序好的数组结合成一个排序数组
     */
    private int[] merge(int[] left, int[] right) {
        int l = left.length;
        int r = right.length;
        int len = l + r;
        int[] res = new int[len];
        for (int index = 0, i = 0, j = 0; index < len; ) {
            if (i == l) {
                res[index++] = right[j++];
            } else if (j == r) {
                res[index++] = left[i++];
            } else if (left[i] < right[j]) {
                res[index++] = left[i++];
            } else {
                res[index++] = right[j++];
            }
        }
        return res;
    }

    /**
     * 快速排序
     */
    int[] quickSort(int[] array, int start, int end) {
        if (start < 0 || end >= array.length || start > end) {
            return null;
        }
        int smallIndex = partition(array, start, end);
        if (smallIndex > start) {
            quickSort(array, start, smallIndex - 1);
        }
        if (smallIndex < end) {
            quickSort(array, smallIndex + 1, end);
        }
        return array;
    }

    /**
     * 快速排序-分区
     */
    private int partition(int[] array, int start, int end) {
        int pivot = (int) (start + Math.random() * (end - start + 1));
        int smallIndex = start - 1;
        swap(array, pivot, end);
        for (int i = start; i <= end; i++) {
            if (array[i] <= array[end]) {
                smallIndex++;
                if (smallIndex < i) {
                    swap(array, i, smallIndex);
                }
            }
        }
        return smallIndex;
    }

    /**
     * 堆排序
     */
    int[] heapSort(int[] array) {
        int len = array.length;
        if (len < 1) {
            return array;
        }
        // 1.构建一个最大堆
        buildHeap(array, len);
        // 2.循环将堆首位（最大值）与末位交换，然后在重新调整最大堆
        while (len > 0) {
            swap(array, 0, len - 1);
            len--;
            adjustHeap(array, 0, len);
        }
        return array;
    }

    /**
     * 建立最大堆
     */
    private void buildHeap(int[] array, int len) {
        // 从最后一个非叶子节点开始向上构造最大堆
        for (int i = (len - 1) / 2; i >= 0; i--) {
            adjustHeap(array, i, len);
        }
    }

    /**
     * 调整使之成为最大堆
     */
    private void adjustHeap(int[] array, int i, int len) {
        int maxIndex = i;
        // 如果有左子树，且左子树大于父节点，则将最大指针指向左子树
        if (2 * i < len && array[2 * i] > array[maxIndex]) {
            maxIndex = 2 * i;
        }
        // 如果有右子树，且右子树大于父节点，则将最大指针指向右子树
        if (2 * i + 1 < len && array[2 * i + 1] > array[maxIndex]) {
            maxIndex = 2 * i + 1;
        }
        // 如果父节点不是最大值，则将父节点与最大值交换，并且递归调整与父节点交换的位置。
        if (maxIndex != i) {
            swap(array, maxIndex, i);
            adjustHeap(array, maxIndex, len);
        }
    }

    /**
     * 计数排序
     */
    int[] countingSort(int[] array) {
        int len = array.length;
        if (len < 1) {
            return array;
        }
        int min = array[0], max = array[0], diff;
        for (int i : array) {
            if (i > max) {
                max = i;
            }
            if (i < min) {
                min = i;
            }
        }
        diff = 0 - min;
        int[] bucket = new int[max - min + 1];
        Arrays.fill(bucket, 0);
        for (int i : array) {
            bucket[i + diff]++;
        }
        int index = 0, i = 0;
        while (index < len) {
            if (bucket[i] != 0) {
                array[index++] = i - diff;
                bucket[i]--;
            } else {
                i++;
            }
        }
        return array;
    }

    /**
     * 桶排序
     */
    ArrayList<Integer> BucketSort(ArrayList<Integer> array, int bucketSize) {
        if (array == null || array.size() < 2)
            return array;
        int max = array.get(0), min = array.get(0);
        // 找到最大值最小值
        for (Integer value : array) {
            if (value > max)
                max = value;
            if (value < min)
                min = value;
        }
        int bucketCount = (max - min) / bucketSize + 1;
        ArrayList<ArrayList<Integer>> bucketArr = new ArrayList<>(bucketCount);
        ArrayList<Integer> resultArr = new ArrayList<>();
        for (int i = 0; i < bucketCount; i++) {
            bucketArr.add(new ArrayList<Integer>());
        }
        for (Integer integer : array) {
            bucketArr.get((integer - min) / bucketSize).add(integer);
        }
        for (int i = 0; i < bucketCount; i++) {
            if (bucketCount == 1)
                bucketSize--;
            ArrayList<Integer> temp = BucketSort(bucketArr.get(i), bucketSize);
            resultArr.addAll(temp);
        }
        return resultArr;
    }

    /**
     * 基数排序
     */
    int[] radixSort(int[] array) {
        int len = array.length;
        if (len < 2) {
            return array;
        }
        int max = array[0];
        for (int i : array) {
            max = Math.max(i, max);
        }
        int maxDigit = 0;
        while (max != 0) {
            maxDigit++;
            max /= 10;
        }
        int mod = 10, div = 1;
        ArrayList<ArrayList<Integer>> bucketList = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            bucketList.add(new ArrayList<>());
        }
        for (int i = 0; i < maxDigit; i++, mod *= 10, div *= 10) {
            for (int value : array) {
                int num = (value % mod) / div;
                bucketList.get(num).add(value);
            }
            int index = 0;
            for (ArrayList<Integer> integers : bucketList) {
                for (Integer integer : integers) {
                    array[index++] = integer;
                }
                integers.clear();
            }
        }
        return array;
    }

    /**
     * 交换array[i]与array[j]
     */
    private void swap(int[] array, int i, int j) {
        if (i != j) {
            array[i] = array[i] ^ array[j];
            array[j] = array[i] ^ array[j];
            array[i] = array[i] ^ array[j];
        }
    }
}
