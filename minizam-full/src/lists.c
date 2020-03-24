//
// Created by human on 24/03/2020.
//



#include "lists.h"

ml_list ml_empty_list(){
    ml_list f = malloc(sizeof(struct mll));
    f->val=NULL;
    f->next=NULL;
    return f;
}

ml_list pushHead(mlvalue * i,ml_list fl) {
    //on suppose fl non NULL;
    if(fl->val==NULL){
        fl->val=i;
        return fl;
    }else{
        ml_list nfl=ml_empty_list();
        nfl->val=i;
        nfl->next=fl;
    }
}


void show (ml_list fl){
    ml_list tmp=fl;
    while(tmp&&tmp->val) {
        printf("%p - ",tmp->val);
        tmp=tmp->next;
    }
}

void release(ml_list fl){
    if(!fl)return;
    if(fl->next==NULL){
        return;
    }else{
        release(fl->next);
    }
    free(fl->next);
}

