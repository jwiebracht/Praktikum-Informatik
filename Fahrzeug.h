/*
 * Fahrzeug.h
 *
 *  Created on: 15.10.2024
 *      Author: jonas
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <iostream>
#include <string>
#include <iomanip>

extern double dGlobaleZeit;

class Fahrzeug {
public:
	Fahrzeug();
	Fahrzeug(std::string p_sName);
	Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);
	static void vKopf();
	virtual void vAusgeben(std::ostream& out) const;
	virtual void vSimulieren();
	virtual void dTanken(double dMenge) = 0;
	virtual double dGeschwindigkeit() const = 0;
	virtual ~Fahrzeug();

private:
	 static int p_iMaxID;
	 const int ID;

protected:
	 std::string p_sName;
	 double p_dGesamtStrecke = 0.0;
	 double p_dGesamtZeit = 0.0;
	 double p_dMaxGeschwindigkeit;
	 double p_dZeit = 0.0;
};
std::ostream& operator<<(std::ostream& out, const Fahrzeug& fahrzeug);

#endif /* FAHRZEUG_H_ */
