#include <iostream>
#include <vector>

using namespace std;

class Candidat
{
protected:
    float media;
    int nrInregistrare; //cod dosar
    string codLegitimatie;
    string nume;
    float mediaBAC;
public:
    friend istream& operator>>(istream&, Candidat& ob);
    //virtual float calcMedia();
friend class facultate;
};


istream& operator>>(istream& in, Candidat& ob)
{
cout<<"Numele: ";
in>>ob.nume;
cout<<endl;
cout<<"mendia Bac: ";
in>>ob.mediaBAC;
return in;
}

class CandidatFac2: public Candidat
{
private:
    string PDSabsolvit;
    string diploma;
    float probaOrala;
    float nota_absolvire;
public:
    friend istream& operator>>(istream&, CandidatFac2& ob);
    CandidatFac2(string,float);
    friend ostream& operator<<(ostream& out, CandidatFac2& ob );
};

/*float CandidatFac2::calcMedia()
{
media=(0.6*ProbaOrala)+0.4*(nota_absolvire);
} */

CandidatFac2::CandidatFac2(string Nume, float bac)
{
nume=Nume;
mediaBAC=bac;
}

istream& operator>>(istream& in, CandidatFac2& ob)
{
cout<<"Optati pentru a 2-a facultate, ce PDS  ati absolvit? ";
in>>ob.PDSabsolvit;
cout<<"numele diplomei: ";
in>>ob.diploma;
cout<<"proba orala nota: "<<endl;
in>>ob.probaOrala;
cout<<"absolvire nota: "<<endl;
in>>ob.nota_absolvire;
cout<<endl;
ob.codLegitimatie="ID2_";
return in;
}

class CandidatIF: public Candidat
{
private:
    float notaPScrisa;
public:
    friend istream& operator>>(istream&, CandidatIF& ob);
    CandidatIF(string,float);
    friend ostream& operator<<(ostream& out, CandidatIF& ob );
};

/*float candidatIF::calcMedia()
{
media=0.8*notaPscrisa+0.2*mediaBAC;
} */

 ostream& operator<<(ostream& out, CandidatIF& ob )
 {
 out<<"numele: "<<ob.nume<<endl;
 out<<"media bac: "<<ob.mediaBAC<<endl;
 out<<"nota Proba scrisa: "<<ob.notaPScrisa<<endl;
 out<<"nr Intregistr: "<<ob.nrInregistrare;
 out<<"nr legitimatie: "<<ob.codLegitimatie<<ob.nrInregistrare<<endl;
 return out;
 }

istream& operator>>(istream& in, CandidatIF& ob)
{
cout<<"nota proba scrisa: ";
in>>ob.notaPScrisa;
cout<<endl;
ob.codLegitimatie=ob.nrInregistrare;
return in;
}

CandidatIF::CandidatIF(string Nume, float bac)
{
nume=Nume;
mediaBAC=bac;
}

class CandidatID: public Candidat
{
private:
    float mediaBACmate;
    float probaOrala;
public:
    friend istream& operator>>(istream&, CandidatID& ob);
    CandidatID(string,float);
    friend ostream& operator<<(ostream& out, CandidatID& ob );
};

 ostream& operator<<(ostream& out, CandidatID& ob )
 {
 out<<"numele: "<<ob.nume<<endl;
 out<<"media bac: "<<ob.mediaBAC<<endl;
 out<<"nota Proba orala: "<<ob.probaOrala<<endl;
 out<<"Nota bac mate: "<<ob.mediaBACmate<<endl;
 out<<"nr Intregiste: "<<ob.nrInregistrare<<endl;
 out<<"nr legitimatie: "<<ob.codLegitimatie<<ob.nrInregistrare<<endl;
 return out;
 }

CandidatID::CandidatID(string Nume, float bac)
{
nume=Nume;
mediaBAC=bac;
}

istream& operator>>(istream& in, CandidatID& ob)
{
cout<<"media bac mate: ";
in>>ob.mediaBACmate;
cout<<"proba orala nota: "<<endl;
in>>ob.probaOrala;
cout<<endl;
ob.codLegitimatie="ID_";
return in;
}

class facultate
{
private:
    int nr_locuri;
    int nr_locuri_taxa;
    int IF;
    int ID;
    int procentTaxa;
    vector<CandidatIF> v1;
    vector<CandidatID> v2;
    vector<CandidatFac2> v3;
    int n;
public:
    void citire_facultate();
    void add_candidat();
    void afisare_cand();
};

void facultate::afisare_cand()
{
cout<<"nr de cand inscrisi la IF: "<<v1.size()<<endl;
cout<<"nr de cand inscrisi la ID: "<<v1.size()<<endl;
cout<<"candidatii inscrisi la IF: "<<endl;
for (int i=0;i<v1.size();i++)
    {
    cout<<v1[i];
    }
cout<<"candidatii inscrisi la ID: "<<endl;
for (int i=0;i<v1.size();i++)
    cout<<v2[i];
}

void facultate::citire_facultate()
{
cout<<"introduceti nr de locuri IF:"<<endl;
cin>>IF;
cout<<"introduceti nr de locuri ID:"<<endl;
cin>>ID;
cout<<"procentul de taxa: "<<endl;
nr_locuri=IF+ID;
nr_locuri_taxa=nr_locuri*procentTaxa/100;
n=0;
cout<<endl;
}

void facultate::add_candidat()
{
bool IF,ID,fac2;
cout<<"Candidatul este la IF? 1/0"<<endl;
    cin>>IF;
cout<<"Candidatul este la ID? 1/0"<<endl;
    cin>>ID;
cout<<"Candidatul este la fac2? 1/0"<<endl;
    cin>>fac2;
cout<<"introduceti numele cand.";
string nume;
float mediabac;
cout<<"numele: ";
cin>>nume;
cout<<"media bac: ";
cin>>mediabac;
if (IF==1)
    {
    cout<<"introduceti datele cand.  pt IF"<<endl;
    CandidatIF cand1(nume,mediabac);
    cin>>cand1;
    v1.push_back(cand1);
    }
if (ID==1)
    {
    cout<<"introduceti datele cand. pt ID"<<endl;
    CandidatID cand2(nume,mediabac);
    cin>>cand2;
    v2.push_back(cand2);
    }
if (fac2==1)
    {
    cout<<"introduceti datele cand. pt fac2"<<endl;
    CandidatFac2 cand3(nume,mediabac);
    cin>>cand3;
    v3.push_back(cand3);
    }
}

int main()
{
facultate fac1;
fac1.add_candidat();
fac1.afisare_cand();
return 0;
}
