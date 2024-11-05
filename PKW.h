/*
 * PKW.h
 *
 *  Created on: 23.10.2024
 *      Author: Jonas
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"
#include <iostream>

class PKW : public Fahrzeug{
public:
	PKW();
	PKW(std::string p_sName, double p_dMaxGeschwindigkeit, double p_dVerbrauch);//Konstruktor ohne optionalen Tankinhalt
	PKW(std::string p_sName, double p_dMaxGeschwindigkeit, double p_dVerbrauch, double p_dTankvolumen);
	void dTanken(double dMenge) override;
	void vSimulieren() override;
	static void vKopf();
	void vAusgeben(std::ostream& out) const override;
	double dGeschwindigkeit() const override;
	virtual ~PKW();

private:
	double p_dVerbrauch;
	double p_dTankvolumen;
	double p_dTankinhalt;
};

#endif /* PKW_H_ */
