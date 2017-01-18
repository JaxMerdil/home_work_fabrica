#include <iostream>

using namespace std;

class Device
{
public:
    string m_firm;
    bool m_indicator;
    string m_model;
    Device()
        : m_firm("N/A")
        , m_indicator(0)
        , m_model("N/A")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Device(string firm, bool indicator, string model)
        : m_firm(firm)
        , m_indicator(indicator)
        , m_model(model)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    virtual ~Device()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void TurnOn()
    {
        m_indicator=true;
    }
    void TurnOff()
    {
        m_indicator=false;
    }
    virtual  void GetStatus()const=0;
};

class Printer  : public virtual Device
{
public:
    unsigned int m_ppm; // к-во печати страниц в минуту
    Printer (unsigned int ppm)
        : m_ppm(ppm)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Printer (string firm, bool indicator, string model, unsigned int ppm)
        : Device(firm, indicator, model)
        , m_ppm(ppm)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~Printer()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void Print()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void GetStatus() const override
    {
        cout << "Firm printer " << m_firm
             << ", model " << m_model
             << ", ppm: " << m_ppm
             << ", status " << m_indicator
             << endl;
    }
};

class Scanner : public virtual Device
{
public:
    unsigned int m_scanSpeed; // скорость сканирования
    Scanner(unsigned int scanSpeed)
        : m_scanSpeed(scanSpeed)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Scanner(string firm, bool indicator, string model, unsigned int scanSpeed)
        : Device(firm, indicator, model)
        , m_scanSpeed(scanSpeed)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~Scanner()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void Scann()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void GetStatus() const override
    {
        cout << "Firm scanner " << m_firm
             << ", model " << m_model
             << ", scan speed: " << m_scanSpeed
             << ", status " << m_indicator
             << endl;
    }
};

class MFU :  public Printer,  public Scanner
{
public:
    MFU(string firm, bool indicator, string model, unsigned int ppm, unsigned int scanSpeed)
        : Device(firm, indicator, model)
        , Printer (ppm)
        , Scanner(scanSpeed)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void Print()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void Scann()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void GetStatus() const override
    {
        cout << "Firm MFU " << m_firm
             << ", model " << m_model
             << ", ppm: " << m_ppm
             << ", scan speed: " << m_scanSpeed
             << ", status " << m_indicator
             << endl;
    }
};

int main()
{
    Printer p1("HP",false,"Deskjet 6120",21);
    p1.TurnOn(); // вкл устр., смена инд.
    p1.GetStatus();
    cout << "--------------------------------------------------------" << endl;
    Scanner s1("Canon",false,"MP 150",6);
    s1.GetStatus();
    cout << "--------------------------------------------------------" << endl;
    MFU m1("HP",false,"Deskjet F2483",17,8);
    m1.TurnOn(); // вкл устр., смена инд.
    m1.GetStatus();
    cout << "--------------------------------------------------------" << endl;
    return 0;
}
