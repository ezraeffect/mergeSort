#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    // 임시 변수의 동적 메모리 할당
    int* temp = (int*)malloc((r - l + 1) * sizeof(int));
    // 메모리 할당에 실패 했을 경우
    if (temp == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return;
    }

    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= m) {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    k--;
    while (k >= 0) {
        arr[l + k] = temp[k];
        k--;
    }

    //동적 메모리 할당 해제
    free(temp);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    // 파일 포인터 선언
    FILE* file_ptr;
    // 파일 열기
    file_ptr = fopen("input.txt", "r");

    // 파일 열기에 실패했을 경우 오류 메시지 출력 후 종료
    if (file_ptr == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return -1;
    }

    // 파일 내의 정수 개수 카운트
    int num_count = 0;
    int num;
    while (fscanf(file_ptr, "%d", &num) == 1) {
        num_count++;
    }

    // 파일 포인터를 다시 파일의 처음으로 이동
    fseek(file_ptr, 0, SEEK_SET);

    // 정수를 저장할 배열 동적 할당
    int* array = (int*)malloc(num_count * sizeof(int));

    if (array == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return -1;
    }

    // 파일에서 정수를 읽어 배열에 저장
    int i = 0;
    while (fscanf(file_ptr, "%d", &array[i]) == 1) {
        i++;
    }

    // 파일 닫기
    fclose(file_ptr);

    // 배열에 저장된 정수 출력
    printf("텍스트 파일에서 읽은 정수:\n");
    for (int j = 0; j < num_count; j++) {
        printf("%d ", array[j]);
    }

    mergeSort(array, 0, num_count - 1);

    printf("\n정렬 후:\n");
    for (int i = 0; i < num_count; i++) {
        printf("%d ", array[i]);
    }
    // 할당된 메모리 해제
    free(array);

    printf("\n정렬이 완료되었습니다!\n");
    return 0;
}