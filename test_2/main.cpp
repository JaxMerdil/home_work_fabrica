#include <iostream>

using namespace std;

class HTMLElement
{
public:
    unsigned Width() const;
    unsigned Height() const;
    bool Hidden() const;
    virtual ~HTMLElement(){}
    virtual string Render() = 0;
    virtual HTMLElement* Duplicate() = 0;
};

class HTMLButtonElement : public HTMLElement
{
public:
    const string& Title() const;
    string Render() override{
        return "<button>title-of-the-button</button> \n";
    }
    HTMLElement* Duplicate()
    {
        return new HTMLButtonElement(*this);
    }
};

class HTMLImageElement : public HTMLElement
{
public:
    const string& Url() const;
    string Render() override{
        return "<img src=\"../../smiley.gif\" height=\"42\" width=\"42\"> \n";
    }
    HTMLElement* Duplicate()
    {
        return new HTMLImageElement(*this);
    }
};

class HTMLTextAreaDocument : public HTMLElement
{
public:
    const string& Content() const;
    string Render() override{
        return "<textarea>\ncontent-of-the-text-area\n</textarea>";
    }
    HTMLElement* Duplicate()
    {
        return new HTMLTextAreaDocument(*this);
    }
};


int main()
{
    const int nObj=6;
    HTMLElement* HT[nObj];
    HT[0] = new HTMLButtonElement();
    cout << "String HTMLButtonElement: " << HT[0]->Render();
    HT[1] = new HTMLImageElement();
    cout << "String HTMLImageElement: " << HT[1]->Render();
    HT[2] = new HTMLTextAreaDocument();
    cout << "String HTMLTextAreaDocument: \n" << HT[2]->Render() << endl;
    cout<<"------------------------------------------------------------------------"<<endl;
//-----------------------------------------------------------------------------------------
    HT[3] = new HTMLImageElement();
    HT[4] = new HTMLImageElement();
    HT[5] = new HTMLImageElement();
//-----------------------------------------------------------------------------------------
    HT[3]->Duplicate();
    HT[4]->Duplicate();
    HT[5]->Duplicate();
//-----------------------------------------------------------------------------------------
    cout << "String Duplicate HTMLButtonElement: " << HT[3]->Render();
    HT[4] = new HTMLImageElement();
    cout << "String Duplicate HTMLImageElement: " << HT[4]->Render();
    HT[5] = new HTMLTextAreaDocument();
    cout << "String Duplicate HTMLTextAreaDocument: \n" << HT[5]->Render() << endl;
//-----------------------------------------------------------------------------------------
    return 0;
}
