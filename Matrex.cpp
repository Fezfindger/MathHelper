#include "StdAfx.h"
#include "Matrex.h"
//���������� ������������
Matrex::Matrex(char type,int s){
    int i,j;
 
    if(s < 1) size = 1;
    else if(s > 10) size = 10;
    else size = s;
 
    mtx = new int *[size];
    for(i=0; i<size; i++)
        mtx[i] = new int[size];
 
    switch(type){
    case'0':
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
                mtx[i][j] = 0;
        break;
    case'1':
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
                mtx[i][j] = (i==j)? 1:0;
        break;
    case'r':
        srand(time(NULL));
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
                mtx[i][j] = rand() % 1000;
        break;
    case'm':
        cout << "\n";
        for(i=0; i<size; i++)
            for(j=0; j<size; j++){
                do{
                    cout << "������� �������� mtx[" << i << "][" << j << "]: "; 
                    fflush(stdin);
                }while(scanf( "%i",&mtx[i][j])!=1 || cin.rdbuf()->in_avail()!=1);
                mtx[i][j]%=1000;
            }
        break;
    }
}
 
//����� ������
Matrex Matrex::Add(Matrex ob){
    Matrex result('0',size);
    int i,j;
 
    for(i=0; i<size;i++)
        for(j=0;j<size;j++)
            result.mtx[i][j] = mtx[i][j] + ob.mtx[i][j];
    
    return result;
}
 
//��������� ������
Matrex Matrex::Sub(Matrex ob){
    Matrex result('0',size);
    int i,j;
 
    for(i=0; i<size;i++)
        for(j=0;j<size;j++)
            result.mtx[i][j] = mtx[i][j] - ob.mtx[i][j];
    
    return result;
}
 
//��������� ������
Matrex Matrex::Mul(Matrex ob){
    Matrex result('0',size);
    int i,j,k;
 
    for(k=0; k<size;k++)
        for(i=0;i<size;i++)
            for(j=0;j<size;j++)
                result.mtx [k][i]= result.mtx[k][i] + mtx[k][j] * ob.mtx[j][i];
            
    return result;
}
 
//����� ���� �������� �������
int Matrex::SumAllElements(){
    int result = 0;
    
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            result+=mtx[i][j];
    
    return result;
}
 
//����� ��������� �� ���������
int Matrex::SumDiagElements(){
    int result = 0;
    
    for(int i=0; i<size; i++)
        result+=mtx[i][i];
    
    return result;
}
 
//****************************************************
 
//������������ ��������� �������
bool CorrectElem(Matrex &ob){
    int i,j,change_val;
    char ch;
    
    do{
        cout << "������ �������� �������� ������� (0-���, 1 -��): ";
        fflush(stdin);
    }while(scanf("%c", &ch)!=1 || cin.rdbuf()->in_avail()!=1 || ch!='0' && ch !='1');
 
    if(ch == '0') return false;
 
    do{
        cout <<"������� ����� ������, ������� � ����� �������� (�,�,�): ";
        fflush(stdin);
    }while(scanf("%i,%i,%i",&i,&j,&change_val)!=3 || cin.rdbuf()->in_avail()!=1 ||
        !ob.isValidIndex(i) || !ob.isValidIndex(j));
 
    ob.SetVal(i, j, change_val % 1000);
    return true;
}
 
//�������� �������
void ShowMatrex(Matrex &ob){
    int i,j;
    
    for(i=0; i<ob.GetSize(); i++){
        for(j=0; j<ob.GetSize(); j++){
            cout.width(6);
            cout << ob.GetVal(i, j) << ' ';
        }
        cout << "\n";   
    }
    cout << "\n";
}
 
//����� ������� ���������� �������
void FillMatrex(char &ch){
    cout << "0-��������� ������.\n"
         << "1-��������� �������.\n"
         << "r-��������� ������.\n"
         << "m-������ ���� ���������.\n";
    do{
        cout << "�������� ���� �� �������: ";
        fflush(stdin);
    }while(scanf("%c",&ch)!=1 || cin.rdbuf()->in_avail()!=1 ||
        ch != '0' && ch != '1' &&ch!='r' && ch!='m');
}
 
void Mat(){
    char ch_fill1;        //������ ���������� 1 �������
    char ch_fill2;        //������ ���������� 2 �������
    char ch_operations;   //����� ��������
    int size;
 
    setlocale(LC_ALL,"Rus");
    
    for(;;){
        system("cls");
        
        cout   << "1.����� ������.\n"
               << "2.�������� ������.\n"
               << "3.��������� ������.\n"
               << "4.����� ��������� �� ���������.\n"
               << "5.����� ���� ���������.\n";
        do{
            cout << "�������� ���� �� ������� (0 - ��� ������): ";
            fflush(stdin);
        }while(scanf("%c", &ch_operations)!=1 || cin.rdbuf()->in_avail()!=1 ||
            ch_operations < '0' || ch_operations > '5');    
        
        if(ch_operations == '0') break; //���� ����, �� �������
 
        //������ ������ ������
        do{
            cout << "\n������� ������ ������: ";
            fflush(stdin);
        }while(scanf("%i", &size)!=1 || cin.rdbuf()->in_avail()!=1);
 
        Matrex result;  //������� ��� �������� ���������� ��������
 
        if(ch_operations > '0' && ch_operations < '4'){
            cout << "\n������� 1:\n";
            FillMatrex(ch_fill1);       //������ ������ ���������� 1 �������
            Matrex ob(ch_fill1,size);   //������� 1 �������
            
            cout << "\n";
 
            //���������� � ������������ �������, ���� ����
            do{
                cout << "�� ����� ������� 1:\n";
                ShowMatrex(ob);
            }while(CorrectElem(ob));
    
            cout << "\n������� 2:\n";
            FillMatrex(ch_fill2);         //��������� ������� 2
            Matrex ob2(ch_fill2,size);    //������� 2 �������
            
            cout << "\n";
 
            //���������� � ������������, ���� ���� 2 �������
            do{
                cout << "�� ����� ������� 2:\n";
                ShowMatrex(ob2);
            }while(CorrectElem(ob2));
            
            //���������� �������� 1,2 ��� 3
            switch(ch_operations){
            case'1':
                result = ob.Add(ob2);        
                cout << "��������� ��������:\n";
                ShowMatrex(result);      
                break;
            case'2':
                result = ob.Sub(ob2);          
                cout << "��������� ��������� :\n";
                ShowMatrex(result);
                break;
            case'3':
                result = ob.Mul(ob2);
                cout << "��������� ���������\n";
                ShowMatrex(result);
                break;
            }
        }else if(ch_operations == '4' || ch_operations == '5'){
            cout << "������� 1:\n";
            FillMatrex(ch_fill1);        //����� ���������� �������
            Matrex ob(ch_fill1,size);    //������� �������
        
            //���������� � ������������ �������, ���� ����
            do{
                cout << "�� ����� ������� 1:\n";
                ShowMatrex(ob);
            }while(CorrectElem(ob));
 
            //���������� �������� 4 ��� 5
            switch(ch_operations){
            case'4':
                cout << "����� ��������� �� ���������: ";
                cout << ob.SumDiagElements() << "\n";                
                break;
            case'5':
                cout << "����� ���� ���������: ";
                cout << ob.SumAllElements() << "\n";
                break;
            }
        }
        cout << "��� ����������� ������� ����� ������.";
        getch();
    }
}