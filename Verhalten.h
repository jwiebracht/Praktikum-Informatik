/*
 * Verhalten.h
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_
#include <memory>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
#include <list>

class Weg;

class Fahrzeug;

class Verhalten {
public:
	Verhalten() = delete;
	Verhalten(Weg& weg);

	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) = 0;
	Weg& getWeg();

	virtual ~Verhalten();

protected:
	Weg& aktuellerWeg;
};

#endif /* VERHALTEN_H_ */
