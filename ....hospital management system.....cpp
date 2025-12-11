#include <iostream>
#include <string>
#include <iomanip>//using this for tools like set width and left and right
#include <cstdlib>//using this for clear screen and exit 
using namespace std;
// function of main choice and subchoice is basically to let user pick from menu(mainchoice)and then after that from sub category(subchoice)
int mainChoice, subChoice;
// Function use for clear screen and exit
void clearScreen() {
    #ifdef _WIN32
        system("cls");//cls is only use for windows
    #else
        system("clear");//while clear is use in mac or linux
    #endif
}
// Function to convert int to string manually
string intToString(int num) {
    if(num == 0) return "0";//this will return 0
    string result = "";//this is left empty so that we can store our answer
    bool negative = false;
    if(num < 0) {
        negative = true;
        num = -num;
    }
    while(num > 0) {
        result = char('0' + num % 10) + result;
        num /= 10;
    }
    if(negative) result = "-" + result;
    return result;
}
// Function to convert string to int manually
int stringToInt(string str) {
    int result = 0;
    bool negative = false;
    int start = 0;
    
    if(str[0] == '-') {
        negative = true;
        start = 1;
    }
    for(int i = start; i < str.length(); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
    }
    if(negative) result = -result;
    return result;
}
// Login system
bool login() {
    string username, password;
    int attempts = 3;
    while(attempts > 0) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "               HOSPITAL LOGIN SYSTEM" << endl;
        cout << "========================================================" << endl;
        cout << "Attempts remaining: " << attempts << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        if(username == "citygeneral_hospital" && password == "cy1_2025") {
            return true;
        } else {
            cout << "\nInvalid username or password!" << endl;
            attempts--;
            if(attempts > 0) {
                cout << "Press Enter to try again...";
                cin.ignore();
                cin.get();
            }
        }
    }
    cout<<"\nMaximum login attempts exceeded!"<<endl;
    cout<<"System will now exit."<<endl;
    return false;
}//using structures
struct MedicalHistory {//structure use for medical history
    string date;
    string diagnosis;
    string treatment;
    string notes;
};
struct Billing {//structure use for billing
    int consultationFee;
    int testCost;
    int medicineCost;
    int roomCharges;
    int daysAdmitted;
    int roomTotal;
    int totalBill;
    string paymentMethod;
};
struct EmergencyContact {//structure use for emergency contact
    string name;
    string number;
    string relation;
};
struct Patient 
{//structure use for patient 
    string name;
    int age;//enter patient age
    string gender;//enter patient gender
    string contact;//enter patient contact
    string sickness;//enter patient sickness
    string patientType;//enter patient type whether indoor or outdoor
    int id;// patient id number example 1001
    string cnic;//enter patient cnic
    string bloodGroup;//enter patient blood group
    string roomType;//enter patient room type
    string testName;//enter test names
    string doctorName;//choose doctor whether senior or junior
    string doctorLocation;//doctor location
    bool discharged;//bool use to tell if patient is still admitted and not discharge(false) or patient has been discharged(true)
    EmergencyContact emergency;//use of nested structure
    Billing bill;//use of nested structure
    MedicalHistory history[10];//array to hold up to 10 medical history records
    int historyCount;//this tells us how much of the array is being used
};
struct Doctor{
    string name;
    string speciality;
    int fee;
    string location;
// constructor
    Doctor(){
        name="";
        speciality="";
        fee=0;
        location="";
    }
//parametarized constructor
    Doctor(string n, string s, int f, string l) {
        name=n;//n=name
        speciality=s;//s=speciality
        fee=f;//f=fee
        location=l;//l=location
    }
};
struct Room {
    string typeName;
    int price;
    string features;
    int available;
    int total;
//Constructor 
    Room() {
        typeName="";
        price=0;
        features="";
        available=0;
        total=0;
    }
//parametarized constructor
    Room(string tn, int p, string f, int a, int t) {
        typeName=tn;//tn=typeName
        price=p;//p=price
        features=f;//f=features
        available=a;//a=available
        total=t;//t=total
    }
};
struct Medicine {
    string name;
    int price;
    string category;
    int stock;
// Constructor
    Medicine(){
        name="";
        price=0;
        category="";
        stock = 0;
    }
//parametarized constructor    
    Medicine(string n, int p, string c, int s) {
        name=n;//n=name
        price=p;//p=price
        category=c;//c=category
        stock=s;//s=stock
    }
};
struct Test {
    string name;
    int price;
    string duration;
// Constructor
    Test(){
        name="";
        price=0;
        duration="";
    }
//parametarized constructor    
    Test(string n, int p, string d) {
        name = n;//n=name
        price = p;//p=price
        duration = d;//d=duration
    }
};
// Arrays
Doctor seniorDoctors[20];
Doctor juniorDoctors[20];
Room rooms[10];
Test tests[6];
Medicine medicines[50];
Patient patients[50];
string categories[20] = {"Headache", "Fever", "Cough", "Stomach", "Diabetes",
                        "Pressure", "Allergy", "Infection", "Pain", "Vitamin"};
//counters
int seniorDoctorCount = 10;
int juniorDoctorCount = 10;
int roomCount = 5;
int medicineCount = 30;
int categoryCount = 10;
int patientCount = 0;
int patientCounter = 1001;
// Initializing
void initializeArrays() {
// Senior Doctors(with the help of constructor)
    seniorDoctors[0] = Doctor("Dr. Ahmed Khan", "Cardiologist", 3500, "3rd Floor, Room 301");
    seniorDoctors[1] = Doctor("Dr. Sarah Ali", "Neurologist", 3500, "4th Floor, Room 405");
    seniorDoctors[2] = Doctor("Dr. Hassan Raza", "Orthopedic Surgeon", 3000, "2nd Floor, Room 210");
    seniorDoctors[3] = Doctor("Dr. Zainab Hussain", "General Surgeon", 3000, "3rd Floor, Room 315");
    seniorDoctors[4] = Doctor("Dr. Imran Malik", "Gastroenterologist", 3200, "4th Floor, Room 412");
    seniorDoctors[5] = Doctor("Dr. Ayesha Tariq", "Gynecologist", 3500, "5th Floor, Room 502");
    seniorDoctors[6] = Doctor("Dr. Bilal Ahmed", "Pulmonologist", 3300, "3rd Floor, Room 308");
    seniorDoctors[7] = Doctor("Dr. Nida Rashid", "Endocrinologist", 3400, "4th Floor, Room 420");
    seniorDoctors[8] = Doctor("Dr. Usman Javaid", "Urologist", 3200, "2nd Floor, Room 215");
    seniorDoctors[9] = Doctor("Dr. Saba Qadir", "Oncologist", 4000, "5th Floor, Room 510");
//Junior Doctors(with the help of constructor)
    juniorDoctors[0] = Doctor("Dr. Fatima Malik", "General Physician", 1500, "1st Floor, Room 105");
    juniorDoctors[1] = Doctor("Dr. Usman Shah", "Pediatrician", 1800, "1st Floor, Room 112");
    juniorDoctors[2] = Doctor("Dr. Ayesha Siddiqui", "Dermatologist", 1800, "2nd Floor, Room 205");
    juniorDoctors[3] = Doctor("Dr. Ali Raza", "ENT Specialist", 2000, "1st Floor, Room 118");
    juniorDoctors[4] = Doctor("Dr. Hina Zahid", "Psychiatrist", 2200, "4th Floor, Room 408");
    juniorDoctors[5] = Doctor("Dr. Kamran Haider", "Dentist", 1700, "Ground Floor, Room 15");
    juniorDoctors[6] = Doctor("Dr. Mariam Asif", "Ophthalmologist", 1900, "2nd Floor, Room 220");
    juniorDoctors[7] = Doctor("Dr. Faisal Iqbal", "Rheumatologist", 2000, "3rd Floor, Room 312");
    juniorDoctors[8] = Doctor("Dr. Saira Khan", "Allergist", 1800, "1st Floor, Room 120");
    juniorDoctors[9] = Doctor("Dr. Waqas Ahmed", "Physiotherapist", 1600, "Ground Floor, Room 8");
//Rooms(with the help of constructor )
    rooms[0] = Room("General Ward", 2000, "Shared, Basic", 20, 20);
    rooms[1] = Room("Semi-Private Room", 4000, "2 Beds, AC, TV", 10, 10);
    rooms[2] = Room("Private Room", 6000, "Single, AC, TV", 8, 8);
    rooms[3] = Room("Deluxe Room", 9000, "Luxury", 5, 5);
    rooms[4] = Room("ICU", 12000, "Critical Care", 4, 4);
//Medical Tests(with the help of constructor)
    tests[0] = Test("Blood Test", 1500, "30 mins");
    tests[1] = Test("X-Ray", 2500, "15 mins");
    tests[2] = Test("Ultrasound", 3500, "20 mins");
    tests[3] = Test("CT Scan", 8000, "45 mins");
    tests[4] = Test("MRI", 15000, "1 hour");
    tests[5] = Test("ECG + Echo", 5000, "40 mins");
// Medicines(with the help of constructor)
    medicines[0] = Medicine("Panadol", 50, "Headache", 100);
    medicines[1] = Medicine("Brufen", 80, "Headache", 80);
    medicines[2] = Medicine("Disprin", 40, "Headache", 50);
    medicines[3] = Medicine("Paracetamol", 50, "Fever", 120);
    medicines[4] = Medicine("Calpol Syrup", 120, "Fever", 40);
    medicines[5] = Medicine("Aspirin", 60, "Fever", 90);
    medicines[6] = Medicine("Benadryl Syrup", 150, "Cough", 60);
    medicines[7] = Medicine("Actifed", 90, "Cough", 70);
    medicines[8] = Medicine("Corex Syrup", 130, "Cough", 55);
    medicines[9] = Medicine("Omeprazole", 100, "Stomach", 85);
    medicines[10] = Medicine("Risek", 120, "Stomach", 65);
    medicines[11] = Medicine("Gaviscon Syrup", 200, "Stomach", 45);
    medicines[12] = Medicine("Glucophage", 180, "Diabetes", 50);
    medicines[13] = Medicine("Diamicron", 250, "Diabetes", 40);
    medicines[14] = Medicine("Insulin", 800, "Diabetes", 20);
    medicines[15] = Medicine("Concor", 220, "Pressure", 75);
    medicines[16] = Medicine("Losar", 190, "Pressure", 80);
    medicines[17] = Medicine("Norvasc", 240, "Pressure", 70);
    medicines[18] = Medicine("Cetirizine", 70, "Allergy", 90);
    medicines[19] = Medicine("Avil", 60, "Allergy", 85);
    medicines[20] = Medicine("Montair", 150, "Allergy", 60);
    medicines[21] = Medicine("Augmentin", 350, "Infection", 35);
    medicines[22] = Medicine("Ciproxin", 280, "Infection", 40);
    medicines[23] = Medicine("Azithromycin", 300, "Infection", 38);
    medicines[24] = Medicine("Tramadol", 120, "Pain", 45);
    medicines[25] = Medicine("Ponstan", 90, "Pain", 55);
    medicines[26] = Medicine("Voltaren", 110, "Pain", 50);
    medicines[27] = Medicine("Centrum", 400, "Vitamin", 70);
    medicines[28] = Medicine("Vitamin D3", 250, "Vitamin", 60);
    medicines[29] = Medicine("Calcium", 180, "Vitamin", 65);
}
//Menu
void displayMainMenu() {
    cout << "\n========================================================" << endl;//using new line
    cout << "           CITY GENERAL HOSPITAL 24/7" << endl;
    cout << "           Hospital Management System       " << endl;
    cout << "========================================================\n" << endl;
    // First module
    cout << "1.  View Doctors List" << endl;
    cout << "2.  View Pharmacy Medicines & Stock" << endl;
    cout << "3.  Doctor Management" << endl;
    cout << "4.  Medicine Management" << endl;
    cout << "--------------------------------------------------------" << endl;
    // Second module
    cout << "5.  Register New Patient" << endl;
    cout << "6.  Room Management" << endl;
    cout << "7.  Update Patient Information" << endl;
    cout << "8.  View All Patient Records" << endl;
    cout << "--------------------------------------------------------" << endl;
    // Third module
    cout <<  "9.  View Room Availability" << endl;
    cout <<  "10. Discharge Patient" << endl;
    cout <<  "11. Edit Patient Bill" << endl;
    cout <<  "12. Category Management" << endl;
    cout <<  "13. Patient Medical History" << endl;
    cout <<  "14. Exit" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "\nEnter your choice: ";
}
void displayDoctors() {
    cout << "\n========================================================" << endl;
    cout << "                    DOCTORS LIST" << endl;
    cout << "========================================================\n" << endl;
    cout << "*** SENIOR DOCTORS ***" << endl;
    cout << left << setw(5) << "No." << setw(25) << "Name"
         << setw(25) << "Speciality" << setw(12) << "Fee" << "Location" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < seniorDoctorCount; i++) {
        cout << left << setw(5) << (i+1) << setw(25) << seniorDoctors[i].name 
             << setw(25) << seniorDoctors[i].speciality << setw(12) << ("Rs." + intToString(seniorDoctors[i].fee)) 
             << seniorDoctors[i].location << endl;
    }
    cout << "\n*** JUNIOR DOCTORS ***" << endl;
    cout << left << setw(5) << "No." << setw(25) << "Name" 
         << setw(25) << "Speciality" << setw(12) << "Fee" << "Location" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < juniorDoctorCount; i++) {
        cout << left << setw(5) << (i+1) << setw(25) << juniorDoctors[i].name 
             << setw(25) << juniorDoctors[i].speciality << setw(12) << ("Rs." + intToString(juniorDoctors[i].fee)) 
             << juniorDoctors[i].location << endl;
    }
}

void displayPharmacy() {
    cout << "\n========================================================" << endl;
    cout << "           PHARMACY MEDICINES & STOCK STATUS" << endl;
    cout << "========================================================\n" << endl;
    cout << left << setw(5) << "ID" << setw(20) << "Medicine" 
         << setw(15) << "Category" << setw(12) << "Price" 
         << "Stock" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < medicineCount; i++) {
        cout << left << setw(5) << (i+1) << setw(20) << medicines[i].name 
             << setw(15) << medicines[i].category << setw(12) << ("Rs." + intToString(medicines[i].price));
        if(medicines[i].stock < 20) {
            cout << intToString(medicines[i].stock) << " (LOW!)" << endl;
        } else {
            cout << medicines[i].stock << endl;}
        }
    }

void displayRoomAvailability() {
    cout << "\n========================================================" << endl;
    cout << "              ROOM AVAILABILITY STATUS" << endl;
    cout << "========================================================\n" << endl;
    cout << left << setw(5) << "No." << setw(22) << "Room Type"
         << setw(15) << "Price/Day" << setw(12) << "Available" 
         << "Features" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    for(int i = 0; i < roomCount; i++) {
        cout << left << setw(5) << (i+1) << setw(22) << rooms[i].typeName 
             << setw(15) << ("Rs." + intToString(rooms[i].price)) 
             << setw(12) << (intToString(rooms[i].available) + "/" + intToString(rooms[i].total));
        if(rooms[i].available == 0) {
            cout << "FULL - " << rooms[i].features << endl;
        } else {
            cout << rooms[i].features << endl;}
        }
    }

void suggestMedicines(string sickness) {
    cout << "\n========================================================" << endl;
    cout << "           PHARMACY - RECOMMENDED MEDICINES" << endl;
    cout << "========================================================\n" << endl;
    cout << "Based on: " << sickness << endl;
    cout << "--------------------------------------------------------\n" << endl;
    string lowerSickness = sickness;
    for(int i = 0; i < lowerSickness.length(); i++) {
        lowerSickness[i] = tolower(lowerSickness[i]);
    }
    bool found = false;
    string category = "";
    if(lowerSickness.find("headache") != string::npos) category = "Headache";
    else if(lowerSickness.find("fever") != string::npos) category = "Fever";
    else if(lowerSickness.find("cough") != string::npos) category = "Cough";
    else if(lowerSickness.find("cold") != string::npos) category = "Cough";
    else if(lowerSickness.find("stomach") != string::npos) category = "Stomach";
    else if(lowerSickness.find("diabetes") != string::npos) category = "Diabetes";
    else if(lowerSickness.find("pressure") != string::npos) category = "Pressure";
    else if(lowerSickness.find("allergy") != string::npos) category = "Allergy";
    else if(lowerSickness.find("infection") != string::npos) category = "Infection";
    else if(lowerSickness.find("pain") != string::npos) category = "Pain";
    if(category != "") {
        cout << "Recommended for " << category << ":" << endl;
        for(int i = 0; i < medicineCount; i++) {
            if(medicines[i].category == category) {
                cout << "ID " << (i+1) << ": " << medicines[i].name << " - Rs. " 
                     << medicines[i].price << " (Stock: " << medicines[i].stock << ")" << endl;
                found = true;
            }
        }
    }
    if(!found) {
        cout << "General Medicines:" << endl;
        cout << "ID 1: Panadol - Rs. 50" << endl;
        cout << "ID 28: Centrum - Rs. 400" << endl;
    }
}
//CRUD OPERATION FOR DOCTOR MANAGEMENT
void manageDoctors() {
    clearScreen();
    cout << "\n========================================================" << endl;
    cout << "               DOCTOR MANAGEMENT" << endl;
    cout << "========================================================\n" << endl;
    cout << "1. Add Doctor" << endl;
    cout << "2. Remove Doctor" << endl;
    cout << "3. Update Doctor" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if(choice == 1) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "                  ADD NEW DOCTOR" << endl;
        cout << "========================================================\n" << endl;
        cout << "1. Senior Doctor" << endl;
        cout << "2. Junior Doctor" << endl;
        cout << "Enter type: ";
        int type;
        cin >> type;
        while(type < 1 || type > 2) {
            cout << "Invalid option! Please choose between 1 or 2: ";
            cin >> type;
        }
        Doctor newDoctor;
        cin.ignore();
        cout << "Enter Doctor Name: ";
        getline(cin, newDoctor.name);
        cout << "Enter Speciality: ";
        getline(cin, newDoctor.speciality);
        cout << "Enter Consultation Fee: ";
        cin >> newDoctor.fee;
        cin.ignore();
        cout << "Enter Location: ";
        getline(cin, newDoctor.location);
        
        if(type == 1 && seniorDoctorCount < 20) {
            seniorDoctors[seniorDoctorCount] = newDoctor;
            seniorDoctorCount++;
            cout << "\nSenior Doctor added successfully!" << endl;
        } else if(type == 2 && juniorDoctorCount < 20) {
            juniorDoctors[juniorDoctorCount] = newDoctor;
            juniorDoctorCount++;
            cout << "\nJunior Doctor added successfully!" << endl;
        } else {
            cout << "\nCannot add more doctors! Maximum limit reached." << endl;
        }
        
    } else if(choice == 2) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "                 REMOVE DOCTOR" << endl;
        cout << "========================================================\n" << endl;
        
        displayDoctors();
        
        cout << "\n1. Remove Senior Doctor" << endl;
        cout << "2. Remove Junior Doctor" << endl;
        cout << "Enter type: ";
        int type;
        cin >> type;
        
        while(type < 1 || type > 2) {
            cout << "Invalid option! Please choose between 1 or 2: ";
            cin >> type;
        }
        
        cout << "Enter doctor number to remove: ";
        int doctorNum;
        cin >> doctorNum;
        
        if(type == 1 && doctorNum >= 1 && doctorNum <= seniorDoctorCount) {
            for(int i = doctorNum - 1; i < seniorDoctorCount - 1; i++) {
                seniorDoctors[i] = seniorDoctors[i + 1];
            }
            seniorDoctorCount--;
            cout << "\nSenior Doctor removed successfully!" << endl;
        } else if(type == 2 && doctorNum >= 1 && doctorNum <= juniorDoctorCount) {
            for(int i = doctorNum - 1; i < juniorDoctorCount - 1; i++) {
                juniorDoctors[i] = juniorDoctors[i + 1];
            }
            juniorDoctorCount--;
            cout << "\nJunior Doctor removed successfully!" << endl;
        } else {
            cout << "\nInvalid doctor number!" << endl;
        }
    } else if(choice == 3) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "                 UPDATE DOCTOR" << endl;
        cout << "========================================================\n" << endl;
        
        displayDoctors();
        
        cout << "\n1. Update Senior Doctor" << endl;
        cout << "2. Update Junior Doctor" << endl;
        cout << "Enter type: ";
        int type;
        cin >> type;
        
        while(type < 1 || type > 2) {
            cout << "Invalid option! Please choose between 1 or 2: ";
            cin >> type;
        }
        
        cout << "Enter doctor number to update: ";
        int doctorNum;
        cin >> doctorNum;
        
        if(type == 1 && doctorNum >= 1 && doctorNum <= seniorDoctorCount) {
            cin.ignore();
            cout << "Enter New Doctor Name: ";
            getline(cin, seniorDoctors[doctorNum-1].name);
            cout << "Enter New Speciality: ";
            getline(cin, seniorDoctors[doctorNum-1].speciality);
            cout << "Enter New Consultation Fee: ";
            cin >> seniorDoctors[doctorNum-1].fee;
            cin.ignore();
            cout << "Enter New Location: ";
            getline(cin, seniorDoctors[doctorNum-1].location);
            cout << "\nSenior Doctor updated successfully!" << endl;
        } else if(type == 2 && doctorNum >= 1 && doctorNum <= juniorDoctorCount) {
            cin.ignore();
            cout << "Enter New Doctor Name: ";
            getline(cin, juniorDoctors[doctorNum-1].name);
            cout << "Enter New Speciality: ";
            getline(cin, juniorDoctors[doctorNum-1].speciality);
            cout << "Enter New Consultation Fee: ";
            cin >> juniorDoctors[doctorNum-1].fee;
            cin.ignore();
            cout << "Enter New Location: ";
            getline(cin, juniorDoctors[doctorNum-1].location);
            cout << "\nJunior Doctor updated successfully!" << endl;
        } else {
            cout << "\nInvalid doctor number!" << endl;
        }
    }
    
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

//CRUD OPERATION FOR MEDICINE MANAGEMENT
void manageMedicines() {
    clearScreen();
    cout << "\n========================================================" << endl;
    cout << "              MEDICINE MANAGEMENT" << endl;
    cout << "========================================================\n" << endl;
    cout << "1. Add Medicine" << endl;
    cout << "2. Remove Medicine" << endl;
    cout << "3. Update Medicine" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if(choice == 1) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "                 ADD NEW MEDICINE" << endl;
        cout << "========================================================\n" << endl;
        if(medicineCount >= 50) {
            cout << "Cannot add more medicines! Maximum limit reached." << endl;
        } else {
            Medicine newMedicine;
            cin.ignore();
            cout << "Available Categories:" << endl;
            for(int i = 0; i < categoryCount; i++) {
                cout << (i+1) << ". " << categories[i] << endl;
            }
            cout << "Enter Medicine Name: ";
            getline(cin, newMedicine.name);
            cout << "Enter Category Number: ";
            int catChoice;
            cin >> catChoice;
            if(catChoice >= 1 && catChoice <= categoryCount) {
                newMedicine.category = categories[catChoice-1];
            } else {
                newMedicine.category = "General";
            }
            cout << "Enter Price: ";
            cin >> newMedicine.price;
            cout << "Enter Stock Quantity: ";
            cin >> newMedicine.stock;
            
            medicines[medicineCount] = newMedicine;
            medicineCount++;
            cout << "\nMedicine added successfully!" << endl;
        }
        
    } else if(choice == 2) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "                 REMOVE MEDICINE" << endl;
        cout << "========================================================\n" << endl;
        
        displayPharmacy();
        
        cout << "\nEnter medicine ID to remove: ";
        int medicineID;
        cin >> medicineID;
        
        if(medicineID >= 1 && medicineID <= medicineCount) {
            for(int i = medicineID - 1; i < medicineCount - 1; i++) {
                medicines[i] = medicines[i + 1];
            }
            medicineCount--;
            cout << "\nMedicine removed successfully!" << endl;
        } else {
            cout << "\nInvalid medicine ID!" << endl;
        }
    } else if(choice == 3) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "                 UPDATE MEDICINE" << endl;
        cout << "========================================================\n" << endl;
        
        displayPharmacy();
        
        cout << "\nEnter medicine ID to update: ";
        int medicineID;
        cin >> medicineID;
        
        if(medicineID >= 1 && medicineID <= medicineCount) {
            cin.ignore();
            cout << "Enter New Medicine Name: ";
            getline(cin, medicines[medicineID-1].name);
            
            cout << "Available Categories:" << endl;
            for(int i = 0; i < categoryCount; i++) {
                cout << (i+1) << ". " << categories[i] << endl;
            }
            cout << "Enter New Category Number: ";
            int catChoice;
            cin >> catChoice;
            if(catChoice >= 1 && catChoice <= categoryCount) {
                medicines[medicineID-1].category = categories[catChoice-1];
            }
            cout << "Enter New Price: ";
            cin >> medicines[medicineID-1].price;
            cout << "Enter New Stock Quantity: ";
            cin >> medicines[medicineID-1].stock;
            
            cout << "\nMedicine updated successfully!" << endl;
        } else {
            cout << "\nInvalid medicine ID!" << endl;
        }
    }
    
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

//CRUD OPERATION FOR PATIENT BILL
void editPatientBill() {
    clearScreen();
    cout << "\n========================================================" << endl;
    cout << "                 EDIT PATIENT BILL" << endl;
    cout << "========================================================\n" << endl;
    if(patientCount == 0) {
        cout << "No patients registered yet." << endl;
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "1. Update Bill" << endl;
    cout << "2. Add Bill Amount" << endl;
    cout << "3. Remove Bill" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    
    if(choice == 1 || choice == 2 || choice == 3) {
        cout << "\nActive Patients:" << endl;
        for(int i = 0; i < patientCount; i++) {
            cout << "ID: " << patients[i].id << " - Bill: Rs. " << patients[i].bill.totalBill << endl;
        }
        
        cout << "\nEnter Patient ID: ";
        int patientID;
        cin >> patientID;
        
        bool found = false;
        for(int i = 0; i < patientCount; i++) {
            if(patients[i].id == patientID) {
                found = true;
                if(choice == 1) {
                    cout << "\nCurrent Bill: Rs. " << patients[i].bill.totalBill << endl;
                    cout << "Enter new bill amount: ";
                    cin >> patients[i].bill.totalBill;
                    cout << "Bill updated successfully!" << endl;
                } else if(choice == 2) {
                    int additionalAmount;
                    cout << "\nCurrent Bill: Rs. " << patients[i].bill.totalBill << endl;
                    cout << "Enter amount to add: ";
                    cin >> additionalAmount;
                    patients[i].bill.totalBill += additionalAmount;
                    cout << "Amount added successfully! New bill: Rs. " << patients[i].bill.totalBill << endl;
                } else if(choice == 3) {
                    patients[i].bill.totalBill = 0;
                    cout << "Bill removed successfully! Bill set to Rs. 0" << endl;
                }
                break;
            }
        }
        if(!found) {
            cout << "Patient ID not found!" << endl;
        }
    }
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

//CRUD OPERATION FOR PATIENT MEDICAL HISTORY
void managePatientHistory() {
    clearScreen();
    cout << "\n========================================================" << endl;
    cout << "             PATIENT MEDICAL HISTORY" << endl;
    cout << "========================================================\n" << endl;
    if(patientCount == 0) {
        cout << "No patients registered yet." << endl;
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "1. View Medical History" << endl;
    cout << "2. Add Medical History Entry" << endl;
    cout << "3. Update Medical History Entry" << endl;
    cout << "4. Remove Medical History Entry" << endl;
    cout << "5. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    
    if(choice >= 1 && choice <= 4) {
        cout << "\nPatients:" << endl;
        for(int i = 0; i < patientCount; i++) {
            cout << "ID: " << patients[i].id << " - " << patients[i].name << endl;
        }
        cout << "\nEnter Patient ID: ";
        int patientID;
        cin >> patientID;
        
        int patientIndex = -1;
        for(int i = 0; i < patientCount; i++) {
            if(patients[i].id == patientID) {
                patientIndex = i;
                break;
            }
        }
        if(patientIndex == -1) {
            cout << "Patient ID not found!" << endl;
        } else {
            if(choice == 1) {
                clearScreen();
                cout << "\n========================================================" << endl;
                cout << "      MEDICAL HISTORY - " << patients[patientIndex].name << endl;
                cout << "========================================================\n" << endl;
                
                if(patients[patientIndex].historyCount == 0) {
                    cout << "No medical history records found." << endl;
                } else {
                    for(int i = 0; i < patients[patientIndex].historyCount; i++) {
                        cout << "Entry #" << (i + 1) << ":" << endl;
                        cout << "Date      : " << patients[patientIndex].history[i].date << endl;
                        cout << "Diagnosis : " << patients[patientIndex].history[i].diagnosis << endl;
                        cout << "Treatment : " << patients[patientIndex].history[i].treatment << endl;
                        cout << "Notes     : " << patients[patientIndex].history[i].notes << endl;
                        cout << "--------------------------------------------------------" << endl;
                    }
                }
            } else if(choice == 2) {
                if(patients[patientIndex].historyCount >= 10) {
                    cout << "Maximum history entries reached for this patient!" << endl;
                } else {
                    cin.ignore();
                    cout << "\nEnter Date (DD/MM/YYYY): ";
                    getline(cin, patients[patientIndex].history[patients[patientIndex].historyCount].date);
                    cout << "Enter Diagnosis: ";
                    getline(cin, patients[patientIndex].history[patients[patientIndex].historyCount].diagnosis);
                    cout << "Enter Treatment: ";
                    getline(cin, patients[patientIndex].history[patients[patientIndex].historyCount].treatment);
                    cout << "Enter Notes: ";
                    getline(cin, patients[patientIndex].history[patients[patientIndex].historyCount].notes);
                    
                    patients[patientIndex].historyCount++;
                    cout << "\nMedical history entry added successfully!" << endl;
                }
            } else if(choice == 3) {
                if(patients[patientIndex].historyCount == 0) {
                    cout << "No medical history records to update." << endl;
                } else {
                    cout << "\nEnter entry number to update (1-" << patients[patientIndex].historyCount << "): ";
                    int entryNum;
                    cin >> entryNum;
                    
                    if(entryNum >= 1 && entryNum <= patients[patientIndex].historyCount) {
                        cin.ignore();
                        cout << "Enter New Date (DD/MM/YYYY): ";
                        getline(cin, patients[patientIndex].history[entryNum-1].date);
                        cout << "Enter New Diagnosis: ";
                        getline(cin, patients[patientIndex].history[entryNum-1].diagnosis);
                        cout << "Enter New Treatment: ";
                        getline(cin, patients[patientIndex].history[entryNum-1].treatment);
                        cout << "Enter New Notes: ";
                        getline(cin, patients[patientIndex].history[entryNum-1].notes);
                        
                        cout << "\nMedical history entry updated successfully!" << endl;
                    } else {
                        cout << "Invalid entry number!" << endl;
                    }
                }
            } else if(choice == 4) {
                if(patients[patientIndex].historyCount == 0) {
                    cout << "No medical history records to remove." << endl;
                } else {
                    cout << "\nEnter entry number to remove (1-" << patients[patientIndex].historyCount << "): ";
                    int entryNum;
                    cin >> entryNum;
                    
                    if(entryNum >= 1 && entryNum <= patients[patientIndex].historyCount) {
                        for(int i = entryNum - 1; i < patients[patientIndex].historyCount - 1; i++) {
                            patients[patientIndex].history[i] = patients[patientIndex].history[i + 1];
                        }
                        patients[patientIndex].historyCount--;
                        cout << "\nMedical history entry removed successfully!" << endl;
                    } else {
                        cout << "Invalid entry number!" << endl;
                    }
                }
            }
        }
    }
    
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

//CRUD OPERATION FOR ROOM MANAGEMENT
void manageRooms() {
    clearScreen();
    cout << "\n========================================================" << endl;
    cout << "               ROOM MANAGEMENT" << endl;
    cout << "========================================================\n" << endl;
    cout << "1. Add New Room Type" << endl;
    cout << "2. Remove Room Type" << endl;
    cout << "3. Update Room Type" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "               ADD NEW ROOM TYPE" << endl;
        cout << "========================================================\n" << endl;
        
        if(roomCount >= 10) {
            cout << "Cannot add more room types! Maximum limit reached." << endl;
        } else {
            Room newRoom;
            cin.ignore();
            cout << "Enter Room Type Name: ";
            getline(cin, newRoom.typeName);
            cout << "Enter Price per Day: ";
            cin >> newRoom.price;
            cout << "Enter Total Rooms: ";
            cin >> newRoom.total;
            newRoom.available = newRoom.total;
            cin.ignore();
            cout << "Enter Room Features: ";
            getline(cin, newRoom.features);
            
            rooms[roomCount] = newRoom;
            roomCount++;
            cout << "\nRoom type added successfully!" << endl;
        }
        
    } else if(choice == 2) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "               REMOVE ROOM TYPE" << endl;
        cout << "========================================================\n" << endl;
        
        displayRoomAvailability();
        
        cout << "\nEnter room type number to remove: ";
        int roomNum;
        cin >> roomNum;
        
        if(roomNum >= 1 && roomNum <= roomCount) {
            for(int i = roomNum - 1; i < roomCount - 1; i++) {
                rooms[i] = rooms[i + 1];
            }
            roomCount--;
            cout << "\nRoom type removed successfully!" << endl;
        } else {
            cout << "\nInvalid room type number!" << endl;
        }
    } else if(choice == 3) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "               UPDATE ROOM TYPE" << endl;
        cout << "========================================================\n" << endl;
        
        displayRoomAvailability();
        
        cout << "\nEnter room type number to update: ";
        int roomNum;
        cin >> roomNum;
        
        if(roomNum >= 1 && roomNum <= roomCount) {
            cin.ignore();
            cout << "Enter New Room Type Name: ";
            getline(cin, rooms[roomNum-1].typeName);
            cout << "Enter New Price per Day: ";
            cin >> rooms[roomNum-1].price;
            cout << "Enter New Total Rooms: ";
            cin >> rooms[roomNum-1].total;
            rooms[roomNum-1].available = rooms[roomNum-1].total;
            cin.ignore();
            cout << "Enter New Room Features: ";
            getline(cin, rooms[roomNum-1].features);
            
            cout << "\nRoom type updated successfully!" << endl;
        } else {
            cout << "\nInvalid room type number!" << endl;
        }
    }
    
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

//CRUD OPERATION FOR CATEGORY MANAGEMENT
void manageCategories() {
    clearScreen();
    cout << "\n========================================================" << endl;
    cout << "               CATEGORY MANAGEMENT" << endl;
    cout << "========================================================\n" << endl;
    cout << "1. View All Categories" << endl;
    cout << "2. Add New Category" << endl;
    cout << "3. Update Category" << endl;
    cout << "4. Remove Category" << endl;
    cout << "5. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "               ALL MEDICINE CATEGORIES" << endl;
        cout << "========================================================\n" << endl;
        
        for(int i = 0; i < categoryCount; i++) {
            cout << (i+1) << ". " << categories[i] << endl;
        }
    } else if(choice == 2) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "               ADD NEW CATEGORY" << endl;
        cout << "========================================================\n" << endl;
        
        if(categoryCount >= 20) {
            cout << "Cannot add more categories! Maximum limit reached." << endl;
        } else {
            string newCategory;
            cin.ignore();
            cout << "Enter new category name: ";
            getline(cin, newCategory);
            
            categories[categoryCount] = newCategory;
            categoryCount++;
            cout << "\nCategory '" << newCategory << "' added successfully!" << endl;
        }
    } else if(choice == 3) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "               UPDATE CATEGORY" << endl;
        cout << "========================================================\n" << endl;
        
        for(int i = 0; i < categoryCount; i++) {
            cout << (i+1) << ". " << categories[i] << endl;
        }
        cout << "\nEnter category number to update: ";
        int catNum;
        cin >> catNum;
        
        if(catNum >= 1 && catNum <= categoryCount) {
            cin.ignore();
            cout << "Enter new category name: ";
            getline(cin, categories[catNum-1]);
            cout << "\nCategory updated successfully!" << endl;
        } else {
            cout << "\nInvalid category number!" << endl;
        }
    } else if(choice == 4) {
        clearScreen();
        cout << "\n========================================================" << endl;
        cout << "               REMOVE CATEGORY" << endl;
        cout << "========================================================\n" << endl;
        
        for(int i = 0; i < categoryCount; i++) {
            cout << (i+1) << ". " << categories[i] << endl;
        }
        cout << "\nEnter category number to remove: ";
        int catNum;
        cin >> catNum;
        
        if(catNum >= 1 && catNum <= categoryCount) {
            for(int i = catNum - 1; i < categoryCount - 1; i++) {
                categories[i] = categories[i + 1];
            }
            categoryCount--;
            cout << "\nCategory removed successfully!" << endl;
        } else {
            cout << "\nInvalid category number!" << endl;
        }
    }
    
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

//CRUD OPERATION TO UPDATE PATIENT INFORMATION
void updatePatientInfo() {
    clearScreen();
    cout << "\n========================================================" << endl;
    cout << "             UPDATE PATIENT INFORMATION" << endl;
    cout << "========================================================\n" << endl;
    if(patientCount == 0) {
        cout << "No patients registered yet." << endl;
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "1. Update Patient Information" << endl;
    cout << "2. Add New Patient" << endl;
    cout << "3. Remove Patient" << endl;
    cout << "4. Back to Main Menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        cout << "\nPatients:" << endl;
        for(int i = 0; i < patientCount; i++) {
            cout << "ID: " << patients[i].id << " - " << patients[i].name << endl;
        }
        cout << "\nEnter Patient ID to update: ";
        int patientID;
        cin >> patientID;
        
        int patientIndex = -1;
        for(int i = 0; i < patientCount; i++) {
            if(patients[i].id == patientID) {
                patientIndex = i;
                break;
            }
        }
        if(patientIndex == -1) {
            cout << "Patient ID not found!" << endl;
        } else {
            clearScreen();
            cout << "\n========================================================" << endl;
            cout << "        UPDATE INFORMATION - " << patients[patientIndex].name << endl;
            cout << "========================================================\n" << endl;
            cout << "Current Information:" << endl;
            cout << "1. Name: " << patients[patientIndex].name << endl;
            cout << "2. Age: " << patients[patientIndex].age << endl;
            cout << "3. Gender: " << patients[patientIndex].gender << endl;
            cout << "4. Contact: " << patients[patientIndex].contact << endl;
            cout << "5. Sickness: " << patients[patientIndex].sickness << endl;
            cout << "6. CNIC: " << patients[patientIndex].cnic << endl;
            cout << "7. Blood Group: " << patients[patientIndex].bloodGroup << endl;
            cout << "\nEnter field number to update (1-7, 0 to cancel): ";
            int fieldChoice;
            cin >> fieldChoice;
            
            if(fieldChoice == 0) {
                cout << "Update cancelled." << endl;
            } else if(fieldChoice >= 1 && fieldChoice <= 7) {
                string newValue;
                cout << "Enter new value: ";
                cin.ignore();
                getline(cin, newValue);
                
                switch(fieldChoice) {
                    case 1: patients[patientIndex].name = newValue; break;
                    case 2: patients[patientIndex].age = stringToInt(newValue); break;
                    case 3: patients[patientIndex].gender = newValue; break;
                    case 4: patients[patientIndex].contact = newValue; break;
                    case 5: patients[patientIndex].sickness = newValue; break;
                    case 6: patients[patientIndex].cnic = newValue; break;
                    case 7: patients[patientIndex].bloodGroup = newValue; break;
                }
                cout << "\nPatient information updated successfully!" << endl;
            }
        }
    } else if(choice == 2) {
        if(patientCount >= 50) {
            cout << "Cannot add more patients! Maximum limit reached." << endl;
        } else {
            Patient newPatient;
            cin.ignore();
            cout << "Enter Patient Name: ";
            getline(cin, newPatient.name);
            cout << "Enter Patient Age: ";
            cin >> newPatient.age;
            cout << "Enter Patient Gender (M/F): ";
            cin >> newPatient.gender;
            cout << "Enter Contact Number: ";
            cin >> newPatient.contact;
            cin.ignore();
            cout << "Enter CNIC: ";
            getline(cin, newPatient.cnic);
            cout << "Enter Blood Group: ";
            getline(cin, newPatient.bloodGroup);
            cout << "Enter Sickness: ";
            getline(cin, newPatient.sickness);
            
            newPatient.id = patientCounter++;
            newPatient.historyCount = 0;
            newPatient.discharged = false;
            patients[patientCount] = newPatient;
            patientCount++;
            cout << "\nPatient added successfully! ID: " << newPatient.id << endl;
        }
    } else if(choice == 3) {
        cout << "\nPatients:" << endl;
        for(int i = 0; i < patientCount; i++) {
            cout << "ID: " << patients[i].id << " - " << patients[i].name << endl;
        }
        cout << "\nEnter Patient ID to remove: ";
        int patientID;
        cin >> patientID;
        
        int patientIndex = -1;
        for(int i = 0; i < patientCount; i++) {
            if(patients[i].id == patientID) {
                patientIndex = i;
                break;
            }
        }
        if(patientIndex == -1) {
            cout << "Patient ID not found!" << endl;
        } else {
            for(int i = patientIndex; i < patientCount - 1; i++) {
                patients[i] = patients[i + 1];
            }
            patientCount--;
            cout << "\nPatient removed successfully!" << endl;
        }
    }
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// ============ END OF MISSING FUNCTIONS ============

// Main function with login system
int main() {
    // First, show login screen
    if(!login()) {
        return 0; // Exit if login fails
    }
    
    initializeArrays();
    
    while(true) {
        clearScreen();
        displayMainMenu();
        cin >> mainChoice;
        
        if(mainChoice == 1) {
            clearScreen();
            displayDoctors();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            
        } else if(mainChoice == 2) {
            clearScreen();
            displayPharmacy();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            
        } else if(mainChoice == 3) {
            manageDoctors();
            
        } else if(mainChoice == 4) {
            manageMedicines();
            
        } else if(mainChoice == 5) {
            clearScreen();
            cout << "\n========================================================" << endl;
            cout << "              PATIENT REGISTRATION" << endl;
            cout << "========================================================\n" << endl;
            Patient newPatient;
            
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, newPatient.name);
            cout << "Enter Patient Age: ";
            cin >> newPatient.age;
            cout << "Enter Patient Gender (M/F): ";
            cin >> newPatient.gender;
            
            while(newPatient.gender != "M" && newPatient.gender != "F" && 
                  newPatient.gender != "m" && newPatient.gender != "f") {
                cout << "Invalid gender! Please enter M or F: ";
                cin >> newPatient.gender;
            }
            cout << "Enter Contact Number: ";
            cin >> newPatient.contact;
            cin.ignore();
            cout << "Enter CNIC: ";
            getline(cin, newPatient.cnic);
            cout << "Enter Blood Group: ";
            getline(cin, newPatient.bloodGroup);
            cout << "Enter Patient Sickness/Problem: ";
            getline(cin, newPatient.sickness);
            cout << "\n*** EMERGENCY CONTACT ***" << endl;
            cout << "Emergency Contact Name: ";
            getline(cin, newPatient.emergency.name);
            cout << "Emergency Contact Number: ";
            cin >> newPatient.emergency.number;
            cout << "Relation (Father/Mother/Spouse): ";
            cin.ignore();
            getline(cin, newPatient.emergency.relation);
    
            newPatient.id = patientCounter++;
            
            cout << "\nPatient Registered! ID: " << newPatient.id << endl;
            cout << "\n========================================================" << endl;
            cout << "              PATIENT ADMISSION TYPE" << endl;
            cout << "========================================================" << endl;
            cout << "1. Indoor Patient (Admitted)" << endl;
            cout << "2. Outdoor Patient (OPD)" << endl;
            cout << "Enter choice: ";
            cin >> subChoice;
            while(subChoice < 1 || subChoice > 2) {
                cout << "Invalid option! Please choose between 1 or 2: ";
                cin >> subChoice;
            }
            if(subChoice == 1) {
                newPatient.patientType = "Indoor";
                
                clearScreen();
                displayRoomAvailability();
                
                cout << "\nEnter room choice (1-" << roomCount << "): ";
                int roomChoice;
                cin >> roomChoice;
                
                while(roomChoice < 1 || roomChoice > roomCount) {
                    cout << "Invalid option! Please choose between 1-" << roomCount << ": ";
                    cin >> roomChoice;
                }
                
                if(rooms[roomChoice-1].available > 0) {
                    newPatient.roomType = rooms[roomChoice-1].typeName;
                    newPatient.bill.roomCharges = rooms[roomChoice-1].price;
                    rooms[roomChoice-1].available--;
                } else {
                    cout << "Room type is full! Assigning General Ward." << endl;
                    newPatient.roomType = rooms[0].typeName;
                    newPatient.bill.roomCharges = rooms[0].price;
                    if(rooms[0].available > 0) rooms[0].available--;
                }
                
                cout << "Days for admission: ";
                cin >> newPatient.bill.daysAdmitted;
                while(newPatient.bill.daysAdmitted <= 0) {
                    cout << "Invalid days! Please enter positive number: ";
                    cin >> newPatient.bill.daysAdmitted;
                }
                newPatient.bill.roomTotal = newPatient.bill.roomCharges * newPatient.bill.daysAdmitted;
                
            } else {
                newPatient.patientType = "Outdoor";
                newPatient.roomType = "N/A";
                newPatient.bill.roomCharges = 0;
                newPatient.bill.daysAdmitted = 0;
                newPatient.bill.roomTotal = 0;
            }
            
            clearScreen();
            cout << "\n========================================================" << endl;
            cout << "                  MEDICAL TESTS" << endl;
            cout << "========================================================" << endl;
            
            for(int i = 0; i < 6; i++) {
                cout << (i+1) << ". " << tests[i].name << " - Rs. " << tests[i].price 
                     << " (" << tests[i].duration << ")" << endl;
            }
            cout << "0. Done" << endl;
            
            newPatient.bill.testCost = 0;
            newPatient.testName = "";
            bool firstTest = true;
            int testChoice;
            
            cout << "\nEnter test choices:" << endl;
            while(true) {
                cout << "Test: ";
                cin >> testChoice;
                
                if(testChoice == 0) break;
                
                if(testChoice >= 1 && testChoice <= 6) {
                    newPatient.bill.testCost += tests[testChoice-1].price;
                    if(firstTest) {
                        newPatient.testName = tests[testChoice-1].name;
                        firstTest = false;
                    } else {
                        newPatient.testName += ", " + tests[testChoice-1].name;
                    }
                    cout << "Added: " << tests[testChoice-1].name << endl;
                } else {
                    cout << "Invalid option! Please choose between 0-6." << endl;
                }
            }
            
            if(newPatient.testName == "") newPatient.testName = "No Test";
            
            clearScreen();
            cout << "\n========================================================" << endl;
            cout << "              DOCTOR CONSULTATION" << endl;
            cout << "========================================================" << endl;
            cout << "1. Senior Doctor" << endl;
            cout << "2. Junior Doctor" << endl;
            cout << "Choice: ";
            cin >> subChoice;
            
            while(subChoice < 1 || subChoice > 2) {
                cout << "Invalid option! Please choose between 1 or 2: ";
                cin >> subChoice;
            }
            
            int doctorChoice;
            
            if(subChoice == 1) {
                cout << "\nSenior Doctors:" << endl;
                for(int i = 0; i < seniorDoctorCount; i++) {
                    cout << (i+1) << ". " << seniorDoctors[i].name << " - " 
                         << seniorDoctors[i].speciality << " (Rs." << seniorDoctors[i].fee << ")" << endl;
                }
                cout << "Choice: ";
                cin >> doctorChoice;
                
                while(doctorChoice < 1 || doctorChoice > seniorDoctorCount) {
                    cout << "Invalid option! Please choose between 1-" << seniorDoctorCount << ": ";
                    cin >> doctorChoice;
                }
                
                newPatient.doctorName = seniorDoctors[doctorChoice-1].name;
                newPatient.doctorLocation = seniorDoctors[doctorChoice-1].speciality + " - " + seniorDoctors[doctorChoice-1].location;
                newPatient.bill.consultationFee = seniorDoctors[doctorChoice-1].fee;
                
            } else {
                cout << "\nJunior Doctors:" << endl;
                for(int i = 0; i < juniorDoctorCount; i++) {
                    cout << (i+1) << ". " << juniorDoctors[i].name << " - " 
                         << juniorDoctors[i].speciality << " (Rs." << juniorDoctors[i].fee << ")" << endl;
                }
                cout << "Choice: ";
                cin >> doctorChoice;
                
                while(doctorChoice < 1 || doctorChoice > juniorDoctorCount) {
                    cout << "Invalid option! Please choose between 1-" << juniorDoctorCount << ": ";
                    cin >> doctorChoice;
                }
                
                newPatient.doctorName = juniorDoctors[doctorChoice-1].name;
                newPatient.doctorLocation = juniorDoctors[doctorChoice-1].speciality + " - " + juniorDoctors[doctorChoice-1].location;
                newPatient.bill.consultationFee = juniorDoctors[doctorChoice-1].fee;
            }
            
            clearScreen();
            suggestMedicines(newPatient.sickness);
            
            cout << "\n========================================================" << endl;
            cout << "              SELECT MEDICINES" << endl;
            cout << "========================================================" << endl;
            cout << "Enter medicine IDs (1-" << medicineCount << "). Enter 0 when done.\n" << endl;
            
            newPatient.bill.medicineCost = 0;
            int medicineID;
            
            while(true) {
                cout << "Medicine ID: ";
                cin >> medicineID;
                if(medicineID == 0) break;
                
                if(medicineID >= 1 && medicineID <= medicineCount) {
                    if(medicines[medicineID-1].stock > 0) {
                        newPatient.bill.medicineCost += medicines[medicineID-1].price;
                        medicines[medicineID-1].stock--;
                        cout << "Added: " << medicines[medicineID-1].name << " - Rs." << medicines[medicineID-1].price << endl;
                    } else {
                        cout << "Out of stock!" << endl;
                    }
                } else {
                    cout << "Invalid option! Please choose between 0-" << medicineCount << "." << endl;
                }
            }
            
            cout << "\n========================================================" << endl;
            cout << "                 PAYMENT METHOD" << endl;
            cout << "========================================================" << endl;
            cout << "1. Cash" << endl;
            cout << "2. Credit/Debit Card" << endl;
            cout << "3. Insurance" << endl;
            cout << "4. Mobile Payment" << endl;
            cout << "Choice: ";
            cin >> subChoice;
            
            while(subChoice < 1 || subChoice > 4) {
                cout << "Invalid option! Please choose between 1-4: ";
                cin >> subChoice;
            }
            
            if(subChoice == 1) newPatient.bill.paymentMethod = "Cash";
            else if(subChoice == 2) newPatient.bill.paymentMethod = "Card";
            else if(subChoice == 3) newPatient.bill.paymentMethod = "Insurance";
            else newPatient.bill.paymentMethod = "Mobile Payment";
            
            // Calculate total bill
            newPatient.bill.totalBill = newPatient.bill.consultationFee + newPatient.bill.testCost + 
                                       newPatient.bill.medicineCost + newPatient.bill.roomTotal;
            
            // Initialize medical history
            newPatient.historyCount = 1;
            newPatient.history[0].date = "Admission Date";
            newPatient.history[0].diagnosis = newPatient.sickness;
            newPatient.history[0].treatment = "Initial consultation";
            newPatient.history[0].notes = "Patient registered";
            newPatient.discharged = false;
            
            // Save patient
            patients[patientCount] = newPatient;
            patientCount++;
            
            // Display final bill
            clearScreen();
            cout << "\n========================================================" << endl;
            cout << "               PATIENT RECORD & BILL" << endl;
            cout << "========================================================" << endl;
            cout << "Patient ID: " << newPatient.id << endl;
            cout << "========================================================\n" << endl;
            
            cout << "*** PATIENT INFORMATION ***" << endl;
            cout << "Name          : " << newPatient.name << endl;
            cout << "Age           : " << newPatient.age << " years" << endl;
            cout << "Gender        : " << newPatient.gender << endl;
            cout << "Contact       : " << newPatient.contact << endl;
            cout << "CNIC          : " << newPatient.cnic << endl;
            cout << "Blood Group   : " << newPatient.bloodGroup << endl;
            cout << "Problem       : " << newPatient.sickness << endl;
            cout << "Patient Type  : " << newPatient.patientType << endl;
            
            cout << "\n*** EMERGENCY CONTACT ***" << endl;
            cout << "Name          : " << newPatient.emergency.name << endl;
            cout << "Number        : " << newPatient.emergency.number << endl;
            cout << "Relation      : " << newPatient.emergency.relation << endl;
            
            if(newPatient.patientType == "Indoor") {
                cout << "\n*** ADMISSION DETAILS ***" << endl;
                cout << "Room Type     : " << newPatient.roomType << endl;
                cout << "Charges/Day   : Rs. " << newPatient.bill.roomCharges << endl;
                cout << "Days Admitted : " << newPatient.bill.daysAdmitted << " days" << endl;
            }
            
            cout << "\n*** MEDICAL SERVICES ***" << endl;
            cout << "Doctor        : " << newPatient.doctorName << endl;
            cout << "Location      : " << newPatient.doctorLocation << endl;
            cout << "Tests         : " << newPatient.testName << endl;
            
            cout << "\n========================================================" << endl;
            cout << "                  BILLING DETAILS" << endl;
            cout << "========================================================" << endl;
            cout << left << setw(35) << "Description" << right << setw(15) << "Amount (Rs.)" << endl;
            cout << "--------------------------------------------------------" << endl;
            
            cout << left << setw(35) << "Doctor Consultation" << right << setw(15) << newPatient.bill.consultationFee << endl;
            cout << left << setw(35) << "Medical Tests" << right << setw(15) << newPatient.bill.testCost << endl;
            cout << left << setw(35) << "Medicines" << right << setw(15) << newPatient.bill.medicineCost << endl;
            
            if(newPatient.patientType == "Indoor") {
                cout << left << setw(35) << "Room Charges" << right << setw(15) << newPatient.bill.roomTotal << endl;
            }
            
            cout << "--------------------------------------------------------" << endl;
            cout << left << setw(35) << "TOTAL BILL" << right << setw(15) << newPatient.bill.totalBill << endl;
            cout << "========================================================" << endl;
            cout << "Payment Method: " << newPatient.bill.paymentMethod << endl;
            cout << "========================================================\n" << endl;
            
            cout << "        Thank you for choosing City General Hospital!" << endl;
            cout << "========================================================\n" << endl;
            
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            
        } else if(mainChoice == 6) {
            manageRooms();
            
        } else if(mainChoice == 7) {
            updatePatientInfo();
            
        } else if(mainChoice == 8) {
            clearScreen();
            if(patientCount == 0) {
                cout << "\n========================================================" << endl;
                cout << "              NO PATIENT RECORDS FOUND" << endl;
                cout << "========================================================" << endl;
                cout << "No patients registered yet." << endl;
            } else {
                int page = 0;
                int recordsPerPage = 5;
                int totalPages = (patientCount + recordsPerPage - 1) / recordsPerPage;
                
                while(true) {
                    clearScreen();
                    cout << "\n========================================================" << endl;
                    cout << "              ALL PATIENT RECORDS" << endl;
                    cout << "========================================================" << endl;
                    cout << "Page " << (page + 1) << " of " << totalPages << endl;
                    cout << "========================================================\n" << endl;
                    
                    int start = page * recordsPerPage;
                    int end = start + recordsPerPage;
                    if(end > patientCount) end = patientCount;
                    
                    for(int i = start; i < end; i++) {
                        cout << "*** PATIENT #" << (i + 1) << " ***" << endl;
                        cout << "Patient ID    : " << patients[i].id << endl;
                        cout << "Name          : " << patients[i].name << endl;
                        cout << "Age           : " << patients[i].age << " years" << endl;
                        cout << "Gender        : " << patients[i].gender << endl;
                        cout << "Contact       : " << patients[i].contact << endl;
                        cout << "CNIC          : " << patients[i].cnic << endl;
                        cout << "Blood Group   : " << patients[i].bloodGroup << endl;
                        cout << "Problem       : " << patients[i].sickness << endl;
                        cout << "Patient Type  : " << patients[i].patientType << endl;
                        
                        if(patients[i].patientType == "Indoor") {
                            cout << "Room Type     : " << patients[i].roomType << endl;
                            cout << "Days Admitted : " << patients[i].bill.daysAdmitted << " days" << endl;
                        }
                        
                        cout << "Doctor        : " << patients[i].doctorName << endl;
                        cout << "Tests         : " << patients[i].testName << endl;
                        cout << "Total Bill    : Rs. " << patients[i].bill.totalBill << endl;
                        cout << "Payment       : " << patients[i].bill.paymentMethod << endl;
                        cout << "Status        : " << (patients[i].discharged ? "Discharged" : "Active") << endl;
                        cout << "--------------------------------------------------------" << endl;
                    }
                    
                    cout << "\nNavigation:" << endl;
                    if(page > 0) cout << "1. Previous Page" << endl;
                    if(page < totalPages - 1) cout << "2. Next Page" << endl;
                    cout << "0. Back to Menu" << endl;
                    cout << "Choice: ";
                    
                    int navChoice;
                    cin >> navChoice;
                    
                    if(navChoice == 0) break;
                    else if(navChoice == 1 && page > 0) page--;
                    else if(navChoice == 2 && page < totalPages - 1) page++;
                }
            }
            
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            
        } else if(mainChoice == 9) {
            clearScreen();
            displayRoomAvailability();
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            
        } else if(mainChoice == 10) {
            clearScreen();
            cout << "\n========================================================" << endl;
            cout << "                DISCHARGE PATIENT" << endl;
            cout << "========================================================\n" << endl;
            
            if(patientCount == 0) {
                cout << "No patients to discharge." << endl;
            } else {
                cout << "Active Patients:" << endl;
                for(int i = 0; i < patientCount; i++) {
                    if(!patients[i].discharged) {
                        cout << "ID: " << patients[i].id << " - " << patients[i].name 
                             << " (" << patients[i].patientType << ")" << endl;
                    }
                }
                
                cout << "\nEnter Patient ID to discharge: ";
                int dischargeID;
                cin >> dischargeID;
                
                bool found = false;
                for(int i = 0; i < patientCount; i++) {
                    if(patients[i].id == dischargeID) {
                        patients[i].discharged = true;
                        if(patients[i].patientType == "Indoor") {
                            for(int j = 0; j < roomCount; j++) {
                                if(patients[i].roomType == rooms[j].typeName) {
                                    rooms[j].available++;
                                    break;
                                }
                            }
                        }
                        cout << "\nPatient " << patients[i].name << " discharged successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                
                if(!found) {
                    cout << "\nPatient ID not found!" << endl;
                }
            }
            
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            
        } else if(mainChoice == 11) {
            editPatientBill();
            
        } else if(mainChoice == 12) {
            manageCategories();
            
        } else if(mainChoice == 13) {
            managePatientHistory();
            
        } else if(mainChoice == 14) {
            clearScreen();
            cout << "\n========================================================" << endl;
            cout << "           HOSPITAL STATISTICS" << endl;
            cout << "========================================================" << endl;
            cout << "Total Patients        : " << patientCount << endl;
            
            int indoor = 0, outdoor = 0, discharged = 0;
            int totalRevenue = 0;
            
            for(int i = 0; i < patientCount; i++) {
                if(patients[i].patientType == "Indoor") indoor++;
                else outdoor++;
                if(patients[i].discharged) discharged++;
                totalRevenue += patients[i].bill.totalBill;
            }
            cout << "Indoor Patients       : " << indoor << endl;
            cout << "Outdoor Patients      : " << outdoor << endl;
            cout << "Discharged Patients   : " << discharged << endl;
            cout << "Active Patients       : " << (patientCount - discharged) << endl;
            cout << "Total Revenue         : Rs. " << totalRevenue << endl;
            
            cout << "\n*** ROOM OCCUPANCY ***" << endl;
            for(int i = 0; i < roomCount; i++) {
                int occupied = rooms[i].total - rooms[i].available;
                cout << rooms[i].typeName << ": " << occupied << "/" << rooms[i].total << endl;
            }
            cout << "\n*** LOW STOCK MEDICINES ***" << endl;
            bool lowStock = false;
            for(int i = 0; i < medicineCount; i++) {
                if(medicines[i].stock < 20) {
                    cout << medicines[i].name << ": " << medicines[i].stock << " units" << endl;
                    lowStock = true;
                }
            }
            if(!lowStock) {
                cout << "All medicines well stocked!" << endl;
            }
            cout << "========================================================\n" << endl;
            cout << "\nThank you for using Hospital Management System!" << endl;
            cout << "Goodbye!\n" << endl;
            break;
            
        } else {
            cout << "\nInvalid option! Please choose between 1-14." << endl;
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}
