#include <iostream>

using namespace std;

class A{

public:
    A(){
        cout<<"s-a construit a"<<"\n";
    }

    virtual ~A(){
        cout<<"s-a distrus a"<<"\n";
    }

    void SetStatus(string newstatus)
    {
        status=newstatus;
    }

    string GetStatus(){
        return status;
    }

private:
    string status;
};

class B: public A{
public :
    B(){
        cout<<"s a construit b"<<"\n";
    }

    ~B(){
        cout<<"s a distrus b"<<"\n";
    }
};

class printable
{

    virtual void drawme()=0;
};

class shape: public printable
{

};

class square: public shape
{

};
int main()
{

   /* A a1;
    B b1;
    a1.SetStatus("da");
    cout<<"status: "<<a1.GetStatus()<<"\n";
    cout<<sizeof(A)<<"\n";
    cout<<sizeof(B)<<"\n";
    */

    A* a2=new A();
    B* b2=new B();

    a2->SetStatus("status a");
    b2->SetStatus("status b");
    cout<<a2->GetStatus()<<"\n";
    cout<<b2->GetStatus()<<"\n";

    delete a2;
    delete b2;


    return 0;
}
