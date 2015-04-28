////
////  main.cpp
////  HW3
////
////  Created by WangSiwen on 15-4-28.
////  Copyright (c) 2015年 WangSiwen. All rights reserved.
////
//
//#include <iostream>
//#include <string>
//using namespace std;
//class Animal{
//public:
//    Animal(){};
//    virtual ~Animal(){};
//    virtual string name()const=0;
//    virtual string moveAction()const=0;
//    virtual void speak()const=0;
//private:
//};
//class Cat:public Animal
//{
//public:
//    Cat(string cur_n):catname(cur_n){catvoice="Meow";cataction="Walk";};
//    Cat(string cur_n,string cur_a):catname(cur_n),cataction(cur_a){catvoice="Meow";};
//    ~Cat(){cout<<"Destroying "<<catname<<" the cat"<<endl;};
//    string name()const{return catname;}
//    string moveAction()const{return cataction;}
//    void speak()const{cout<<catvoice;}
//private:
//    string catname;
//    string catvoice;
//    string cataction;
//};
//class Duck:public Animal
//{
//public:
//    Duck(string cur_n):duckname(cur_n){duckvoice="Quack";duckaction="Swim";};
//    Duck(string cur_n,string cur_a):duckname(cur_n),duckaction(cur_a){duckvoice="Quack";};
//    ~Duck(){cout<<"Destroying "<<duckname<<" the duck"<<endl;};
//    string name()const{return duckname;}
//    string moveAction()const{return duckaction;}
//    void speak()const{cout<<duckvoice;}
//private:
//    string duckname;
//    string duckvoice;
//    string duckaction;
//};
//
//class Pig:public Animal
//{
//public:
//    Pig(string cur_n,int cur_w):pigname(cur_n),weight(cur_w)
//    {
//        if (weight<180) {
//            pigvoice="Oink";
//        }
//        else
//        {
//            pigvoice="Grunt";
//        }
//        pigaction="Walk";
//    }
//    Pig(string cur_n,string cur_a,int cur_w):pigname(cur_n),pigaction(cur_a),weight(cur_w)
//    {
//        if (weight<180) {
//            pigvoice="Oink";
//        }
//        else
//        {
//            pigvoice="Grunt";
//        }
//    }
//    ~Pig(){cout<<"Destroying "<<pigname<<" the pig"<<endl;};
//    string name()const{return pigname;}
//    string moveAction()const{return pigaction;}
//    void speak()const{cout<<pigvoice;}
//private:
//    string pigname;
//    string pigvoice;
//    string pigaction;
//    int weight;
//};
//void animate(const Animal* a)
//{
//    a->speak();
//    cout << "!  My name is " << a->name()
//    << ".  Watch me " << a->moveAction() << "!\n";
//}
//
//int main()
//{
//    Animal* animals[4];
//    animals[0] = new Cat("Fluffy");
//    // Pigs have a name and a weight in pounds.  Pigs under 180
//    // pounds oink; pigs weighing at least 180 pounds grunt.
//    animals[1] = new Pig("Napoleon", 190);
//    animals[2] = new Pig("Wilbur", 50);
//    animals[3] = new Duck("Daffy");
//    
//    cout << "Here are the animals." << endl;
//    for (int k = 0; k < 4; k++)
//    animate(animals[k]);
//    
//    // Clean up the animals before exiting
//    cout << "Cleaning up." << endl;
//    for (int k = 0; k < 4; k++)
//    delete animals[k];
//}
