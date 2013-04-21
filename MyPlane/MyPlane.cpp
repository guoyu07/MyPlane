// MyPlane.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <sstream>  
#include<string>
#include <stdlib.h> 
#include<iostream>
//#include "afx.h"
using namespace std;
#define PCOUT 100			//���庽������
#define PGCOUT 1000			//����˿�����
int ipCount;				//���庽�����
int perCount=0;				//���嵱ǰ��Ʊ����




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

}MyPlane[PCOUT],*Planes;
//����˿͵Ľṹ��
struct passenger{
	char name[30];			//�˿�����		
	char pid[30];			//֤����
	int count;				//��Ʊ����		
	char id[30];		    //�����
	char ddid[30];			//�������
	plane pl;

}Passenger[PGCOUT],*Passg;

//��������
void plInput();										//		����¼�뺽�����
void plOutput();									//		��������������
void outPut();										//		�������Ŀ¼����
void search();	
void searchPlbyId(char id[]);						//		ͨ������Ų��Һ�����Ϣ
void searchPlbySta(char start[],char end[]);		//		ͨ����ʼվ���Һ�����Ϣ
void resetPl(char pid[30]);							//		�޸ĺ�����Ϣ
void deletePl();									//ɾ��������Ϣ
void bookTicket();									//		��Ʊ��Ϣ
void outputTicket();								//		�����Ʊ��Ϣ
void returnTicket();								//��Ʊ��Ϣ
void resetTicket();									//�޸���Ϣ

//������
int main(){
	int in;
	outPut();
	cout<<"��ѡ��"<<endl;
	cin >>in;
		while(in!=-1){
			switch(in){
				case 0:								//�˳�����
					exit(1);
					break;
				case 1:								//¼�뺽����Ϣ
					plInput();
					break; 
				case 2:								//���������Ϣ
					plOutput();
					break;
				case 3:								//���Һ���
					search();
					break;
				case 4:								//�޸ĺ�����Ϣ
					char pid[30];
					cout<<"��������Ҫ�޸ĵĺ����:"<<endl;
					cin>>pid;
					resetPl( pid);
					break;
				case 6:
					bookTicket();					//��Ʊ
					break;
				case 7:								//�����Ʊ��Ϣ
					outputTicket();
					break;
				default:							//ѡ�����
					cout<<"����������������룡��"<<endl;
					break;	
			}
		outPut();
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
	   cout<<endl<<"�������"<<i+1<<"��������Ϣ����������������������"<<endl;
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
	MyPlane[i].kong=MyPlane[i].counts;
	cout<<"������Ʊ��: "<<endl;
	cin>>MyPlane[i].ticket;//��ȡ��Ʊ��
	cout<<"�������ۿ�: "<<endl;
	cin>>MyPlane[i].discount;//��ȡ��Ʊ��
	cout<<endl;
	
	}
}

void outputTicket(){
	cout<<endl;
	cout<<"������ "<<"  ����� "<<" ����  "<<"     ֤����"<<"  ��Ʊ����"<<" ���վ   "<<"  �յ�վ "
		<<endl;
	for (int i=0;i<perCount;i++){	
		cout<<Passenger[i].ddid<<"  "<<Passenger[i].id<<"   "<<Passenger[i].name<<"  "<<Passenger[i].pid<<"  "
			<<Passenger[i].count<<"   "<<Passenger[i].pl.sStation<<"  "<<Passenger[i].pl.eStation<<endl;

	}

}

//���庽���������
void plOutput(){
	cout<<endl;
	cout<<"������ "<<"���վ   "<<"  �յ�վ "<<" ���ʱ��  "<<"  ����ʱ��  "
		<<"  Ʊ��  "<<"  �ۿ�  "<<" ������ "<<endl;
	for (int i=0;i<ipCount;i++){	
		cout<<MyPlane[i].id<<"      "<<MyPlane[i].sStation<<"      "<<MyPlane[i].eStation<<"     "
		<<MyPlane[i].sTime<<"       "<<MyPlane[i].eTime<<"       "<<MyPlane[i].ticket<<"     "<<MyPlane[i].discount<<"     "<<MyPlane[i].kong<<endl;
	}
}
//���Һ�����Ϣ
void search(){
	int sel;
	cout<<"��ѡ����ҷ�����"<<endl;
	cout<<"///////////////////////////////////////"<<endl;
	cout<<"1. ͨ������Ų�ѯ��"<<endl<<
		"2. ͨ����վ����"<<endl;
	cout<<"///////////////////////////////////////"<<endl;	
	cin >>sel;	
			switch(sel){
				case 1:	
					char pid[30];
					cout<<"�����뺽���"<<endl;
					cin>>pid;				
					searchPlbyId(pid);
					break;
				case 2:		
					char mystart[30],myend[30];
					cout<<"��������ɵص�"<<endl;
					cin>>mystart;
					cout<<"�����뽵��ص�"<<endl;
					cin>>myend;
					 searchPlbySta(mystart,myend);		//ͨ����ʼվ���Һ�����Ϣ
					break; 
					
				default:							//ѡ�����
					cout<<"����������������룡��"<<endl;
					break;
				
			}
}


//����ͨ������Ų��Һ�����Ϣ����
void searchPlbyId(char id[]){
	cout<<endl;
	cout<<"������   "<<"���վ   "<<"  �յ�վ "<<" ���ʱ��  "<<"  ����ʱ��  "
		<<"  Ʊ��  "<<"  �ۿ�  "<<" ������ "<<endl;
	for (int i=0;i<ipCount;i++){	
		if (strcmp(MyPlane[i].id,id)==0){
			cout<<MyPlane[i].id<<"      "<<MyPlane[i].sStation<<"      "<<MyPlane[i].eStation<<"   "
				<<MyPlane[i].sTime<<"     "<<MyPlane[i].eTime<<"     "<<MyPlane[i].ticket<<"     "<<MyPlane[i].discount<<"     "<<MyPlane[i].kong<<endl;
		}
	}
}
//����ͨ����ʼվ���Һ�����Ϣ
void searchPlbySta(char start[],char end[]){

	cout<<endl;
	cout<<"������   "<<"���վ   "<<"  �յ�վ "<<" ���ʱ��  "<<"  ����ʱ��  "
		<<"  Ʊ��  "<<"  �ۿ�  "<<" ������ "<<endl;
	for (int i=0;i<ipCount;i++){	
		if (strcmp(MyPlane[i].sStation,start)==0&&strcmp(MyPlane[i].eStation,end)==0){
			cout<<MyPlane[i].id<<"      "<<MyPlane[i].sStation<<"      "<<MyPlane[i].eStation<<"   "
				<<MyPlane[i].sTime<<"     "<<MyPlane[i].eTime<<"     "<<MyPlane[i].ticket<<"     "<<MyPlane[i].discount<<"     "<<MyPlane[i].kong<<endl;
		}
	}
}
//�޸ĺ�����Ϣ
void resetPl(char pid[30]){
	cout<<endl;
	
	bool fin=false;

	for (int i=0;i<ipCount;i++){	
		if (strcmp(MyPlane[i].id,pid)==0){
			fin=true;
			cout<<"��������ʼվ: "<<endl;
			cin>>MyPlane[i].sStation;//��ȡ��ʼվ
			cout<<"�������յ�վ: "<<endl;
			cin>>MyPlane[i].eStation;//��ȡ�յ�վ
			cout<<"���������ʱ��: "<<endl;
			cin>>MyPlane[i].sTime;//��ȡ���ʱ��
			cout<<"�����뽵��ʱ��: "<<endl;
			cin>>MyPlane[i].eTime;//��ȡ����ʱ��
			cout<<"�������ܳ˿�����: "<<endl;
			cin>>MyPlane[i].counts;//��ȡ��Ʊ��
			MyPlane[i].kong=MyPlane[i].counts;
			cout<<"������Ʊ��: "<<endl;
			cin>>MyPlane[i].ticket;//��ȡƱ��
			cout<<"�������ۿ�: "<<endl;
			cin>>MyPlane[i].discount;//��ȡ�ۿ�
			cout<<endl;

			cout<<"�޸ĳɹ�����"<<endl;
			break;
		}
	}
	if (fin==false){
	cout<<"�Բ���δ�ҵ�����"<<endl;
	}
}							


//�����������
void outPut(){
cout<<"                       ��---���ã���ӭ����ɻ��������ϵͳ��---�� "<<endl;
cout<<"================================================================================";
cout<<"     -------- ��        1.���뺽����Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        2.���������Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        3.���Һ�����Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        4.�޸ĺ�����Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        5.ɾ��������Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        6.��Ʊ                    ��-------- "<<endl;
cout<<"     -------- ��        7.�����Ʊ��Ϣ            ��-------- "<<endl;
cout<<"     -------- ��        0.�˳�                    ��-------- "<<endl;
cout<<"================================================================================ "<<endl;
}


//		��Ʊ��Ϣ
void bookTicket(){
	char pid[30];    //��ѯ�����
	bool fin=false;
	cout<<"��ӭ���뺽�ඩƱϵͳ"<<endl<<"�����뺽��ţ�"<<endl;
	cin>>pid;
	
	for (int i=0;i<ipCount;i++){	
		if (strcmp(MyPlane[i].id,pid)==0){
			fin=true;			//���ҵ�����
			//Passenger[perCount++].id=pid;							//���ú�����
			strcpy(Passenger[perCount].id,pid);
			//CString s;
			//char s[30];
			//s.Format("%d",perCount);

			//char last[]=perCount;
			strcpy(Passenger[perCount].ddid,strcat(pid,"--"));						//���ö������						
			Passenger[perCount].pl=MyPlane[i];
			cout<<"������������"<<endl;
			cin>>Passenger[perCount].name;						//��������
			cout<<"������֤���ţ�"<<endl;							//����֤����
			cin>>Passenger[perCount].pid;
			cout<<"�����붩Ʊ������"<<endl;							//���붩Ʊ����
			cin>>Passenger[perCount].count;
			MyPlane[i].kong-=Passenger[perCount].count;			//��Ʊ������
			perCount++;
			break;
		}
	}
	if (fin==false){
		cout<<"�Բ�������ҵĺ���δ�ҵ�����"<<endl;
	}
}							
