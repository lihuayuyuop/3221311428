#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
typedef struct s{
	string tele;
	int count;
	string name;
}S; 
void InserH3(S a[],int *n,int m,int p,string b[],string c[]){
	int i,j,num=1,f=1,l=1;
	j=(((int)b[*n][9]-48)*10+(int)b[*n][10])%p;
	if(a[j].tele[0]=='A'){
		a[j].tele = b[*n];
		a[j].name = c[*n];
	}
	else{
		while(a[j].tele[0]!='A'){
			num++;
			j=(j+f*(l*l))%m;
			f=-f;
			if(f>0){
				l++;
			}
		}
	}
	a[j].tele = b[*n];
	a[j].name = c[*n];
	a[j].count=num;
	(*n)++;
}
void create(S a[],int *n,int m,int p,string b[],int t,string c[]){
	int i;
	for(i=0;i<m;i++){
		a[i].tele[0]='A';
		a[i].count=0;
	}
	for(i=0;i<t;i++){
		InserH3(a,n,m,p,b,c);
	}
}
void ASL(S a[],int n,int m){
	int i,j;
	int succ=0,unsucc=0,s;
	for(i=0;i<m;i++){
		if(a[i].tele[0]!='A'){
			cout<<a[i].count; 
			succ += a[i].count;
		}
	}
	printf("成功情况下(%d)=%g\n",n,succ*1.0/n);
	printf("冲突率%.4f\n",(succ-n)*1.0/succ);
}
int main(){
	int i,j,p,m,n=0,t;
	string b[100],c[100];
	cin>>p;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>b[i];
		cin>>c[i];
	}
	m=p+1;
	S a[m];
	create(a,&n,m,p+1,b,t,c);
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

