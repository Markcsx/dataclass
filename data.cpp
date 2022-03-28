#include "data.h"
#include "iostream"
#include "string"
#include <stdio.h>

using namespace std;

CData::CData(){
	m_dia=1;
	m_mes=12;
	m_any=2000;
}

CData::CData(int dia, int mes, int any){
	m_dia = dia;
	m_mes = mes;
	m_any = any;
}

int CData::GetDia() const
{
	return m_dia;
}

int CData::GetMes() const
{
	return m_mes;
}

bool
CData::SetData(int dia, int mes, int any){
	bool retValue;
	if(ComprovaRang(dia,1,31) &&
	ComprovaRang(mes,1,12)) {
		m_dia = dia;
		m_mes = mes;
		m_any = any;
		retValue = true;
	}else {
		m_dia = 1;
		m_mes = 1;
		m_any = 2000;
		retValue = false;
	}
	return retValue;
}

void
CData::Print(){
	printf("%02d/%02d/%d \n", m_dia, m_mes, m_any);
}

bool
CData::ComprovaRang(int val, int valMin, int valMax){
	return (val>=valMin) && (val<=valMax);
}


ostream& operator<< (ostream &os, const CData& obj){
	os << obj.m_dia << "/" << obj.m_mes << "/" << obj.m_any;
	return os;
}
istream& operator>> (istream &is, CData& obj){
	char tmp;

	is >> obj.m_dia >> tmp >> obj.m_mes >> tmp >>obj.m_any;
	return is;
}

bool
CData::operator==(const CData& opRight){
	bool retValue = false;

	retValue = ((m_dia==opRight.m_dia)&&
				(m_mes==opRight.m_mes)&&
				(m_any==opRight.m_any));
	return retValue;
}


bool
operator>(const CData& opLeft, const CData& opRight){
	bool retValue = false;
	if (opLeft.m_any > opRight.m_any){
		retValue = true;
	} else {
		if(opLeft.m_any == opRight.m_any){
			if(opLeft.m_mes > opRight.m_mes){
				retValue = true;
			} else {
				if(opLeft.m_mes == opRight.m_mes){
					if(opLeft.m_dia > opRight.m_dia){
						retValue = true;
					}
				}
			}
		}
	}

	return retValue;
}
