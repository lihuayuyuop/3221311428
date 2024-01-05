#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std; 
typedef struct s{
	string tele;
	string name;
	struct s *next;
}S;
typedef struct h{
	S* f;
}H;
void InsertH2(H a[],int *n,int m,string b[],string c[]){
	int j;
	j = (((int)b[*n][9] - 48) * 10 + (int)b[*n][10]) % m;
	S* p = new S;
	p->tele = b[*n];
	p->name = c[*n];
	p->next = NULL;
	if (a[j].f == NULL) {
	    a[j].f = p;
	} else {
	    p->next = a[j].f;
	    a[j].f = p;
	}
	(*n)++;
}
void create(H a[],int *n,int m,string b[],string c[],int t){
	int i;
	for(i=0;i<m;i++){
		a[i].f=NULL;
	}
	for(i=0;i<t;i++){
		InsertH2(a,n,m,b,c);
	}
}
void ASL(H a[],int n,int m){
	int s1=0,s;
	S *p;
	for(int i=0;i<m;i++){
		s=1;
		p=a[i].f;
		while(p!=NULL){
			p=p->next;
			s++;
			s1=s1+s;
		}
	}
	printf("成功情况下(%d)=%g\n",n,s1*1.0/n);
	printf("冲突率%.4f\n",(s1-n)*1.0/s1);
}
int main(){
	int i,j,q,m,n=0,t;
	string b[100],c[100];
	cin>>q;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>b[i];
		cin>>c[i];
	}
	m=q+1;
	H a[m];
	create(a,&n,m,b,c,t);
	ASL(a,n, m);
	/*
12
10
12345678902 John
98765432103 Alice
23456789014 Bob
34567890105 David
45678901206 Emma
18815946207 yu
14759968408 ll
15485465366 kk
12547854655 gg
55412522182 hh
	*/
	
}
