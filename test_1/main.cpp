#include <iostream>

using namespace std;

class HTMLElement
{
public:
    unsigned Width() const;
    unsigned Height() const;
    bool Hidden() const;
    virtual string Render()=0;
};

class HTMLButtonElement: public HTMLElement
{

public:
    const string& Title() const;
    string Render() override
    {
        return "<button>title-of-the-button</button>";
    }
};
class HTMLImageElement: public HTMLElement
{
public:
    const string& Url() const;
    string Render() override
    {
        return "<img src=\"../../smiley.gif\" height=\"42\" width=\"42\">";
    }
};
class HTMLTextAreaDocument: public HTMLElement
{
string m_str;
public:
    const string& Content() const;
    string Render() override
    {
        return "<textarea> \n content-of-the-text-area \n </textarea>";


    }
};


int main()
{
     const int nObj=3;
     HTMLElement* HT[nObj];
     HT[0] = new HTMLButtonElement();
     cout << "String HTMLButtonElement: " << HT[0]->Render() << endl;
     HT[1] = new HTMLImageElement();
     cout << "String HTMLImageElement: " << HT[1]->Render() << endl;
     HT[2] = new HTMLTextAreaDocument();
     cout << "String HTMLTextAreaDocument: " << HT[2]->Render() << endl;
    return 0;
}
