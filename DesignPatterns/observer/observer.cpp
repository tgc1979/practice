#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Subject;

class Observer
{
public:
 virtual void Notify(const Subject *news)=0;
//const virtual void Notify(const Subject *news)=0;

};





class Subject
{

vector < class Observer * > observerCollection; // 3. Coupled only to "interface"
string news;
public:

Subject(){};

 string GetNews ()const
{
    return news;
}

void Register(Observer *observerInstance)
{
    observerCollection.push_back(observerInstance);
}
void Unregister(Observer *observerInstance)
{
}
void NotifyObservers()
{

 for (Observer * n : observerCollection) {
        n->Notify(this);
    }
}
void SetNews(string somethingHappened , bool isBreakingNews)
{

    news = somethingHappened;
    if(isBreakingNews)
    {
        NotifyObservers();
    }
}
};

class Facebook: public Observer
{
public:
 void Notify(const Subject *news)
//const void Notify(const Subject *news)
{
cout << "Facebook Breaking News:\n"<< news->GetNews() <<"\n";
}

};

class Twitter : public Observer
{

void Notify(const Subject *news)
//const void Notify(const Subject *news)
{
cout << "Twitter Breaking News:\n"<< news->GetNews() <<"\n";

}
};
int main()
{
    Facebook fb;
    Twitter tw;
    Subject cnn;

    cnn.Register(&fb);
    cnn.Register(&tw);
    cnn.SetNews("Volcanic eruption in Turkey",true);
    cnn.SetNews("Rain expected in Sussex",false);

    cout << "hello world1\n";

    return 0;
}