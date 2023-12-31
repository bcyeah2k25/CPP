/*32.Create two classes DM and DB, which store the value of distances. DM stores distances in
meters and centimeters and DB in feet and inches. Write a program that can read values for
the class objects and add one object of DM with another object of DB. Use a friend function
to carry out addition operation. The object that stores the result may be a DM object or DB
object, depending on the units in which the results are required. The display should be in
the format of feet and inches or meters and centimeters depending on the object on display.*/


#include <iostream>
using namespace std;

class DB;

class DM {
    int meters;
    int centimeters;

public:
    DM() : meters(0), centimeters(0) {}

    void readData() {
        cout << "Enter distance in meters: ";
        cin >> meters;
        cout << "Enter distance in centimeters: ";
        cin >> centimeters;
    }

    void displayData() const {
        cout << "\nDistance: " << meters << " meters, " << centimeters << " centimeters" << endl;
    }

    friend DM addDistanceC(const DM& dm, const DB& db);
    friend DB addDistanceF(const DM& dm, const DB& db);
};

class DB {
    int feet;
    int inches;

public:
    DB() : feet(0), inches(0) {}

    void readData() {
        cout << "Enter distance in feet: ";
        cin >> feet;
        cout << "Enter distance in inches: ";
        cin >> inches;
    }

    void displayData() const {
        cout << "\nDistance: " << feet << " feet, " << inches << " inches" << endl;
    }

    friend DM addDistanceC(const DM& dm, const DB& db);
    friend DB addDistanceF(const DM& dm, const DB& db);
};

DM addDistanceC(const DM& dm, const DB& db) {
    DM result;
    int totalCentimeters = dm.meters * 100 + dm.centimeters + (db.feet * 12 + db.inches) * 2.54;
    result.meters = totalCentimeters / 100;
    result.centimeters = totalCentimeters % 100;
    return result;
}

DB addDistanceF(const DM& dm, const DB& db){
    
    DB result;
    int totalCentimeters = dm.meters * 100 + dm.centimeters + (db.feet * 12 + db.inches) * 2.54;
    int totalInches =  totalCentimeters *0.393701;

    int totalFeet = totalInches / 12;
    totalInches =  totalInches % 12; 

    result.feet = totalFeet;
    result.inches = totalInches;

    return result;
    
}

int main() {
    DM dm;
    DB db;


    cout << "Enter distance in meters and centimeters:-"<< endl<<endl;
    dm.readData();

    cout << "\n\nEnter distance in feet and inches:-"<<endl<< endl;
    db.readData();

    int ch;
    do{

        cout<<"\n\nIn which format do you want answer "<<endl
            <<"1.Meters and Centimeter "<<endl
            <<"2.Feet and Inches"<<endl
            <<"0.Exit"<<endl
            <<"Enter your choice : ";
        cin>>ch;

        switch(ch){

            case 1 : {
                DM result = addDistanceC(dm,db);
                cout<<"\nSum of Distances : ";
                result.displayData();
                break;
            }
            case 2:{
                DB result = addDistanceF(dm,db);
                cout<<"\nSum of Distances : ";
                result.displayData();
                break;
            }
            case 0: exit(0) ; break;
            default:{
                cout<<"Invalid Choice !";
                break;
            }
        }

    }while(ch!=0);

    return 0;
}
