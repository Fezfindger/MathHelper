#pragma once
#include "stdafx.h"

using namespace std;
 
class Matrex{
    int **mtx;   //���� �������� �������
    int size;    //����� �������� ������ �������
public:
    //������������
    Matrex(char type ,int size);
    Matrex(){};
 
    //�������������� �������� ��� ���������
    Matrex Add(Matrex ob);        
    Matrex Sub(Matrex ob);        
    Matrex Mul(Matrex ob);        
 
    //�������������� �������� ��� ���������
    int SumDiagElements();
    int SumAllElements();
 
    //������� �������
    int GetSize(){ return size; }
    void SetVal(int i, int j, int val) {
        mtx[i][j] = val;
    }
    int GetVal(int i, int j){ return mtx[i][j]; }
 
    //��������� �������� �� ������ ����������
    bool isValidIndex(int x){ 
        if(x < 0 || x > size - 1) return false;
        return true;
    }
};
bool CorrectElem(Matrex &ob);
void ShowMatrex(Matrex &ob);
void FillMatrex(char &ch);
void Mat();
