#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    // �ӽ� ������ ���� �޸� �Ҵ�
    int* temp = (int*)malloc((r - l + 1) * sizeof(int));
    // �޸� �Ҵ翡 ���� ���� ���
    if (temp == NULL) {
        printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
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

    //���� �޸� �Ҵ� ����
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
    // ���� ������ ����
    FILE* file_ptr;
    // ���� ����
    file_ptr = fopen("input.txt", "r");

    // ���� ���⿡ �������� ��� ���� �޽��� ��� �� ����
    if (file_ptr == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return -1;
    }

    // ���� ���� ���� ���� ī��Ʈ
    int num_count = 0;
    int num;
    while (fscanf(file_ptr, "%d", &num) == 1) {
        num_count++;
    }

    // ���� �����͸� �ٽ� ������ ó������ �̵�
    fseek(file_ptr, 0, SEEK_SET);

    // ������ ������ �迭 ���� �Ҵ�
    int* array = (int*)malloc(num_count * sizeof(int));

    if (array == NULL) {
        printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
        return -1;
    }

    // ���Ͽ��� ������ �о� �迭�� ����
    int i = 0;
    while (fscanf(file_ptr, "%d", &array[i]) == 1) {
        i++;
    }

    // ���� �ݱ�
    fclose(file_ptr);

    // �迭�� ����� ���� ���
    printf("�ؽ�Ʈ ���Ͽ��� ���� ����:\n");
    for (int j = 0; j < num_count; j++) {
        printf("%d ", array[j]);
    }

    mergeSort(array, 0, num_count - 1);

    printf("\n���� ��:\n");
    for (int i = 0; i < num_count; i++) {
        printf("%d ", array[i]);
    }
    // �Ҵ�� �޸� ����
    free(array);

    printf("\n������ �Ϸ�Ǿ����ϴ�!\n");
    return 0;
}