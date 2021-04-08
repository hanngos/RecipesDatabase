#pragma once
#ifndef PRZEPIS_H
#define PRZEPIS_H

class Przepis
{
public:
	virtual void setValue() = 0;
	template<class T>
	T getValue() {
		return T;
	}
};


#endif // !PRZEPIS_H
