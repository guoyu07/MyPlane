// MyPlane.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include<iostream>
using namespace std;
#define PCOUT 100			//���庽������
#define PGCOUT 1000			//����˿�����
int ipCount;				//���庽�����

//����ɻ�����Ľṹ��
struct plane{
	char id[30];			//	�ɻ������
	char sTime[30];			//  ���ʱ��
	char eTime[30];			//  ����ʱ��
	char sStation[30];		//  ��ɵص�
	char eStation[30];		//	����ص�
	double ticket;			//  Ʊ��
	double discount;		//  �ۿ�
	int counts;				//	�ɳ�������
	int kong;				//  ������
	bool isFull;			//  �Ƿ�����
	int tId[30];			//  ������

}MyPlane[PCOUT];
//����˿͵Ľṹ��
struct passenger{
	char name[30];			//�˿�����		
	char pid[30];			//֤����
	int count;				//��Ʊ����		
	char id;			    //�������
	char ddid[30];				//�������

}Passenger[PGCOUT];

//��������
void plInput();				//		����¼�뺽�����
void plOutput();			//		��������������
void outPut();				//		�������Ŀ¼����


//������
int main(){

	int in;
	outPut();
	cout<<"��ѡ��"<<endl;
	cin >>in;
	while(in!=-1){
		switch(in){
			case 1:
				plInput();
				break; 
			case 2:
				plOutput();
				break;
		}
	cout<<"��ѡ��"<<endl;
	cin >>in;
	
	}
return 0;
}
//���庽��¼�뺯��

void plInput(){
	
	cout<<"������¼�뺽�������"<<endl;
	cin>>ipCount;
	for(int i=0;i<ipCount;i++)
   {

	cout<<"�����뺽���: "<<endl;
	cin>>MyPlane[i].id;     //��ȡ�����
	cout<<"��������ʼվ: "<<endl;
	cin>>MyPlane[i].sStation;//��ȡ��ʼվ
	cout<<"�������յ�վ: "<<endl;
	cin>>MyPlane[i].eStation;//��ȡ�յ�վ
	cout<<"���������ʱ��: "<<endl;
	cin>>MyPlane[i].sTime;//��ȡʱ��
	cout<<"�����뽵��ʱ��: "<<endl;
	cin>>MyPlane[i].eTime;//��ȡʱ��
	cout<<"�������ܳ˿�����: "<<endl;
	cin>>MyPlane[i].counts;//��ȡ��Ʊ��
	cout<<"������Ʊ��: "<<endl;
	cin>>MyPlane[i].ticket;//��ȡ��Ʊ��
	cout<<"�������ۿ�: "<<endl;
	cin>>MyPlane[i].discount;//��ȡ��Ʊ��
	}
}


//���庽���������
void plOutput(){
	cout <<"�������ѯ������"<<endl;
	char inplid[30];
	cin>>inplid;
	cout<<endl;
	cout<<"������   "<<"���վ   "<<"  �յ�վ "<<" ���ʱ��  "<<"  ����ʱ��  "
		<<"  Ʊ��  "<<"  �ۿ�  "<<" �Ƿ����� "<<endl;
	for (int i=0;i<ipCount;i++){	
		if (!strcmp(MyPlane[i].id,inplid)){
			cout<<MyPlane[i].id<<"      "<<MyPlane[i].sStation<<"      "<<MyPlane[i].eStation<<"   "
			<<MyPlane[i].sTime<<"     "<<MyPlane[i].eTime<<"     "<<MyPlane[i].ticket<<"     "<<MyPlane[i].discount<<"     "<<MyPlane[i].isFull<<endl;
		}
	}
}

//�����������
void outPut(){
cout<<"                       ��---���ã���ӭ����ɻ��������ϵͳ��---�� "<<endl;
cout<<"================================================================================";
cout<<"     -------- ��        1.���뺽����Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        2.���������Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        3.�޸ĺ�����Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        4.���Һ�����Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        5.ɾ��������Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        6.��Ʊ��Ϣ                ��-------- "<<endl;
cout<<"     -------- ��        7.��Ʊ��Ϣ                ��-------- "<<endl;
cout<<"     -------- ��        0.�˳�                    ��-------- "<<endl;
cout<<"================================================================================ "<<endl;
}


