#include <iostream>
using namespace std;

int main(void) {
    //정렬할 배열
    int array[10] = { 4,6,8,1,3,5,7,2,10,9 };
    //최솟값 구할때 비교할 숫자
    int min;
    //최솟값 index
    int index = 0;
    //swap할때 사용할 변수
    int temp;

    //정렬할 배열 크기만큼 반복
    for (int i = 0; i < 10; i++) {
        //최솟값 구할때 숫자 여유롭게 크게 부여
        min = 9999;
        //정렬된 부분 제외하고 나머지 부분에서 최솟값 탐색
        //j는 i부터 시작하는 것 참고
        for (int j = i; j < 10; j++) {
            //최솟값, 최솟값의 index 저장
            if (min > array[j]) {
                min = array[j];
                index = j;
            }
        }
        //최솟값과 제일 앞의 값 Swap
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;

    }

    //정렬된 배열 출력
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }

    return 0;
}