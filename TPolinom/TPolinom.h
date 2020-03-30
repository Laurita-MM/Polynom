#pragma once
#include <iostream>
#include "HeadList.h"
using namespace std;

struct TMonom {
	double coeff;
	int px, py, pz;

	TMonom() {
		coeff = 0;
		px = py = pz = 0;
	}

	TMonom(int arr[1][2]) {
		coeff = arr[0][0];
		px = arr[0][1] / 100;
		py = arr[0][1] / 10 % 10;
		pz = arr[0][1] % 10;
	}

	bool operator< (TMonom& mon) {
		if (px < mon.px)
			return true;
		else
			if (py < mon.py)
				return true;
			else
				if (pz < mon.pz)
					return true;
				else
					return false;
	}

	bool operator> (TMonom& mon) {
		if (px > mon.px)
			return true;
		else
			if (py > mon.py&& px == mon.px == py )
				return true;
			else
				if (pz > mon.pz && px == mon.px && py == mon.py)
					return true;
				else
					return false;
	}

	bool operator== (TMonom& mon) {
		if ((px == mon.px) && (py == mon.py) && (pz == mon.pz))
			return true;
		else
			return false;
	}

	bool operator!= (TMonom & mon) {
		if (*this == mon)
			return false;
		else
			return true;
	}
};

class TPolinom : public THeadList<TMonom> {
public:

	TPolinom() : THeadList<TMonom>() {
		pHead->val.pz = -1;
	}

	TPolinom(int** arr, int sizep) : THeadList<TMonom>() {          
		pHead->val.pz = -1;
		for (int i = 0; i < sizep; i++) {
			TMonom mon;
			mon.coeff = arr[i][0];
			mon.px = arr[i][1] / 100;
			mon.py = arr[i][1] / 10 % 10;
			mon.pz = arr[i][1] % 10;
			InsMonom(mon);
		}
	}

	TPolinom(TPolinom& p) : THeadList<TMonom>() {
		pHead->val.pz = -1;
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			TMonom mon = p.pCurr->val;
			InsMonom(mon);
		}
	}

	void operator= (TPolinom& p) {
		DelList();
		Reset();
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			InsMonom(p.pCurr->val);
		}
	}

	TMonom& GetMonom() {
		return pCurr->val;
	}

	void InsMonom(TMonom mon) {
		if (mon.coeff == 0)
			return;
		for (Reset(); !IsEnd(); GoNext()) {
			if (mon == GetMonom()) {
				double tmp = mon.coeff + GetMonom().coeff;
				if (tmp)
					//GetMonom().coeff = tmp;
					pCurr->val.coeff = tmp;
				else
					DelCurr();
				return;
			}
			if (mon > GetMonom()) {
				InsCurr(mon);
				return;
			}
			
		}
		InsLast(mon);
	}

	void operator *= (double a) {
		for (Reset(); !IsEnd(); GoNext()) {
			pCurr->val.coeff *= a;
		}
	}

	void operator*= (TMonom mon) {
		for (Reset(); !IsEnd(); GoNext()) {
			pCurr->val.coeff *= mon.coeff;
			pCurr->val.px += mon.px;
			pCurr->val.py += mon.py;
			pCurr->val.pz += mon.pz;
		}
		return;
	}

	TPolinom operator* (TMonom mon) {
		TPolinom res = *this;
		res *= mon;
		return res;
	}

	void operator+=(TPolinom& q) {
		TMonom pm, qm, rm;
		Reset();
		q.Reset();
		while (!q.IsEnd()) {
			pm = pCurr->val;
			qm = q.pCurr->val;
			if (pm > qm)
				GoNext();
			else {
				if (pm < qm) {
					InsCurr(qm);
					q.GoNext();
				}
				else {
					if (pm == qm) {
						rm = pm;
						rm.coeff += qm.coeff;
						if (rm.coeff == 0) {
							DelCurr();
							q.GoNext();
						}
						else {
							pCurr->val = rm;
							q.GoNext();
							GoNext();
						}
					}
				}
			}
		}
	}

	TPolinom operator+ (TPolinom& pol) {
		TPolinom res = *this;
		res += pol;
		return res;
	}

	friend std::ostream& operator<<(std::ostream& os, TPolinom& p) {
		for (p.Reset(); !p.IsNextEnd(); p.GoNext()) {
			std::cout << p.pCurr->val.coeff << "*x^" << p.pCurr->val.px << "y^" << p.pCurr->val.py << "z^" << p.pCurr->val.pz << " + ";//<<  std::endl;
		}
		//p.GoNext();
		std::cout << p.pCurr->val.coeff << "*x^" << p.pCurr->val.px << "y^" << p.pCurr->val.py << "z^" << p.pCurr->val.pz << std::endl;
		return os;
	}
};
