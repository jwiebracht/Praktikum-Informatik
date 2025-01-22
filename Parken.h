/*
 * Parken.h
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#ifndef PARKEN_H_
#define PARKEN_H_
#include "Verhalten.h"

class Weg;

class Parken : public Verhalten{
public:
	Parken() = delete;
	Parken(Weg& weg, double startZeitpunkt);

	double dStrecke(Fahrzeug& aFzg,double dZeitIntervall);

	virtual ~Parken();

private:
	double dStartZeitpunkt;
	bool losgefahren;
};

#endif /* PARKEN_H_ */
