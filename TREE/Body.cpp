// Muhammad Daffa Tridya Atha 	(231511082)
// Yulina Anggraeni 			(231511092)
// D3-Teknik Informatika / 1C-JTK

#include "TreeHeader.h"
#include <stdbool.h>
#include <stdio.h>

/***************************/
/* Implementasi Fungsi */
/***************************/

void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    for (i = 1; i <= Jml_Node; i++) {
        X[i].info = '0' + i;
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

void PreOrder(Isi_Tree P) {
    int pCur = 1;
    bool backtrack = false; // Untuk menandakan apakah traversal harus mundur ke parent
    printf("%c ", P[pCur].info); // Cetak nilai simpul saat ini (root)

    while (pCur != 0) {
        if (!backtrack && P[pCur].ps_fs != 0) { // Jika masih ada anak dan belum mundur dari traversal
            pCur = P[pCur].ps_fs;
            printf("%c ", P[pCur].info); // Cetak nilai anak yang sedang ditinjau
        } else {
            if (P[pCur].ps_nb != 0) { // Jika masih ada saudara
                pCur = P[pCur].ps_nb;
                printf("%c ", P[pCur].info); // Cetak nilai saudara yang sedang ditinjau
                backtrack = false; // Reset backtrack ke false karena traversal tidak mundur
            } else { // Jika tidak ada saudara, mundur ke parent
                pCur = P[pCur].ps_pr;
                backtrack = true; // Set backtrack ke true karena traversal harus mundur
            }
        }
    }
}

void PostOrder(Isi_Tree P) {
    int pCur = 1; // index simpul yang sedang di iterasi pada traversal
    bool resmi = true; // sebagai penanda apakah simpul sedang diiterasi secara resmi atau tidak
    while (pCur != 0) {
        if (P[pCur].ps_fs != 0 && resmi) // dicek apakah memiliki anak pertama dan sedang di traversal secara resmi
        {
            pCur = P[pCur].ps_fs;
        } else // jika tidak memiliki anak dan tidak traversal secara resmi
        {
            printf("%c ", P[pCur].info);
            if (P[pCur].ps_nb != 0) // apakah simpul saat ini memiliki saudara
            {

                pCur = P[pCur].ps_nb;
                resmi = true;
            } else {

                pCur = P[pCur].ps_pr;
                resmi = false;
            }
        }
    }
}

void InOrder(Isi_Tree P) {
    int pcur = 1; // index simpul yang sedang diiterasi pada traversal
    bool resmi = true; // sebagai penanda simpul sedang diiterasi atau tidak
    while (pcur != 0) {
        if (P[pcur].ps_fs != 0 && resmi) // pengecekan apakah memiliki anak pertama dan merupakan simpul resmi
        {
            pcur = P[pcur].ps_fs;
        } else {
            if (resmi) // dilakukan pengecekan apakah simpul resmi atau bukan
            {
                printf("%c ", P[pcur].info);
            }
            if (pcur == P[P[pcur].ps_pr].ps_fs) // pengecekan apakah merupakan anak pertama
            {
                printf("%c ", P[P[pcur].ps_pr].info);
            }
            if (P[pcur].ps_nb != 0) // pengecekan apakah memiliki saudara
            {
                pcur = P[pcur].ps_nb;
                resmi = true;
            } else // jika bukan maka menjadi parent dan resmi diubah menjadi false
            {
                pcur = P[pcur].ps_pr;
                resmi = false;
            }
        }
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    // Queue to store nodes for level-order traversal
    int queue[jml_maks + 1];
    int front = -1, rear = -1;

    // Insert the root node into the queue
    rear++;
    queue[rear] = 1;

    // Level-order traversal using a queue
    while (front != rear) {
        // Remove the front node from the queue
        front++;
        int currentNode = queue[front];

        // Process the current node
        printf("%c ", X[currentNode].info);

        // Enqueue the children of the current node
        int child = X[currentNode].ps_fs;
        while (child != 0) {
            rear++;
            queue[rear] = child;
            child = X[child].ps_nb;
        }
    }
}


void PrintTree(Isi_Tree P) {
    int arah, a, level, pCur = 1;
    arah = 0;
    level = 0;
    printf("%c\n", P[pCur].info); // root di print
    do {
        if (P[pCur].ps_fs != 0 && arah == 0) {
            level++;
            pCur = P[pCur].ps_fs;
            for (a = 0; a < level; a++) {
                printf("-");
            }
            printf("%c\n", P[pCur].info);
        } else {
            arah = 0;
            if (P[pCur].ps_nb != 0) {
                pCur = P[pCur].ps_nb;
                for (a = 0; a < level; a++) {
                    printf("-");
                }
                printf("%c\n", P[pCur].info);
            } else {
                pCur = P[pCur].ps_pr;
                level--;
                arah = 1;
            }
        }
    } while (P[pCur].ps_pr != 0);
}

boolean Search(Isi_Tree P, infotype X) {
    int pCur = 1;
    bool resmi = true, ketemu = false;
    while (pCur != 0) {
        if (P[pCur].ps_fs != 0 && resmi) {
            pCur = P[pCur].ps_fs;
        } else {
            if (P[pCur].info == X) {
                ketemu = true;
                break;
            }
            if (P[pCur].ps_nb != 0) {
                pCur = P[pCur].ps_nb;
                resmi = true;
            } else {
                pCur = P[pCur].ps_pr;
                resmi = false;
            }
        }
    }
    return ketemu;
}

void DeleteNode(Isi_Tree P, infotype X) {
    int pCur = 1;
    bool resmi = true, ketemu = false;
    int parent = 0;
    int prev_sibling = 0;

    // Traverse the tree to find the node to be deleted
    while (pCur != 0) {
        if (P[pCur].ps_fs != 0 && resmi) {
            parent = pCur;
            pCur = P[pCur].ps_fs;
        } else {
            if (P[pCur].info == X) {
                ketemu = true;
                break;
            }
            if (P[pCur].ps_nb != 0) {
                prev_sibling = pCur;
                pCur = P[pCur].ps_nb;
                resmi = true;
            } else {
                parent = P[pCur].ps_pr;
                pCur = P[pCur].ps_pr;
                resmi = false;
            }
        }
    }

    // If the node to be deleted is found
    if (ketemu) {
        // If the node to be deleted is the first child of its parent
        if (parent != 0 && P[parent].ps_fs == pCur) {
            P[parent].ps_fs = P[pCur].ps_nb;
        } else if (prev_sibling != 0) { // If the node to be deleted has a previous sibling
            P[prev_sibling].ps_nb = P[pCur].ps_nb;
        } else { // If the node to be deleted is the only child of its parent or has no sibling
            P[P[pCur].ps_pr].ps_fs = P[pCur].ps_nb;
        }
        // Set the deleted node's pointers to nil
        P[pCur].ps_fs = 0;
        P[pCur].ps_nb = 0;
        P[pCur].ps_pr = 0;
    } else {
        printf("Node with value %c not found.\n", X);
    }
}


