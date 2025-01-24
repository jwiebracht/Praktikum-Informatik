/*
 * Fahrzeug.h
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <memory>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
#include <list>
#include "Simulationsobjekt.h"
#include "SimuClient.h"
#include "Verhalten.h"
#include "Fahren.h"
#include "Parken.h"

extern double dGlobaleZeit;

class Fahrzeug : public Simulationsobjekt{
public:
	Fahrzeug() = delete;
	Fahrzeug(std::string p_sName);
	Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);

	Fahrzeug(const Fahrzeug&) = delete;
	Fahrzeug& operator=(const Fahrzeug& rhs);

	void vAusgeben(std::ostream& out) const override;
	virtual void vSimulieren();
	virtual double dTanken(double dMenge = 0.0) = 0;
	virtual double dGeschwindigkeit() const = 0;
	static std::string generateRandomName();
	virtual std::unique_ptr<Fahrzeug> fahrzeugErstellen() = 0;
	void vNeueStrecke(Weg&);
	void vNeueStrecke(Weg& weg, double dStartzeit);
	virtual void vZeichnen(Weg& weg) const;
	virtual double getTankvolumen() = 0;
	virtual double getTankinhalt() = 0;

	double getGesamtStrecke() const;
	double getMaxGeschwindigkeit();
	double getTeilstrecke();

	virtual ~Fahrzeug();

protected:
	 double p_dGesamtStrecke = 0.0;
	 double p_dGesamtZeit = 0.0;
	 double p_dMaxGeschwindigkeit;
	 std::unique_ptr<Verhalten> p_pVerhalten;
	 double p_dAbschnittStrecke = 0;
};

bool operator< (const Fahrzeug& lhs, const Fahrzeug& rhs);

#endif /* FAHRZEUG_H_ */
