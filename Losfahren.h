/*
 * Losfahren.h
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme{
public:
	Losfahren() = delete;
	Losfahren(Fahrzeug& fahrzeug, Weg& weg);

	void vBearbeiten();

	virtual ~Losfahren();
};

#endif /* LOSFAHREN_H_ */
