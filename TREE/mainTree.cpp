#include <stdio.h>
#include "TreeHeader.h"

int main() {
    Isi_Tree P;
    int n, i;

    printf("Masukkan jumlah node dalam Tree (max 20): ");
    scanf("%d", &n);

    Create_tree(P, n);

    printf("Traversal Preorder: ");
    PreOrder(P);
    printf("\n");

    printf("Traversal Inorder: ");
    InOrder(P);
    printf("\n");

    printf("Traversal Postorder: ");
    PostOrder(P);
    printf("\n");

    printf("Traversal Levelorder: ");
    Level_order(P, n);
    printf("\n");

//    printf("Print Tree: \n");
//    PrintTree(P);

    printf("Jumlah elemen dalam pohon: %d\n", nbElmt(P));
    printf("Jumlah daun dalam pohon: %d\n", nbDaun(P));

    infotype x;
    printf("Masukkan info yang ingin dicari: ");
    scanf(" %c", &x);

    if (Search(P, x))
        printf("Info ditemukan\n");
    else
        printf("Info tidak ditemukan\n");

    printf("Masukkan info untuk mencari level: ");
    scanf(" %c", &x);

    int level = Level(P, x);

    if (level == -1)
        printf("Node tidak ditemukan\n");
    else
        printf("Level node %c adalah %d\n", x, level);

    printf("Depth pohon adalah: %d\n", Depth(P));

    return 0;
}

