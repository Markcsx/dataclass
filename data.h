#include <iostream>
using namespace std;

class CData {
public:
	CData();
	CData(int dia, int mes, int any);
	CData(const CData& data);

	int GetDia() const;
	int GetMes() const;

	bool SetData(int dia, int mes, int any);
	void Print();

	bool operator==(const CData&);


private:
	bool ComprovaRang(int val, int valMin, int valMax);

private:
	int m_dia;
	int m_mes;
	int m_any;

	friend ostream& operator<< (ostream& os, const CData& obj);
	friend istream& operator>> (istream &is, CData& obj);

	friend bool operator>(const CData& opLeft, const CData& opRight);
};
