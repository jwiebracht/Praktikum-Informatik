/*
 * Fahren.h
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#ifndef FAHREN_H_
#define FAHREN_H_
#include "Verhalten.h"

class Fahren : public Verhalten{
public:
	Fahren() = delete;
	Fahren(Weg& weg);

	double dStrecke(Fahrzeug& aFzg,double dZeitIntervall);

	virtual ~Fahren();
};

#endif /* FAHREN_H_ */
