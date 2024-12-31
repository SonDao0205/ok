#include "../include/secondaryFeatures.h"

void goodBye(){
    printf("========  Thank You! =========\n");
    printf("======== See You Soon ========\n");
}

void backMenu() {
    while (1) {
        printf("Quay lai menu (b)? Thoat chuong trinh (0)? : ");
        char x;
        fflush(stdin);
        scanf("%c", &x);
        x = toupper(x);
        switch (x) {
            case 'B':
                return;
            case '0':
                goodBye();
                exit(0);
            default:
                printf("Lua chon khong hop le!\n");
        }
    }
}
