#include<iostream>
#include<string>
using namespace std;

class Printer
{
private:
    string name;
    int availablePaper;

public:
    Printer(string _name,int _num)
    {
        name = _name;
        availablePaper = _num;
    }

    void Print(string text)
    {
        int requiredPaper = text.length()/5;

        if(requiredPaper > availablePaper)
        {
            //throw "No paper!";
            throw 101;

        }
        cout << "Printing " << text << endl;
        availablePaper -= requiredPaper;
    }

};

int main()
{
    Printer p("Diskjet",10);
    try
    {
        p.Print("Hello! My name is Anuvab and I do astrophysics!");
        p.Print("Hello! My name is Anuvab and I do astrophysics!");
    }

    catch(const char* textException)
    {
        cout << "Exception: " << textException << endl;
    }

//catch(int Excode){
//cout << "Exception: " << Excode << endl;
//}

    catch(...)
    {
        cout << "Exception happened!"<< endl;
    }
}
