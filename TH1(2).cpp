#include<stdio.h>
#include<conio.h>

void nhapMang(int arr[], int n) {
    printf("Nhap cac phan tu cua mang:\n");
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
}


void xuatMang(int arr[], int n) {
    printf("Cac phan tu cua mang la:\n");
    for(int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int timKiemTuyenTinh(int arr[], int n, int x) {
    for(int i = 0; i < n; ++i) {
        if(arr[i] == x) {
            return 1;
        }
    }
    return 0;
}


int timKiemNhiPhan(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x) {
            return 1;
        } else if(arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}


void timXTrongMang(int arr[], int n, int x) {
    printf("Tim x trong mang:\n");
    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] == x) {
            printf("Tim thay tai vi tri %d\n", i);
            count++;
        }
    }
    if(count == 0) {
        printf("Khong tim thay %d trong mang.\n", x);
    }
}


void demSoNguyenTo(int arr[], int n) {
    printf("Cac so nguyen to trong mang va vi tri:\n");
    for(int i = 0; i < n; ++i) {
        if(arr[i] > 1) {
            int isPrime = 1;
            for(int j = 2; j * j <= arr[i]; ++j) {
                if(arr[i] % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime) {
                printf("%d tai vi tri %d\n", arr[i], i);
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    nhapMang(arr, n);
    xuatMang(arr, n);
    int x;
    printf("Nhap gia tri x can tim: ");
    scanf("%d", &x);
    if(timKiemTuyenTinh(arr, n, x)) {
        printf("Tim thay %d trong mang.\n", x);
    } else {
        printf("Khong tim thay %d trong mang.\n", x);
    }
    timXTrongMang(arr, n, x);
    demSoNguyenTo(arr, n);
    return 0;
}
