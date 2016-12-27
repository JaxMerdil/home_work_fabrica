#include <iostream>

using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------

class HTMLElement
{
unsigned m_width;
unsigned m_height;
bool m_hidden;
public:
    HTMLElement (unsigned width, unsigned heigth, bool hidden): m_width(width), m_height(heigth), m_hidden(hidden){}
    unsigned Width() const
    {
        return m_width;
    }
    unsigned Height() const
    {
        return m_height;
    }
    bool Hidden() const
    {
        return m_hidden;
    }
    virtual string Render()=0;
    virtual ~HTMLElement(){}
};

//---------------------------------------------------------------------------------------------------------------------------------------

class HTMLButtonElement: public HTMLElement
{
string m_button;
public:
    HTMLButtonElement(const string& str,unsigned width,unsigned height,bool hidden): HTMLElement(width,height,hidden), m_button(str){}
    const string& Title() const
    {
        return  m_button;
    }
    string Render() override
    {
        return "\n<button>" + m_button + "</button>";
    }
};

//---------------------------------------------------------------------------------------------------------------------------------------

class HTMLImageElement: public HTMLElement
{
    string m_image;
public:
    HTMLImageElement(const string& str,unsigned width,unsigned height,bool hidden): HTMLElement(width,height,hidden), m_image(str){}
    const string& Url() const
    {
        return m_image;
    }
    string Render() override
    {
        return "\n<img src=''../../" + m_image + "'' height=''" + to_string(Height())+"'' "+ "width=''"+to_string(Width())+"'' "+">";
    }
};

//---------------------------------------------------------------------------------------------------------------------------------------

class HTMLTextAreaElement: public HTMLElement
{
    string m_content;
public:
    HTMLTextAreaElement(const string& str,unsigned width,unsigned height,bool hidden): HTMLElement(width,height,hidden), m_content(str){}
    const string& Content() const
    {
        return m_content;
    }
    string Render() override
    {
        return "\n<textarea>\n" + m_content + "\n" + "</textarea>\n";
    }
};

//---------------------------------------------------------------------------------------------------------------------------------------

int main()
{
     const int nObj=3;
     HTMLElement* HT[nObj];
     HT[0] = new HTMLButtonElement("title-of-the-button",100,30,true);
     cout << "String HTMLButtonElement: " << HT[0]->Render() << endl;
     HT[1] = new HTMLImageElement("img.jpg",800,640,true);
     cout << "String HTMLImageElement: " << HT[1]->Render() << endl;
     HT[2] = new HTMLTextAreaElement("content-of-the-text-area",100,30,true);
     cout << "String HTMLTextAreaDocument: " << HT[2]->Render() << endl;
    return 0;
}
