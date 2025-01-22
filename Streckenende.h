/*
 * Streckenende.h
 *
 *  Created on: 18.01.2025
 *      Author: Jonas
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme{
public:
	Streckenende() = delete;
	Streckenende(Fahrzeug& fahrzeug, Weg& weg);

	void vBearbeiten();

	virtual ~Streckenende();
};

#endif /* STRECKENENDE_H_ */
