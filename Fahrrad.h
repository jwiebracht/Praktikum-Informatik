/*
 * Fahrrad.h
 *
 *  Created on: 23.10.2024
 *      Author: Jonas
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug{
public:
	Fahrrad();
	Fahrrad(std::string p_sName, double p_dMaxGeschwindigkeit);
	double dGeschwindigkeit() const override;
	void dTanken(double dMenge) override;
	virtual ~Fahrrad();
};

#endif /* FAHRRAD_H_ */
