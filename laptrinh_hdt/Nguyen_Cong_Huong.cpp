#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int* nhap_a(int &n){
	int *a;
	printf("Nhap so phan tu cac he so a:");
	scanf("%d", &n);
	a = (int*)calloc(n, sizeof(int));
	for(int i=0;i<n;i++){
		printf("a%d:", i+1);
		scanf("%d", a);
	}
	return a;
}
int* nhap_b(int &m){
	int *b;
	printf("Nhap so phan tu cac he so b:");
	scanf("%d", &m);
	b = (int*)calloc(m, sizeof(int));
	for(int j=0;j<m;j++){
		printf("b%d:", j+1);
		scanf("%d", b);
	}
	return b;
}
void result(int *a, int *b, float d1, float d2, int m, int n){
	float P, Q;
	float S;
	for(int i=0;i<=n;i++){
		P += *(a+i)*pow(d1,i);
	}
	for(int j=0;j<=m;j++){
		Q += *(b+j)*pow(d2, j);
	}
	if (P>=Q){
		S = sqrt(P-Q) -2023;
	}
	else printf("Bieu thuc ko hop le");
	printf("%.2f", S);
}
int main(){
	int m,n;
	float d1,d2;
	int *a = nhap_a(n);
	int *b = nhap_b(n);
	printf("Nhap d1:");
	scanf("%f", &d1);
	printf("Nhap d2:");
	scanf("%f", &d2);
	result(a,b,d1,d2,m,n);
}
