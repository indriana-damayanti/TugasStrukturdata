#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

typedef struct segitiga
{
	char nama[20];
	float tinggi;
    float alas;
    float nilai;
	struct segitiga *next_segitiga;
	
}data;

int main () {
	data *segitiga1, *segitiga2, *segitiga3, *temp;

	segitiga1=(data *)malloc(sizeof(data));
	segitiga2=(data *)malloc(sizeof(data));

	strcpy(segitiga1->nama,"Segitiga 1 =>");
	strcpy(segitiga2->nama,"Segitiga 2 =>");

	segitiga1->tinggi=4;
	segitiga2->tinggi=6;

	segitiga1->alas=6;
	segitiga2->alas=6;

	segitiga1->nilai=0.5*segitiga1->tinggi*segitiga1->alas;
	segitiga2->nilai=0.5*segitiga2->tinggi*segitiga2->alas;

	segitiga1->next_segitiga =segitiga2;
	segitiga2->next_segitiga =segitiga3;
	segitiga2->next_segitiga =0;

	cout << "===Kondisi Awal segitiga===\n";
	cout << "---------------------------\n";
	temp=segitiga1;
	cout<< temp->nama << "Tinggi: " << temp->tinggi << " Alas : " << temp->alas <<" "<< endl;
	cout<< "Nilai : " << temp->nilai<<  " "<<endl;

	temp=segitiga1->next_segitiga;
	cout<<temp->nama << "Tinggi: " << temp->tinggi << " Alas : " << temp->alas <<" "<< endl;
	cout<< "Nilai : " << temp->nilai<<  " "<<endl;


	cout <<"\n=== Kondisi segitiga (data bertamabah)===\n";
	cout << "----------------------------------------\n";
	segitiga3=(data *)malloc(sizeof(data));
	strcpy(segitiga3->nama,"Segitiga 3 =>");
	segitiga3->tinggi=8;
	segitiga3->alas=6;

	segitiga3->nilai=0.5*segitiga3->tinggi*segitiga3->alas;
	segitiga2->next_segitiga=segitiga3;

	for(temp=segitiga1; temp!=0; temp=temp->next_segitiga){
	cout<<temp->nama << "Tinggi : " << temp->tinggi << " Alas : " << temp->alas <<" "<< endl;
	cout<< "Nilai : " << temp->nilai<<  " "<<endl;
	}	

	cout << "\n=== Kondisi segitiga (data berkurang) ===";
	cout << "\n\tMenghapus segitiga ke 2\n";
	cout << "-----------------------------------------\n";
	segitiga1->next_segitiga=segitiga3;
	free(segitiga2);

	for(temp=segitiga1; temp!=0; temp=temp->next_segitiga){
		cout<<temp->nama << "Tinggi : " << temp->tinggi << " Alas : " << temp->alas <<" "<< endl;
		cout<< "Nilai : " << temp->nilai<<  " "<<endl;
	}

	return 0;

}