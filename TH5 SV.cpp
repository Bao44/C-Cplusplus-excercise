#include<iostream>
#include<math.h>
#include<conio.h>
#include<string.h>
#define MAX 100
#define S(type,x,y) do{type temp=x;x=y;y=temp;}while(0)
using namespace std;
struct sv{
	char hoten[50];
	char masv[50];
	float tk,gk,ck,th,dtb;
};
void input(sv a[],int &n)
{
	cout << "Nhap so luong sv: "; cin >> n;
	for(int i=0;i<n;i++)
	{
		cout << "Nhap ten sv:  ";fflush(stdin);gets(a[i].hoten);
		cout << "Nhap ma sv:  ";fflush(stdin);gets(a[i].masv);
		
		/////
		do{
			cout << "Nhap diem thuong ki:  ";cin >> a[i].tk;
		}while(a[i].tk <0 || a[i].tk >10);
		
		/////
		do{
			cout << "Nhap diem giua ki:  ";cin >> a[i].gk;
		}while(a[i].gk<0 || a[i].gk>10);
		
		/////
		do{
			cout << "Nhap diem cuoi ki:  ";cin >> a[i].ck;
		}while(a[i].ck<0 || a[i].ck>10);
		
		/////
		do{
			cout << "Nhap diem thuc hanh:  ";cin >> a[i].th;
		}while(a[i].th<0 || a[i].th>10);
		
		cout << endl;
	}
}


void output(sv a[],int n)
{
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	cout << endl;
	printf("%5s %20s %20s","STT","Ho Ten","MaSV");
	cout << endl;
	int v=0;
	for(int i=0;i<n;i++)
	{
		v++;
		printf("%5d %20s %20s",v,a[i].hoten,a[i].masv);
		cout << endl;
	}
	cout << "*******************************************************" << endl << endl;
}


float diemtb(float a,float b,float c,float d)
{
	float DTB=(double)(((2*a+3*b+5*c)/10)*2+d)/3;
	return DTB;
}


void danhsachsvhoclai(sv a[],int n)
{
	cout << endl << "			DANH SACH SINH VIEN HOC LAI			   " << endl;
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	cout << endl;
	printf("%5s %20s %20s %20s","STT","Ho Ten","MaSV","DTB");
	cout << endl;
	int v=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].dtb < 4)
		{
			v++;
			printf("%5d %20s %20s %20.1f",v,a[i].hoten,a[i].masv,a[i].dtb);
			cout << endl;
		}
	}
	cout << "*********************************************************************" << endl << endl;
}


void sapxep(sv a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].dtb < a[j].dtb)
				S(sv,a[i],a[j]);
		}
	}
	cout << "			DANH SACH THEO THU TU GIAM DAN CUA DTB			   " << endl;
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	cout << endl;
	printf("%5s %20s %20s %20s","STT","Ho Ten","MaSV","DTB");
	cout << endl;
	int v=0;
	for(int i=0;i<n;i++)
	{
			v++;
			printf("%5d %20s %20s %20.1f",v,a[i].hoten,a[i].masv,a[i].dtb);
			cout << endl;
	}
	cout << "**********************************************************************" << endl << endl;
}


void hienthi(sv a[],int n)
{
	cout << "					DANH SACH DIEM THI KTLT" << endl;
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	cout << endl;
	printf("%5s %20s %20s %10s %10s %10s %10s %10s %10s","STT","Ho Ten","MaSV","TK","GK","CK","TH","DTB","GHI CHU");
	cout << endl;
	int v=0;
	for(int i=0;i<n;i++)
	{
		v++;
		if(a[i].dtb < 4)
		{
			printf("%5d %20s %20s %10.1f %10.1f %10.1f %10.1f %10.1f %10s",v,a[i].hoten,a[i].masv,a[i].tk,a[i].gk,a[i].ck,a[i].th,a[i].dtb,"Hoc lai");
			cout << endl;
		}
		else
		{
			printf("%5d %20s %20s %10.1f %10.1f %10.1f %10.1f %10.1f",v,a[i].hoten,a[i].masv,a[i].tk,a[i].gk,a[i].ck,a[i].th,a[i].dtb);
			cout << endl;
		}
	}
	cout << endl << endl;
}

void search(sv a[],int n)
{
	char x[50];
	cout << "Nhap ma X: "; cin >> x;
	int b=0;
	for(int i=0;i<n;i++)
	{
		if (strcmp(a[i].masv,x) == 0)
		{
			cout << "Ho ten: " << a[i].hoten << endl;
			cout << "Ma SV: " << a[i].masv << endl;
			cout << "Diem TK: " << a[i].tk << endl;
			cout << "Diem GK: " << a[i].gk << endl;
			cout << "Diem CK: " << a[i].ck << endl;
			cout << "Diem TH: " << a[i].th << endl;
			cout << "Diem TB: " << a[i].dtb << endl;
			cout << endl;
			b=1;
			break;
		}	
	}
	if(b==0)
		cout << "Khong tim thay!";
}



int main()
{
	int n;
	sv a[MAX];
	input(a,n);
	for(int i=0;i<n;i++)
	{
		float diem=0;
		diem=diemtb(a[i].tk,a[i].gk,a[i].ck,a[i].th);
		a[i].dtb=diem;
	}
	output(a,n);
	danhsachsvhoclai(a,n);
	search(a,n);
	sapxep(a,n);
	hienthi(a,n);
	
}


