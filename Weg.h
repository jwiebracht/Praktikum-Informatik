/*
 * Weg.h
 *
 *  Created on: 17.01.2025
 *      Author: jonas
 */

#ifndef WEG_H_
#define WEG_H_
#include "Simulationsobjekt.h"
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include "Fahrzeug.h"

class Weg : public Simulationsobjekt{
public:
	Weg() = delete;
	Weg(std::string p_sName);
	virtual ~Weg();

private:
	double p_dLaenge;
	std::unique_ptr<std::list<Fahrzeug>> p_pFahrzeuge;
	double p_eMaxGeschwindigkeit;

};

#endif /* WEG_H_ */
