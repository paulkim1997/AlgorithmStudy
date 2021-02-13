#include <bits/stdc++.h>
using namespace std;

//배열 원소의 갯수
int number = 8;
//정렬하고 담을 추가 배열
int sorted[8];

//병합 함수
void merge(int arr[], int m, int middle, int n) {
    //i 는 첫 번째 원소
    int i = m;
    //j 는 중간 바로 다음번째 원소
    int j = middle + 1;
    //K 는 첫 번째 원소
    int k = m;

    //i랑 j 비교해 작은 순서대로 k, 배열에 삽입
    //i는 중간 까지, j는 마지막 까지 도달할때 까지 반복
    while(i <= middle && j <= n) {
        if(arr[i] <= arr[j]) {
            sorted[k] = arr[i];
            i++;
        } else {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    //i 쪽의 원소를 모두 넣었다면 남은 j값들 넣어주기
    if(i > middle) {
        for(int t=j ; t<=n; t++) {
            sorted[k] = arr[t];
            k++;
        }
    } //j 쪽의 원소를 모두 넣었다면 남은 i 값들 넣어주기
    else {
        for(int t=i; t<=middle ;t++) {
            sorted[k] = arr[t];
            k++;
        }
    }
    //정렬된 배열을 삽입
    for(int t=m;t<=n;t++)
        arr[t] = sorted[t];
}

//병합 정렬 함수
void mergeSort(int arr[], int m, int n){
    //원소가 1개 보다 많을 때만!
    if(m<n) {
        int middle = (m+n)/2;
        //배열을 절반으로 나누고
        mergeSort(arr, m, middle);
        mergeSort(arr, middle+1, n);
        //나중에 합친다
        merge(arr , m , middle, n);
    }
}

int main(void){
    int array[number] = {4,6,1,8,3,5,7,2};
    mergeSort(array, 0, number-1);

    for(int i=0;i<number;i++)
        cout << array[i] <<" ";
}