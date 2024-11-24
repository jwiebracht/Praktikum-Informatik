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

extern double dGlobaleZeit;

class Fahrzeug {
public:
	Fahrzeug();
	Fahrzeug(std::string p_sName);
	Fahrzeug(std::string p_sName, double p_dMaxGeschwindigkeit);

	Fahrzeug(const Fahrzeug&) = delete;
	Fahrzeug& operator=(const Fahrzeug& rhs);

	static void vKopf();
	virtual void vAusgeben(std::ostream& out) const;
	virtual void vSimulieren();
	virtual double dTanken(double dMenge = 0.0) = 0;
	virtual double dGeschwindigkeit() const = 0;
	static std::string generateRandomName();
	virtual std::unique_ptr<Fahrzeug> fahrzeugErstellen() = 0;
	double getGesamtStrecke() const;
	std::string getName() const;
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
bool operator< (const Fahrzeug& lhs, const Fahrzeug& rhs);

#endif /* FAHRZEUG_H_ */
