#pragma once

#include <list>
#include "memory"
#include "vertagt_aktion.h"

namespace vertagt
{
	template <class T>
	class VListe
	{
	private:
		std::list<T> p_objekte; //Die Objekte
		std::list<std::unique_ptr<VAktion<T>>> p_aktionen; // Die Aktionen Liste, von welcher die Aktionen ausgeführt werden, von Typ VAktion<T>

	public:
		// Typdefinitionen
		using iterator = typename std::list<T>::iterator;
		using const_iterator = typename std::list<T>::const_iterator;

		// Konstruktoren
		VListe() = default; // Benötigt man einen Standardkonstruktor?
		// Destruktor
		~VListe()
		{
			vAktualisieren();
			p_objekte.clear(); // Im Destruktor alle Elemente leeren
		}

		void clear()
		{
			p_objekte.clear(); // Objekte werden geleert
		}

		// Lesefunktionen
		const_iterator begin() const // gibt einen Iterator zurück, der auf das erste Element zeigt
		{
			return p_objekte.begin();
		}
		const_iterator end() const // gibt einen Iterator zurück, der hinter das letzte Element zeigt
		{
			 return p_objekte.end();
		}
		iterator begin() // gibt einen Iterator zurück, der auf das erste Element zeigt
		{
			return p_objekte.begin();
		}
		iterator end() //gibt einen Iterator zurück, der hinter das letzte Element zeigt
		{
			return p_objekte.end();
		}
		bool empty() const // gibt zurück, ob das Objekt keine Elemente enthält
		{
			return p_objekte.empty();
		}

		// Schreibfunktionen
		void push_back(T obj) //fügt obj am Ende ein
		{
			// Aktionselement für PushBack auf Liste erzeugen
			p_aktionen.push_back(std::make_unique<VPushBack<T>>(p_objekte,std::move(obj)));
		}

		void push_front(T obj) //fügt obj vor dem ersten Element ein
		{
			// Aktionselement für PushFront auf Liste erzeugen
			p_aktionen.push_back(std::make_unique<VPushFront<T>>(p_objekte,std::move(obj)));
		}


		void erase(iterator it) //löscht das Element an Position it
		{
			// Aktionselement für Erase auf Liste erzeugen (hier Iterator statt Objekt !)
			p_aktionen.push_back(std::make_unique<VErase<T>>(p_objekte, it));
		}

		// Änderungen auf Objektliste übertragen

		void vAktualisieren() //aktualisiert p_objekte
		{
			while (!p_aktionen.empty()) // Aktionen müssen nur ausgeführt werden, wenn welche vorhanden sind. Wenn Liste leer ist gibt es keine Aktionen mehr zu machen
			{
				// Aktionszeiger auf 1. Element bestimmen
				std::unique_ptr <VAktion<T>> p_aktion = std::move(*(p_aktionen.begin()));

				// Aktion ausführen
				p_aktion->vAusfuehren(); //Oberste Aktion wird ausgeführt
				p_aktionen.pop_front(); //Wenn Aktion ausgeführt von oben löschen, damit nächste behandelt werdne kann ->Stack Prinzip

			}
			p_aktionen.clear(); // Liste leeren
		}
	};
} // namespace vertagt

