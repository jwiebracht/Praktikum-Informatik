#pragma once

#include <list>

namespace vertagt
{
	// Oberklasse VAktion
	template <class T>
	class VAktion // Die Aktion klasse
	{
	protected:
		std::list<T>& p_pListe;  // Zeiger auf Liste der Objekte

	public:
	    //VAktion() = ...; // Benötigt man einen Standardkonstruktor? Nein
		VAktion(std::list<T>& ptListe) : p_pListe(ptListe){}
		virtual ~VAktion() = default;
		virtual void vAusfuehren() = 0;
	};


	// PushBack
	template <class T>
	class VPushBack : public VAktion<T>
	{
	private:
		T p_objekt; // Push Back Objekte

	public:
		VPushBack(std::list<T>& liste, T obj) : VAktion<T>(liste), p_objekt(std::move(obj))	{}
		virtual ~VPushBack() = default;
		void vAusfuehren() override
		{
			VAktion<T>::p_pListe.push_back(std::move(p_objekt)); //Objekt wird unten angehangen
		}
	};

	// PushFront
	template <class T>
	class VPushFront : public VAktion<T>
	{
	private:
		T p_objekt; // Push Front Objekte

	public:
		VPushFront(std::list<T>& liste, T obj) : VAktion<T>(liste), p_objekt(std::move(obj)){}
		virtual ~VPushFront() = default;
		void vAusfuehren() override
		{
			VAktion<T>::p_pListe.push_front(std::move(p_objekt)); //Objekt wird oben hinzugefügt
		}
	};

	// Erase
	template <class T>
	class VErase : public VAktion<T> //Die Aktion Löschen als Klasse; Generische Klasse Aktion
	{
	public:
		using iterator = typename std::list<T>::iterator; // Der Iterator von Txp des Lists Iterator

	private:
		iterator p_it;  // bei erase Iterator speichern

	public:
		VErase(std::list<T>& liste, iterator& it) : VAktion<T>(liste), p_it(it){}
		virtual ~VErase() = default; // Defailt Destruktor
		void vAusfuehren() override
		{
			VAktion<T>::p_pListe.erase(p_it);
		}
	};
}  // namespace vertagt

