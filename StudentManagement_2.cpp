#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
struct thongtin{
	char holot[30];
	char ten[30];
	char ngaysinh[30];
	char noisinh[30];
	char xeploai[30];
	int win,ex,word,tongdiem;
};
void input(thongtin a[],int &n)
{
	do{
		cout << "Nhap so luong: "; cin >> n;
	}while(n<0);
	for(int i=0;i<n;i++)
	{
		cout << "Nhap ho lot: "; fflush(stdin);gets(a[i].holot);
		cout << "Nhap ten: "; cin >> a[i].ten;
		cout << "Nhap ngay sinh: "; cin >> a[i].ngaysinh;
		cout << endl;
	}
	cout << endl;
}

void nhapdiem(thongtin a[],int n)
{
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	for(int i=0;i<n;i++)
	{
		cout << "Nhap noi sinh cua sinh vien: " << a[i].holot << " " << a[i].ten << endl;
		cout << "Nhap noi sinh: "; fflush(stdin); gets(a[i].noisinh);
		cout << "Nhap diem cua sinh vien: " << a[i].holot << " " << a[i].ten << endl;
		do{
			cout << "Nhap diem D_Win: "; cin >> a[i].win;
		}while(a[i].win < 0 || a[i].win > 10);
		do{
			cout << "Nhap diem D_Excel: "; cin >> a[i].ex;
		}while(a[i].ex < 0 || a[i].ex > 10);
		do{
			cout << "Nhap diem D_Word: "; cin >> a[i].word;
		}while(a[i].word < 0 || a[i].word > 10);
		cout << endl;
	}
	cout << endl;
}

void output(thongtin a[],int n)
{
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	int v=1;
	printf("%5s %20s %25s %20s %20s","STT","Ho va Ten","Ngay sinh","Noi sinh","Ghi chu");
	cout << endl;
	for(int i=0;i<n;i++)
	{
		printf("%5d %20s",v,a[i].holot);
		printf(" %s %20s %20s",a[i].ten,a[i].ngaysinh,a[i].noisinh);
		cout << endl;
		v++;
	}
	cout << endl;
}


void tinhxeploai(thongtin a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int x=a[i].win;
		int y=a[i].ex;
		int z=a[i].word;
		a[i].tongdiem = x+y+z;
	}	
	for(int i=0;i<n;i++)
	{
		if(a[i].tongdiem >= 24)
			strcpy(a[i].xeploai,"Gioi");
		else if(a[i].tongdiem >=18 && a[i].tongdiem < 24 )
			strcpy(a[i].xeploai,"Kha");
		else if(a[i].tongdiem >=15 && a[i].tongdiem < 18 )
			strcpy(a[i].xeploai,"T.Binh");
		else
			strcpy(a[i].xeploai,"Kem");
	}
	cout << endl;
}

void inketqua(thongtin a[], int n)
{
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	int v=1;
	printf("%5s %20s %25s %20s","STT","Ho va Ten","Diem Tong","Xep Loai");
	cout << endl;
	for(int i=0;i<n;i++)
	{
		printf("%5d %20s",v,a[i].holot);
		printf(" %s %20d %20s",a[i].ten,a[i].tongdiem,a[i].xeploai);
		cout << endl;
		v++;
	}
	cout << endl;
}

int main()
{
	int n;
	thongtin a[100];
	input(a,n);
	nhapdiem(a,n);
	output(a,n);
	tinhxeploai(a,n);
	inketqua(a,n);
}


