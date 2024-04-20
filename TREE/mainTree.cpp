#include <stdio.h>
#include "TreeHeader.h"

int main() {
    Isi_Tree X;
    int jml;

    printf("Masukkan jumlah node dalam pohon non-biner: ");
    scanf("%d", &jml);

    if (jml > jml_maks) {
        printf("Jumlah node melebihi kapasitas maksimum.\n");
        return 1;
    }

    printf("Masukkan nilai dan posisi parent, first son, serta next brother untuk setiap node:\n");

    for (int i = 1; i <= jml; i++) {
        printf("Node ke-%d: ", i);
        scanf(" %c %d %d %d", &X[i].info, &X[i].ps_pr, &X[i].ps_fs, &X[i].ps_nb);
    }

    printf("\nPreOrder : ");
    PreOrder(X);
    printf("\nInOrder : ");
    InOrder(X);
    printf("\nPostOrder : ");
    PostOrder(X);
    printf("\nLevel Order : ");
    Level_order(X, jml);

    char node_to_search;
    printf("\n\nMasukkan nilai node yang ingin dicari: ");
    scanf(" %c", &node_to_search);
    if (Search(X, node_to_search)) {
        printf("Node dengan nilai %c ditemukan dalam pohon.\n", node_to_search);
    } else {
        printf("Node dengan nilai %c tidak ditemukan dalam pohon.\n", node_to_search);
    }

    char node_to_delete;
    printf("\nMasukkan nilai node yang ingin dihapus: ");
    scanf(" %c", &node_to_delete);
    DeleteNode(X, node_to_delete);
    printf("Setelah menghapus node dengan nilai %c:\n", node_to_delete);
    printf("\nPreOrder : ");
    PreOrder(X);
    printf("\nInOrder : ");
    InOrder(X);
    printf("\nPostOrder : ");
    PostOrder(X);
    printf("\nLevel Order : ");
    Level_order(X, jml);

    printf("\nTree:\n");
    PrintTree(X);

    return 0;
}
