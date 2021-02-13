#include <bits/stdc++.h>
using namespace std;

int main(void){
    int j, temp;

    //정렬할 배열
    int array[10] = {4,6,8,1,3,5,7,2,10,9};

    //배열의 크기 만큼 반복
    for(int i=0;i<10;i++) {
        j = i;
        //array[j] > array[j+1] 인 경우, 즉 배열이 정렬이 안되어있을 경우에만 정렬!
        while(j >= 0 && array[j] > array[j+1]) {
            //정렬 될때까지 Swap 진행
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            j--;
        }
    }

    for(int i=0;i<10;i++) {
        cout << array[i] << " ";
    }

    return 0;
}