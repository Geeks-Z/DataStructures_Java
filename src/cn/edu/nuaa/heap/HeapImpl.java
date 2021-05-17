package cn.edu.nuaa.heap;

import java.util.Arrays;

/**
 * @ClassName HeapImpl
 * @Description 代码参考《韩顺平数据结构与算法-Java版》
 * @Author Geeks_Z
 * @Date 2021/3/19 16:40
 * @Version 1.0
 **/
public class HeapImpl {

    /**
     *
     * @param index 当前需要调整的结点
     * @param arr 存储完全二叉树的数组
     * @param right 右边界
     */
    public static void adjustHeap(int index, int []arr, int right){
        //当前需要调整的点
        int temp = arr[index];

        for (int i = index*2+1; i < right; i = index * 2 +1) {
            int j = i;
            if(i+1 < right && arr[i] < arr[i+1]){
                j = i+1;
            }
            if(temp < arr[j]){
                //调整父结点的值
                arr[index] = arr[j];
                index = j;
            }else{
                break;
            }
        }
        arr[index] = temp;
    }

    public static void main(String[] args) {
        int arr[] = {4, 6, 8, 5, 9};
        adjustHeap(1,arr,5);
        adjustHeap(0,arr,5);

        System.out.println(Arrays.toString(arr));
    }
}
