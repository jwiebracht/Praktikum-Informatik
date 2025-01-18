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
#include <iomanip>
#include "Fahrzeug.h"

enum class p_eTempolimit{Innerorts = 50,
	Ausserorts = 100,
	Autobahn = std::numeric_limits<int>::max()};

class Weg : public Simulationsobjekt{
public:
	Weg();
	Weg(std::string p_sName, double p_dLaenge);
	Weg(std::string p_sName, double p_dLaenge, p_eTempolimit limit);
	void vSimulieren();
	static void vKopf();
	void vAusgeben(std::ostream& out) const override;

	double getTempolimit();

	virtual ~Weg();

private:
	double p_dLaenge;
	std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	p_eTempolimit tempolimit;

};

#endif /* WEG_H_ */
