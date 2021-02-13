#include <bits/stdc++.h>
using namespace std;

//배열 원소 갯수
int number = 10;
//정렬할 배열
int arr[] = {4,6,8,1,3,5,7,2,10,9};

void quickSort(int arr[], int start, int end) {
    //원소가 1개인 경우 정렬 수행 X
    if(start>=end)
        return;

    //첫 번째 수를 피봇 값으로
    int pivot = start;
    //피봇 값보다 큰값 오른쪽에서 부터 탐색 하기 위한 index i
    int i = start + 1;
    //피봇 값보다 큰값 왼쪽에서 부터 탐색 하기 위한 index j
    int j = end;
    //나중에 Swap 할때 사용할 temp
    int temp;
    
    //엇갈릴 때 까지 반복
    while(i <= j) {
        //피봇 값 보다 큰값 찾을때까지 i++
        while(i <= end && arr[i] <= arr[pivot])
            i++;
        //피봇 값 보다 작은값 찾을때까지 i++
        while(j > start && arr[j] >= arr[pivot])
            j--;

        //작은 값의 index가 큰 값의 index보다 커서 엇갈린 상태면
        //피봇 값과 작은 값 위치 변경
        if(i > j) {
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        } //엇갈린 상태 아니면 i 와 j 교체
        else {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //재귀적으로 분할 정복 실행
    quickSort(arr, start, j-1);
    quickSort(arr, j+1, end);
}

int main(void){
    
    quickSort(arr, 0, number-1);

    for(int i=0;i<10;i++)
        cout << arr[i] << " ";
    
    return 0;
}