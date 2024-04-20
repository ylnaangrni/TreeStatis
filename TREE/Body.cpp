// Muhammad Daffa Tridya Atha 	(231511082)
// Yulina Anggraeni 			(231511092)
// D3-Teknik Informatika / 1C-JTK

#include <stdio.h>
#include <stdlib.h>
#include "TreeHeader.h"

void Create_tree(Isi_Tree X, int Jml_Node){
    int i;
    for (i=1; i<=Jml_Node; i++){
        printf("Masukkan node ke-%d : ", i);
        scanf(" %c", &X[i].info);
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
        if (i > 1){
            int j = (i-1) / 2;
            if ((i-1) % 2 == 0){ /* sebagai anak kiri */
                X[j].ps_fs = i;
            }else{				 /* sebagai anak kanan */
                X[j].ps_nb = i;
            	X[i].ps_pr = j;
        	}
        }
    }
}

boolean IsEmpty (Isi_Tree P)
{
    return (P[1].info == 0);
}

void PreOrder (Isi_Tree P)
{
    if (!IsEmpty(P))
    {
        printf("%c ", P[1].info);
        if (P[1].ps_fs != nil)
            PreOrder(&P[P[1].ps_fs]);
        if (P[1].ps_nb != nil)
            PreOrder(&P[P[1].ps_nb]);
    }
}

void InOrder (Isi_Tree P)
{
    if (!IsEmpty(P))
    {
        if (P[1].ps_fs != nil)
            InOrder(&P[P[1].ps_fs]);
        printf("%c ", P[1].info);
        if (P[1].ps_nb != nil)
            InOrder(&P[P[1].ps_nb]);
    }
}

void PostOrder (Isi_Tree P)
{
    if (!IsEmpty(P))
    {
        if (P[1].ps_fs != nil)
            PostOrder(&P[P[1].ps_fs]);
        if (P[1].ps_nb != nil)
            PostOrder(&P[P[1].ps_nb]);
        printf("%c ", P[1].info);
    }
}

void Level_order(Isi_Tree X, int Maks_node)
{
    int i;
    for (i=1; i<=Maks_node; i++)
    {
        if (X[i].info != '\0')
            printf("%c ", X[i].info);
    }
}

boolean Search (Isi_Tree P, infotype X){
	int i = 1;
	boolean found = false;
	while (!found && i <= jml_maks){
    	if (P[i].info == X){
        	found = true;
    	}else{
        	i++;
		}
	}
	return found;
}

int nbElmt (Isi_Tree P){
	int i = 1;
	int count = 0;
	while (i <= jml_maks){
    	if (P[i].info != 0)
        	count++;
    		i++;
		}
	return count;
}

int nbDaun (Isi_Tree P){
	int i = 1;
	int count = 0;
	while (i <= jml_maks){
   		if (P[i].info != 0 && P[i].ps_fs == 0)
    		count++;
    		i++;
		}
	return count;
}

int Level (Isi_Tree P, infotype X){
	int i = 1;
	int level = -1;
	boolean found = false;
	while (!found && i <= jml_maks){
    	if (P[i].info == X){
	        found = true;
	        level = 0;
	        while (i > 1)
	        {
	            i = P[i].ps_pr;
	            level++;
        	}
    	}else{
    		i++;
		}
	}
return level;
}

int Depth (Isi_Tree P){
	if (P[1].info == 0){ // tree kosong
		return 0;
	}else{
		int depth_fs = Depth(P+P[1].ps_fs);
		int depth_nb = Depth(P+P[1].ps_nb);
		return 1 + Max(depth_fs, depth_nb);
	}
}

int Max (infotype Data1, infotype Data2){
	if (Data1 >= Data2){
		return Data1;
	}else{
		return Data2;
	}
}
