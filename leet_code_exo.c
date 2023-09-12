#include <stdlib.h>
// #include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct cellule *list;
typedef struct cellule{
    int info;
    list svt;
}cellule;

typedef struct cordo{
    int i;
    int j;
}cordo;

typedef struct cellule2 *pile;
typedef struct cellule2{
    cordo info;
    pile svt;
}cellule2;

void allouer (list *nouv){
    *nouv=(list)malloc(sizeof(cellule));
}
void allouer_cordo (pile *nouv){
    *nouv=(pile)malloc(sizeof(cellule2));
}
void push(pile *p ,cordo src){
    pile nouv;
    allouer_cordo(&nouv);
    nouv->info=src;
    nouv->svt=*p;
    *p=nouv;
}
void pop(pile *p,cordo *dest){
    if (*p ==NULL)
    {
        printf("\nla pile est vide :");
    }
    else{
        *dest=(*p)->info;
        list tmp=*p;
        *p=(*p)->svt;
        free(tmp);
    }
}
bool pile_vide(pile p){
    if(p==NULL){
        return(true);
    }
    else{return(false);}
}

bool kont_hna(cordo tab[100] ,cordo val,int taille){
    for(int i=0;i<taille;i++){
        if(tab[i].i==val.i&&tab[i].j==val.j){return(true);}
    }
    return(false);
}

int main(){
    int day=-1,n,i,index;
    pile p=NULL;
    bool existe=true;
    printf("enter the n : ");
    scanf("%d",&n);
    cordo cur ,tmp;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j]=0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    cordo x,poubala;
    cordo prd[100];
    while(existe==true){
        for(int l=0;l<100;l++){
            prd[l].i=0;
            prd[l].j=-1;
        }
        while(pile_vide(p)==false){
            pop(&p,&poubala);
        }
        index=0;
        printf("\nenter the number of line : ");
        cordo new;
        scanf("%d",&new.i);
        printf("\nenter the number of colomne : ");
        scanf("%d",&new.j);
        mat[new.i][new.j]=1;
        day++;
        int i=0;
        cur.i=0;
        while(i<n && cur.i<n-1){
            x.i=0;
            x.j=i;
            push(&p,x);
            printf("\nx : %d,%d",x.i,x.j);
            bool wslna=false;
            while(pile_vide(p)==false&&wslna==false){
                pop(&p,&cur);
                if( kont_hna(prd,cur,index)==false && (mat[cur.i][cur.j]==0)){
                    if(cur.i<n-1){
                        tmp=cur;
                        tmp.i++;
                        if(kont_hna(prd,tmp,index)==false && mat[tmp.i][tmp.j]==0){
                            push(&p,tmp);
                            // printf("\ndrtou %d",mat[tmp.i][tmp.j]);
                        }
                    }


                    if(cur.j<n-1 ){
                        tmp=cur;
                        tmp.j++;
                        if(kont_hna(prd,tmp,index)==false && mat[tmp.i][tmp.j]==0){
                            push(&p,tmp);
                            // printf("\ndrtou %d",mat[tmp.i][tmp.j]);
                        }
                    }
                    if(cur.j>0 &&(mat[cur.i][cur.j]!=1)){
                        tmp=cur;
                        tmp.j--;
                        if(kont_hna(prd,tmp,index)==false && mat[tmp.i][tmp.j]==0){
                            push(&p,tmp);
                        }
                    }
                }
                index++;
                prd[index].i=cur.i;
                prd[index].j=cur.j;
                // printf("\nprd=%d",index);
                printf("\n%d , %d",cur.i,cur.j);
                if(cur.i==n-1 && mat[cur.i][cur.j]==0){wslna=true;}
                // if(mat[cur.i][cur.j]!=0){break;}
            }
            i++;
        }
        if(cur.i<n-1){existe=false;}
            printf("\n");
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    printf("%d\t",mat[i][j]);
                }
            printf("\n");
            }
    }
    printf("\nthe number of days is : %d ",day);
    printf("the end");
    return 0;
}
