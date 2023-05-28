#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int s1 = 1; //global variable specified for the location.
int s2 = 2;
int s3 = 3;
//Below is a class where file handling has been depicted.
class FileHandler {
private:
    fstream file;

public:
    FileHandler(string filename) { //calling parameterized constructor
        file.open(filename, ios::out | ios::in | ios::trunc);/*The file is opened with
        multiple modes specified using three ios (Input/Output Stream) flags.*/
        if (!file.is_open()) {
            cerr << "Failed to open the file." << endl;//If file is unable to be opened, error message printed to stnd. error stream
        }
    }

    void writeToFile(string content) {
        if (file.is_open()) {
            file << content; /* To write the content string to the file using the << operator,
             which is overloaded for file streams to write data.*/
            file.flush();// To flush the file buffer to ensure written content is immediately saved to file
    }
}

    string readFromFile() {
        string content;
        if (file.is_open()) {
            file.seekg(0, ios::beg);// Here file position indicator is set to the start of file.
            content.assign(istreambuf_iterator<char>(file), istreambuf_iterator<char>());/*file materials read and assigned to
            content string using istreambuf_iterator*/
        }
        return content;
    }

    void closeFile() {
        if (file.is_open()) {
            file.close();
        }
    }
};

class emergency_service //parent class for the project.
{
protected:
    int  type;   //Two class member variables have been encapsulated
    int location;
public:
    emergency_service(int type , int location){}
    virtual void show_details_mirpur()=0;      //Three pure virtual function as means of abstraction
    virtual void show_details_cantonment()=0;
    virtual void show_details_motijheel()=0;
};
class Ambulance:public emergency_service //class Ambulance publicly inherits parent class
{
    public:
        Ambulance(int type , int location):emergency_service(type , location){}

       //The pure virtual functions(declared in the parent class) are defined below :
            void show_details_mirpur()
            {
                cout<<"\t\t Ambulance is available in mirpur.\n \t\tName: RED CROSS " <<endl;
                cout<<"\t\t keypad dialler: 101"<<endl;
                cout<< "\t\t cell phone: 01962579496"<<endl;
                cout<< "\t\t email: RED_CROSS_atyourservice@gmail.com"<<endl;
                cout<< "\t\t eqipments available: first aid box,scissors,oxygen cylinder, bandage , sedatives.\n\n"<<endl;
            }
             void show_details_cantonment()
            {
                cout<<"\t\t Ambulance is  available in cantonment.\n\t\t Name: NEW VISION " <<endl;
                cout<<"\t\t keypad dialler: 102"<<endl;
                cout<< "\t\t cell phone: 01962579496"<<endl;
                cout<< "\t\t email: NEW_VISION_atyourservice@gmail.com"<<endl;
                cout<< "\t\t eqipments available: first aid box,scissors, bandage , oxygen cylinder,sedatives.\n\n"<<endl;
            }
             void show_details_motijheel()
            {
                cout<<"\t\t Ambulance is available in motijheel.\n \t\tName: Bnevolent soul " <<endl;
                cout<<"\t\t Keypad dialler: 103"<<endl;
                cout<< "\t\t cell phone: 01962579496"<<endl;
                cout<< "\t\t email: Benevolent_Soul_atyourservice@gmail.com"<<endl;
                cout<< "\t\t eqipments available: first aid box,bandage , scissors,oxygen cylinder,sedatives.\n\n"<<endl;
            }



};

class firetruck:public emergency_service //class firetruck publicly inherits parent class
{
    public:
        firetruck(int type , int location):emergency_service(type , location){}
          //The pure virtual functions(declared in the parent class) are defined below :
            void show_details_mirpur()
            {
                cout<<"\t\t firetruck is available in mirpur .\n\t\t Name: Agnibina  " <<endl;
                cout<<"\t\t keypad dialer: 201"<<endl;
                cout<< "\t\t cell phone: 01662570996"<<endl;
                cout<< "\t\t email: agnibina@gmail.com"<<endl;
                cout<<"\t\t equipments available: ladders,fire hoases, foam , nozzles, extinguisher"<<endl;
                cout<<"\t\t Water tank capacity : 5000L\n\n"<<endl;
            }
             void show_details_cantonment()
            {
                cout<<"\t\t firetruck is available in cantonment.\t Name: Naya  Diganta" <<endl;
                cout<<"\t\t keypad dialer: 202"<<endl;
                cout<< "\t\t cell phone: 01662578490"<<endl;
                cout<< "\t\t email: naya_diaganta@gmail.com"<<endl;
                cout<<"\t\t equipments available: ladders,fire hoases, foam , nozzles, extinguisher"<<endl;
                cout<<"\t\t Water tank capacity : 3000\n\n"<<endl;
            }
             void show_details_motijheel()
            {
                cout<<"\t\t firetruck is available in motijheel.\t Name: obokash" <<endl;
                cout<<"\t\t keypad dialer: 203"<<endl;
                cout<< "\t\t cell phone: 01662572580"<<endl;
                cout<< "\t\t email: obokash@gmail.com"<<endl;
                cout<<"\t\t equipments available: ladders,fire hoases, foam , nozzles, extinguisher"<<endl;
                cout<<"\t\t Water tank capacity : 4000L\n\n"<<endl;
            }



};


class police:public emergency_service  //class police publicly inherits parent class
{
    public:
        police(int type , int location):emergency_service(type , location){}
        //The pure virtual functions(declared in the parent class) are defined below :
            void show_details_mirpur()
            {
                cout<<"\t\t Police personel is available in mirpur . " <<endl;
                cout<<"\t\t keypad dialler : 301"<<endl;
                cout<< "\t\t cell phone: 01962579496"<<endl;
                cout<< "\t\t email: police_at_mirpur@gmail.comn\n\n"<<endl;
            }
             void show_details_cantonment()
            {
                cout<<"\t\t Police personel is available in cantonment." <<endl;
                cout<<"\t\t keypad dialler : 302"<<endl;
                cout<< "\t\t cell phone: 01542525896"<<endl;
                cout<< "\t\t email: police_at_cantonment@gmail.com\n\n"<<endl;
            }
            void show_details_motijheel()
            {
                cout<<"\t\t Police personel is available in motijheel." <<endl;
                cout<<"\t\t keypad dialler : 303"<<endl;
                cout<< "\t\t cell phone: 01543219496"<<endl;
                cout<< "\t\t email: police_at_motijheel@gmail.com\n\n"<<endl;
            }



};

class rescue_platoon:public emergency_service  //class rescue_platoon publicly inherits parent class
{
    public:
        rescue_platoon(int type , int location):emergency_service(type , location){}
        //The pure virtual functions(declared in the parent class) are defined below :
            void show_details_mirpur()
            {
                cout<<"\t\t Rescue platoon is available in mirpur . " <<endl;
                cout<<"\t\t keypad dialer: 401"<<endl;
                cout<< "\t\t cell phone: 01757907956"<<endl;
                cout<< "\t\t email: orchid_astra_revolt@gmail.com\n\n"<<endl;
            }
             void show_details_cantonment()
            {
                cout<<"\t\t Rescue platoon is available in cantonment." <<endl;
                cout<<"\t\t keypad dialer: 402"<<endl;
                cout<< "\t\t cell phone: 01742579496"<<endl;
                cout<< "\t\t email: rapid_batallion_@gmail.com\n\n"<<endl;
            }
            void show_details_motijheel()
            {
                cout<<"\t\t Rescue platoon is available in motijheel." <<endl;
                cout<<"\t\t keypad dialer: 403"<<endl;
                cout<< "\t\t cell phone: 01712098946"<<endl;
                cout<< "\t\t email: charismatic_endeavours@gmail.com\n\n"<<endl;
            }



};

class overload      //class made to depict operator overloading
{
public:
    void operator<< (string line) // The << operator has been overloaded
    {
        cout<< line << endl;
    }

    void memfunc()
    {
        overload over;
        over << "Enter your location:\tPress 1 for mirpur"; //To directly output the string using << operator
        over << "\t\t\tPress 2 for cantonment";
        over << "\t\t\tPress 3 for motijheel";
    }
};

inline void advice(int a) //an inline function to pass message
{
    if(a==1){cout<<"You can call ambulance through the info provided below:"<<endl;}
    if(a==2){cout<<"You can call Fireservice through the info provided below:"<<endl;}
    if(a==3){cout<<"You can call police through the info provided below:"<<endl;}
    if(a==4){cout<<"You can call rescue platoon through the info provided below:"<<endl;}
}

int main()
 {
    int location;
    int type;
    FileHandler handler("emergency.txt");
    handler.writeToFile("Welcome to the project.\nThis service , for the time being , is only available for the inhabitants of mirpur,cantonment & motijheel.");
    handler.writeToFile("\n Press 1 for ambulance.\n Press 2 for firetruck.\nPress 3 for calling police\nPress 4 for calling rescue team\nPress any number other than 1/2/3/4  to exit\n");

    string content = handler.readFromFile();
    cout << "File content: " << content << endl;

    handler.closeFile();
    vector<emergency_service*> emer; //vector emer will hold pointers to object of class emergency_service
    overload over; //object of class overloading has been declared.
    do
    {cout<<"Enter the type\n";
    cin>>type;
    if(type == 1)
        { over.memfunc(); //memfunc() of class overload is called
    cin>>location;
    emer.push_back(new Ambulance(type,location));//To dynamically create new object of class ambulance
   if ((location==1) || (location==2) || (location==3)) advice(type); //the inline function called here
    for (auto emergency : emer)//loop to iterate over the elements of container emer and each elem assigned to emergency variable
        {
        if(location == s1){emergency-> show_details_mirpur(); //calling member function through 'emergency' pointer
                           cout<<endl;}
        else if(location == s2){ emergency-> show_details_cantonment();cout<<endl;}
        else if(location == s3){ emergency-> show_details_motijheel();cout<<endl;}
        else{cout<<"Enter only 1/2/3 for your location. Try again"<<endl;}
    }
    for (auto emergency : emer) {
        delete emergency; //to deallocate memory pointed by emergency pointer.
    }
    emer.clear(); //to clear 'emer'container removing all its elements
    }
   else if(type == 2) {over.memfunc();//memfunc() of class overload is called
    cin>>location;
    emer.push_back(new firetruck(type,location)); //To dynamically create new object of class firetruck
    if ((location==1) || (location==2) || (location==3)) advice(type); //the inline function called here
    for (auto emergency : emer) //loop to iterate over the elements of container emer and each elem assigned to emergency variable
        {
        if(location == s1){emergency-> show_details_mirpur(); //calling member function through 'emergency' pointer
                           cout<<endl;}
        else if(location == s2){ emergency-> show_details_cantonment();cout<<endl;}
        else if(location == s3){ emergency-> show_details_motijheel();cout<<endl;}
        else{cout<<"Enter only 1/2/3 for your location. Try again"<<endl;}
    }
    for (auto emergency : emer) {
        delete emergency;  //to deallocate memory pointed by emergency pointer.
    }
    emer.clear();//to clear 'emer'container removing all its elements
    }

    else if(type==3){over.memfunc(); //memfunc() of class overload is called
    cin>>location;
    emer.push_back(new police(type,location)); //To dynamically create new object of class police
    if ((location==1) || (location==2) || (location==3)) advice(type); //the inline function called here
    for (auto emergency : emer) //loop to iterate over the elements of container emer and each elem assigned to emergency variable
        {
        if(location == s1){emergency-> show_details_mirpur(); //calling member function through 'emergency' pointer
                           cout<<endl;}
        else if(location == s2){ emergency-> show_details_cantonment();cout<<endl;}
        else if(location == s3) { emergency-> show_details_motijheel();cout<<endl;}
        else{cout<<"Enter only 1/2/3 for your location. Try again"<<endl;}
    }
    for (auto emergency : emer) {
        delete emergency;  //to deallocate memory pointed by emergency pointer.
    }
    emer.clear();  //to clear 'emer'container removing all its elements
    }

    else if(type==4){over.memfunc(); //memfunc() of class overload is called
    cin>>location;
    emer.push_back(new rescue_platoon(type,location)); //To dynamically create new object of class rescue _platoon
   if ((location==1) || (location==2) || (location==3)) advice(type); //the inline function called here
    for (auto emergency : emer) //loop to iterate over the elements of container emer and each elem assigned to emergency variable
        {
        if(location == s1){emergency-> show_details_mirpur(); //calling member function through 'emergency' pointer
                           cout<<endl;}
        else if(location == s2){ emergency-> show_details_cantonment();cout<<endl;}
        else if(location == s3) { emergency-> show_details_motijheel();cout<<endl;}
        else{cout<<"Enter only 1/2/3 for your location. Try again"<<endl;}
    }
    for (auto emergency : emer) {
        delete emergency;  //to deallocate memory pointed by emergency pointer.
    }
    emer.clear(); //to clear 'emer'container removing all its elements
    }
    }
    while((type==1) || (type==2) || (type==3) || (type==4) );
    return 0;
}
