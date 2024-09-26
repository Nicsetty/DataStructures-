#include <stdio.h>
void move(int n, int source, int destination, int temp) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", source, destination);
        return;
    }
    move(n - 1, source, temp, destination);
    printf("Move disk %d from rod %d to rod %d\n", n, source, destination);
    move(n - 1, temp, destination, source);
}

int main() {
    int num_disks; 
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    move(num_disks, 1, 3, 2);
    return 0;
}
