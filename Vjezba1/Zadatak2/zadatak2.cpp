#include <iostream>
#include <string>

using namespace std;

typedef struct student {
	int kviz_1, kviz_2, kviz_3, kviz_4, polugodiste, finalno, uk_br_bodova;
	string id, ime, prezime;
	char spol;
	student* next;
}student;

student *pronadi_po_id(student *popis_studenata)
{
	string tmp_id;
	cout << "upisi ID" << endl;
	cin >> tmp_id;
	student *tmp;
	while (popis_studenata != NULL)
	{
		if (popis_studenata->id.compare(tmp_id) == 0)
		{
			tmp = popis_studenata;
			return tmp;
		}
		popis_studenata = popis_studenata->next;
	}
	return NULL;
}

student *dodaj_studenta(student *popis_studenata, int &kapacitet)
{
	if (kapacitet >= 20)
	{
		cout << "lista je popunjena";
		return popis_studenata;
	}
	string tmp_id;
	student *tmp = new student;
	student *p = popis_studenata;
	cout << "unesite ID" << endl;
	cin >> tmp_id;

	while (p != NULL)
	{
		if (p->id.compare(tmp_id) == 0)
		{
			cout << "ID vec postoji, unesite ponovo";
			cin >> tmp_id;
			p = popis_studenata;
		}
		p = p->next;
	}
	tmp->id = tmp_id;
	cout << "unesite ime" << endl;
	cin >> tmp->ime;
	cout << "unesite prezime" << endl;
	cin >> tmp->prezime;
	cout << "unesite spol (m ili z)" << endl;
	cin >> tmp->spol;
	tmp->kviz_1 = 0;
	tmp->kviz_2 = 0;
	tmp->kviz_3 = 0;
	tmp->kviz_4 = 0;
	tmp->polugodiste = 0;
	tmp->finalno = 0;
	tmp->uk_br_bodova = 0;
	tmp->next = popis_studenata;
	popis_studenata = tmp;
	kapacitet++;
	return popis_studenata;
}

student *ukloni_studenta(student *popis_studenata, int &kapacitet)
{
	if (popis_studenata == NULL)
	{
		cout << "lista je vec prazna";
		return popis_studenata;
	}
	string tmp_id;
	cout << "upisite ID studenta kojeg zelite izbrisat";
	cin >> tmp_id;
	if (popis_studenata->id.compare(tmp_id) == 0) {
		student *tmp = popis_studenata;
		popis_studenata = popis_studenata->next;
		kapacitet--;
		delete tmp;
		return popis_studenata;
	}
	while (popis_studenata->next != NULL)
	{
		if (popis_studenata->next->id.compare(tmp_id) == 0)
		{
			student *tmp = popis_studenata->next;
			popis_studenata->next = popis_studenata->next->next;
			delete tmp;
			kapacitet--;
			return popis_studenata;
		}
		popis_studenata = popis_studenata->next;
	}
	cout << "taj ID ne postoji";
	return popis_studenata;
}

void izracunaj_prosjek_polugodista(student *popis_studenata)
{
	if (popis_studenata == NULL)
		return;
	while (popis_studenata != NULL)
	{
		popis_studenata->polugodiste = (popis_studenata->kviz_1 + popis_studenata->kviz_2) / 2;
		popis_studenata = popis_studenata->next;
	}
}

void izracunaj_finalnu_ocjenu(student *popis_studenata)
{
	if (popis_studenata == NULL)
		return;
	while (popis_studenata != NULL)
	{
		popis_studenata->finalno = (popis_studenata->kviz_1 + popis_studenata->kviz_2 + popis_studenata->kviz_3 + popis_studenata->kviz_4) / 4;
		popis_studenata = popis_studenata->next;
	}
}

void izracunaj_uk_br_bodova(student *popis_studenata)
{
	if (popis_studenata == NULL)
		return;
	while (popis_studenata != NULL)
	{
		popis_studenata->uk_br_bodova = popis_studenata->kviz_1 + popis_studenata->kviz_2 + popis_studenata->kviz_3 + popis_studenata->kviz_4 + popis_studenata->polugodiste + popis_studenata->finalno;
		popis_studenata = popis_studenata->next;
	}
}

void azuriraj_zapis(student *popis_studenata)
{
	string tmp;
	string tmp_id;
	cout << "upisite ID";
	cin >> tmp_id;
	cout << "sto zelite azurirati: ime, prezime, kviz_1, kviz_2, kviz_3, kviz_4";
	cin >> tmp;
	while (popis_studenata != NULL)
	{
		if (popis_studenata->id.compare(tmp_id) == 0)
		{
			if (tmp.compare("ime") == 0)
				cin >> popis_studenata->ime;
			else if (tmp.compare("prezime") == 0)
				cin >> popis_studenata->prezime;
			else if (tmp.compare("kviz_1") == 0)
			{
				cin >> popis_studenata->kviz_1;
				izracunaj_prosjek_polugodista(popis_studenata);
			}
			else if (tmp.compare("kviz_2") == 0)
			{
				cin >> popis_studenata->kviz_2;
				izracunaj_prosjek_polugodista(popis_studenata);
			}
			else if (tmp.compare("kviz_3") == 0)
			{
				cin >> popis_studenata->kviz_3;
				izracunaj_finalnu_ocjenu(popis_studenata);
			}
			else if (tmp.compare("kviz_4") == 0)
			{
				cin >> popis_studenata->kviz_4;
				izracunaj_finalnu_ocjenu(popis_studenata);
			}
			izracunaj_uk_br_bodova(popis_studenata);
			return;
		}
		popis_studenata = popis_studenata->next;
	}
	cout << "taj ID ne postoji";
}

void student_sa_najmanjim_br_bodova(student *popis_studenata)
{
	if (popis_studenata == NULL)
	{
		cout << "lista je prazna";
		return;
	}
	student *tmp = popis_studenata;
	int br_bodova = popis_studenata->uk_br_bodova;
	while (popis_studenata != NULL)
	{
		if (popis_studenata->uk_br_bodova < br_bodova)
		{
			br_bodova = popis_studenata->uk_br_bodova;
			tmp = popis_studenata;
		}
		popis_studenata = popis_studenata->next;
	}
	cout << "student sa najmanjim brojem bodova" << " " << tmp->id << "  " << tmp->ime << "  " << tmp->prezime << "  " << tmp->uk_br_bodova << endl;
}

void student_sa_najvecim_br_bodova(student *popis_studenata)
{
	if (popis_studenata == NULL)
	{
		cout << "lista je prazna";
		return;
	}
	student *tmp = popis_studenata;
	int br_bodova = popis_studenata->uk_br_bodova;
	while (popis_studenata != NULL)
	{
		if (popis_studenata->uk_br_bodova > br_bodova)
		{
			br_bodova = popis_studenata->uk_br_bodova;
			tmp = popis_studenata;
		}
		popis_studenata = popis_studenata->next;
	}
	cout << "student sa najvecim brojem bodova" << " " << tmp->id << "  " << tmp->ime << "  " << tmp->prezime << "  " << tmp->uk_br_bodova << endl;
}

student *sortiraj_po_br_bodova(student *popis_studenata)
{
	student *sortirani_popis_studenata = NULL;
	student *tmp = popis_studenata;
	student *p = popis_studenata;
	student *tmp2 = popis_studenata;
	while (p != NULL)
	{
		while (p->next != NULL)
		{
			if (p->next->uk_br_bodova > tmp->uk_br_bodova)
			{
				tmp2 = p;
				tmp = p->next;
			}
			p = p->next;
		}
		if (tmp == tmp2) {
			popis_studenata = popis_studenata->next;
			tmp->next = sortirani_popis_studenata;
			sortirani_popis_studenata = tmp;
		}
		else {
			tmp2->next = tmp2->next->next;
			tmp->next = sortirani_popis_studenata;
			sortirani_popis_studenata = tmp;
		}
		p = popis_studenata;
		tmp = popis_studenata;
		tmp2 = popis_studenata;
	}
	return sortirani_popis_studenata;
}

void prikazi_sve_zapise(student *popis_studenata)
{
	if (popis_studenata == NULL)
	{
		cout << "lista je prazna";
		return;
	}
	while (popis_studenata != NULL)
	{
		cout << "ID" << "-" << popis_studenata->id << "   " << "ime" << "-" << popis_studenata->ime << "   " << "prezime" << "-" << popis_studenata->prezime << "   " << "spol" << "-" << popis_studenata->spol << "   " << "kviz 1" << "-" << popis_studenata->kviz_1 << "   " << "kviz 2" << "-" << popis_studenata->kviz_2 << "   " << "kviz 3" << "-" << popis_studenata->kviz_3 << "   " << "kviz 4" << "-" << popis_studenata->kviz_4 << "   " << "polugodiste" << "-" << popis_studenata->polugodiste << "   " << "finalna ocjena" << "-" << popis_studenata->finalno << "   " << "ukupan br bodova" << "-" << popis_studenata->uk_br_bodova << endl;
		popis_studenata = popis_studenata->next;
	}
}

int main()
{
	student *popis_studenata = NULL;
	int kapacitet = 0;
	string upis;
	while (upis.compare("kraj") != 0)
	{
		cout << "\ndodaj_studenta, ukloni_studenta, azuriraj_zapis, prikazi_sve_zapise, sortiraj, student_sa_najmanjim_br_bodova, student_sa_najvecim_br_bodova, pronadi_po_id, kraj?" << endl;
		cin >> upis;
		if (upis.compare("dodaj_studenta") == 0)
			popis_studenata = dodaj_studenta(popis_studenata, kapacitet);
		else if (upis.compare("ukloni_studenta") == 0)
			popis_studenata = ukloni_studenta(popis_studenata, kapacitet);
		else if (upis.compare("azuriraj_zapis") == 0)
			azuriraj_zapis(popis_studenata);
		else if (upis.compare("prikazi_sve_zapise") == 0)
			prikazi_sve_zapise(popis_studenata);
		else if (upis.compare("student_sa_najmanjim_br_bodova") == 0)
			student_sa_najmanjim_br_bodova(popis_studenata);
		else if (upis.compare("student_sa_najvecim_br_bodova") == 0)
			student_sa_najvecim_br_bodova(popis_studenata);
		else if (upis.compare("sortiraj") == 0)
			popis_studenata = sortiraj_po_br_bodova(popis_studenata);
		else if (upis.compare("pronadi_po_id") == 0)
		{
			student *tmp = pronadi_po_id(popis_studenata);
			cout << "ID" << "-" << tmp->id << "   " << "ime" << "-" << tmp->ime << "   " << "prezime" << "-" << tmp->prezime << "   " << "spol" << "-" << tmp->spol << "   " << "kviz 1" << "-" << tmp->kviz_1 << "   " << "kviz 2" << "-" << tmp->kviz_2 << "   " << "kviz 3" << "-" << tmp->kviz_3 << "   " << "kviz 4" << "-" << tmp->kviz_4 << "   " << "polugodiste" << "-" << tmp->polugodiste << "   " << "finalna ocjena" << "-" << tmp->finalno << "   " << "ukupan br bodova" << "-" << tmp->uk_br_bodova << endl;
		}
	}
	student *tmp2;
	while (popis_studenata != NULL)
	{
		tmp2 = popis_studenata;
		popis_studenata = popis_studenata->next;
		delete tmp2;
	}
	system("pause");
}