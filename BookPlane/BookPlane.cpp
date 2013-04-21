// MyPlane.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int ipCount=0;				//���庽�����
int perCount=0;				//���嵱ǰ��Ʊ����

//����ɻ�����Ľṹ��
typedef struct plane{
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
	plane *next;

}*Planes,PL;

//����˿͵Ľṹ��
typedef struct passenger{
	char name[30];			//�˿�����		
	char pid[30];			//֤����
	int count;				//��Ʊ����		
	char id[30];		    //�����
	char ddid[30];			//�������
	struct plane pl;		//���˷ɻ�
	passenger *next;

}*Passg,PAG;
Passg FirPa;		//����˿�����
Planes FirPl;		//����ɻ���������
//��������
void outPut();										//		���Ŀ¼����
void myOutputPl();									//		�����������
Planes myInputPl();								    //		�������뺯��
void searchPl();
void searchPlbyId();
void searchPlbySta(char mystart[],char myend[]);
Passg bookTickets(Passg MyPa);								//		��Ʊ����
void outPutTickets();

Passg MyPa;
//������
int main(){
	 MyPa=new PAG();

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
				FirPl=myInputPl();
					break; 
				case 2:								//���������Ϣ
					myOutputPl();
					break;
				case 3:
					searchPl();						//��ѯ������Ϣ
					break;
				
				case 6:								//���嶩Ʊ����
					
				MyPa=bookTickets( MyPa);
				break;
				case 7:
				  outPutTickets();					//��ʾ��Ʊ��Ϣ
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
Planes myInputPl(){
	Planes P1,P2,header;
	cout<<"������¼�뺽�������"<<endl;
	cin>>ipCount;
	 int i=0;
	 P2=new plane(); 
	 header=NULL;  
	
	while(i<ipCount){    
		if (i==0){				//����һ�ν���ʱ
			 P1=new plane(); 
			 header=P1;
		}
	cout<<endl<<"�������"<<i+1<<"��������Ϣ����������������������"<<endl;
	cout<<"�����뺽���: "<<endl;
	cin>>P1->id;     //��ȡ�����
	cout<<"��������ʼվ: "<<endl;
	cin>>P1->sStation;//��ȡ��ʼվ
	cout<<"�������յ�վ: "<<endl;
	cin>>P1->eStation;//��ȡ�յ�վ
	cout<<"���������ʱ��: "<<endl;
	cin>>P1->sTime;//��ȡʱ��
	cout<<"�����뽵��ʱ��: "<<endl;
	cin>>P1->eTime;//��ȡʱ��
	cout<<"�������ܳ˿�����: "<<endl;
	cin>>P1->counts;//��ȡ��Ʊ��
	P1->kong=P1->counts;
	cout<<"������Ʊ��: "<<endl;
	cin>>P1->ticket;//��ȡƱ��
	cout<<"�������ۿ�: "<<endl;
	cin>>P1->discount;//��ȡ�ۿ�
	cout<<endl;
	 P2=P1;  
    P1=new plane();  
     P2->next=P1;  
	i++;
	}
	return header;
}
//	��Ʊ����
Passg bookTickets(Passg MyPa){
	Passg endP=MyPa;
	if (endP->next!=NULL){
		endP=endP->next;			//��Ʊָ��ָ�����
	}

	Passg Pg=NULL;                   //����һ���ڲ��˿ͽڵ�
	Planes Pl1=FirPl;                // ����һ������ڵ㣬���Բ��Һ���
	char pid[30];					 //��ѯ�����
	bool fin=false;					 //�����ʼ��δ�ҵ�����
	cout<<"��ӭ���뺽�ඩƱϵͳ"<<endl<<"�����뺽��ţ�"<<endl;
	cin>>pid;						 //���붩Ʊ�ĺ����
	for (int i=0;i<ipCount;i++){	
		if (strcmp(Pl1->id,pid)==0){
			fin=true;				  //���ҵ�����
			//���ú�����
			Pg=new PAG();
			strcpy(Pg->id,pid);	
					
			strcmp((char*)Pg->pl.sStation,Pl1->sStation);//������ɽ���ص�
			//cout<<" ���ԣ�"<<Pg->pl.sStation<<"  ������"<<Pl1->sStation<<endl;
			strcmp(Pg->pl.eStation,Pl1->eStation);
			strcpy(Pg->ddid,strcat(pid,"--"));	//���ö������
			cout<<"������������"<<endl;
			cin>>Pg->name;						//��������
			cout<<"������֤���ţ�"<<endl;		//����֤����
			cin>>Pg->pid;
			cout<<"�����붩Ʊ������"<<endl;		//���붩Ʊ����
			cin>>Pg->count;
			Pl1->kong-=Pg->count;			    //��Ʊ������
			perCount++;   //������������
			break;
		}
		if (Pl1->next!=NULL)
		Pl1=Pl1->next;
		else break;
	}
	//Pg->next=NULL;
	endP->next=Pg;

	if (fin==false){
		cout<<"�Բ�������ҵĺ���δ�ҵ�����"<<endl;
	}
return MyPa;
}								




//���庽���������
void myOutputPl(){
	Planes P1=FirPl;
	cout<<endl;
	cout<<"������ "<<" ���վ "<<"  �յ�վ "<<" ���ʱ�� "<<"  ����ʱ��  "
		<<"  Ʊ��  "<<"  �ۿ� "<<" ������ "<<endl;
	int count=0;
	while (count<ipCount){
		cout<<P1->id<<"      "<<P1->sStation<<"    "<<P1->eStation<<"      "<<P1->sTime<<"      "
			<<P1->eTime<<"     "<<P1->ticket<<"       "<<P1->discount<<"       "<<P1->kong<<endl;
	P1=P1->next;
	count++;
	}

}
//�����ѯ������Ϣ
void searchPl(){
	int sel;
	cout<<"��ѡ����ҷ�����"<<endl;
	cout<<"///////////////////////////////////////"<<endl;
	cout<<"1. ͨ������Ų�ѯ��"<<endl<<
		  "2. ͨ����վ����"<<endl;
	cout<<"///////////////////////////////////////"<<endl;	
	cin >>sel;	
			switch(sel){
				case 1:				
					searchPlbyId();
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
//����ͨ����վ��ѯ����
void searchPlbySta(char mystart[],char myend[]){
	Planes P1=FirPl;
	bool fin=false;
	int count=0;
	
	while (count<ipCount){
		if(strcmp(P1->sStation,mystart)==0&&strcmp(P1->eStation,myend)==0){
			fin=true;
		cout<<endl;
	    cout<<"������   "<<"���վ   "<<"  �յ�վ "<<" ���ʱ��  "<<"  ����ʱ��  "
		<<"  Ʊ��  "<<"  �ۿ�  "<<" ������ "<<endl;

		cout<<P1->id<<"      "<<P1->sStation<<"    "<<P1->eStation<<"      "<<P1->sTime<<"      "
			<<P1->eTime<<"     "<<P1->ticket<<"       "<<P1->discount<<"       "<<P1->kong<<endl;
		break;
		}
		P1=P1->next;
	   count++;
	}
	if (fin==false){
	cout<<"�Բ���δ�ҵ�����ҵĺ��ࡣ"<<endl;
	}

}
void searchPlbyId(){
	Planes P1=FirPl;
	bool fin=false;
	int count=0;
	char search[30];
	cout<<"�������ѯ����ţ�"<<endl;
	cin>>search;
	while (count<ipCount){
		if(strcmp(P1->id,search)==0){
			fin=true;
		cout<<endl;
	    cout<<"������   "<<"���վ   "<<"  �յ�վ "<<" ���ʱ��  "<<"  ����ʱ��  "
		<<"  Ʊ��  "<<"  �ۿ�  "<<" ������ "<<endl;

		cout<<P1->id<<"      "<<P1->sStation<<"    "<<P1->eStation<<"      "<<P1->sTime<<"      "
			<<P1->eTime<<"     "<<P1->ticket<<"       "<<P1->discount<<"       "<<P1->kong<<endl;
		break;
		}
		P1=P1->next;
	   count++;
	}
	if (fin==false){
	cout<<"�Բ���δ�ҵ�����ҵĺ��ࡣ"<<endl;
	}

}
void outPutTickets(){
	Passg Pg=MyPa;
	cout<<"������ "<<"  ����� "<<" ����  "<<"     ֤����"<<
		"  ��Ʊ����"<<" ���վ   "<<"  �յ�վ "<<endl;
	do{
		Pg=Pg->next;
		if (Pg!=NULL)
			cout<<Pg->ddid<<"  "<<Pg->id<<"  "<<Pg->name <<"   "<<Pg->pid<<"  "<<Pg->count<<Pg->pl.sStation<<"  "<<Pg->pl.eStation<<endl;
	}while(Pg->next!=NULL);
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

