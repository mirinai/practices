#include <stdio.h>
#include <stdlib.h>//메모리 동적할당 쓰려고 부름

//지역변수 (Local Variables)
//1. 함수 안에서 정의되고, 오직 그 함수 안에서만 접근할수 있는 변수
//2. 함수 호출할 때 생기고, 함수 실행이 끝나면 없어짐
//3. 함수의 실행이 끝난 뒤에도 값을 유지해야 하는 경우에는 지역변수를 쓸 수 없음

//전역변수( Global Variables)
//1. 함수 바깥에서 정의되며, 프로그램의 어느 곳에서나 접근할 수 있는 변수
//2. 프로그램이 실행될 때 할당되 뒤 프로그램이 끝날때까지 유지됨
//3. 크기가 큰 데이터 다룰 때 메모리 낭비가 일어날 수 있음

//메모리 동적할당
//1. 실행시간에 메모리 크기 조절가능 : 프로그램 실행하는 가운데에서 필요한 메모리 크기를 할당하고 정할수 있음.
//데이터의 크기가 미리 결정되지 않은 경우에 잘 대처할 수 있음
//2. 메모리 사용 효율성 : 필요할 때 메모리를 할당하고, 더는 필요 없을 때 해제를 해줌으로써,
//메모리를 효율적으로 관리할 수 있고, 낭비도 줄일수있음
//3. 데이터 구조 동적확장 : 연결리스트, 트리 등 여러 동적 데이터 구조를 만들 수 있음

//메모리 동적할당?
// 유저가 바라는 크기만큼 공간을 할당받아서 쓸 수 있는 것
// 프로그램이 실행되는 동앙 쓸 메모리 공간을 할당하는 것

// 쓰는 경우
//1. 프로그램 실행하는 동앚ㄴ 메모리 크기를 결정해야 할 때
//2. 크기가 크거나 실행 동안 바뀔 수 있는 배열이나 데이터 구조를 다룰때
//3. 프로그램의 다른 부분에서도 메모리에 접근해야할 때 (함수가 끝난 뒤에도 메모리를 유지해야 하는 케이스)

int globalVar = 100;//전역변수


int* createArray() {
	int arr[10];//지역변수로 배열 선언
	for (int i = 0; i < 10; i++) {
		arr[i] = i * 10;
	}
	return arr;//함수가 끝나면 arr의 메모리가 해제됨
}

int* createArray2() {
	int* arr = (int*)malloc(10 * sizeof(int));//동적 메모리 할당
	for (int i = 0; i < 10; i++) {
		arr[i] = i * 10;
	}

	return arr;
}


int main_2(void) {

	int num1 = 5;//지역변수

	printf("전역변수 처음값 : %d\n", globalVar);//100
	globalVar = 200;
	printf("전역변수 바꾼 값 : %d\n", globalVar);//200

	printf("\n");
	printf("--------------------\n");
	printf("\n");

	//malloc(할당될 메모리 크기)

	int size1 = 3;
	//malloc -> void* 형태의 포인터를 리턴 -> 어떤 타입의 포인터로도 바뀔 수 있는 범용 포인터
	int* numPtr1 = (int*)malloc(size1 * sizeof(int));//바이트 단위로 크기를 넣기 -> 시작주소 반환 -> (int*)로 타입 바꿈
	//3*4byte -> malloc
	//malloc(size1 * sizeof(int));

	free(numPtr1);//더는 필요없으면 해제, 메모리 아낄 수 있음

	printf("\n");
	printf("--------------------\n");
	int* arr1 = createArray();
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr1[i]);//0 0 1852832096 76 1852832392 76 -858993460 11 -858993460 -858993460 메모리 해제되면서 이상한 값이 들어감
	}
	printf("\n");
	int* arr2 = createArray2();
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr2[i]);//0 10 20 30 40 50 60 70 80 90
	}


	free(arr2);//메모리 해제





	return 0;
}