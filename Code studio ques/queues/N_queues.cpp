// https://www.codingninjas.com/studio/problems/n-queue-using-array_1170053?leftPanelTab=0
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class NQueue{
public:
    int *front;
    int *rear;
    int *arr;
    int *next;
    int N;
    int S;
    int freespot;
    NQueue(int n, int s){
        N=n;
        S=s;
        front=new int[N];
        rear=new int[N];
        arr=new int[S];
        next=new int[S];
        for(int i=0;i<N;i++)
        {front[i]=-1;
         rear[i]=-1;}
         for(int i=0;i<S;i++)
         {next[i]=i+1;}
         next[S-1]=-1;
         freespot=0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freespot==-1)
        {return false;}
        int index=freespot;
        freespot=next[index];
        if(front[m-1]==-1)
        {front[m-1]=index;}
        else
        {next[rear[m-1]]=index;}
        rear[m-1]=index;
        next[index]=-1;
        arr[index]=x;
        return true;

    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
       if(front[m-1]==-1)
       {return -1;}
       int index=front[m-1];
       front[m-1]=next[index];
       next[index]=freespot;
       freespot=index;
       return arr[index];

    }
};