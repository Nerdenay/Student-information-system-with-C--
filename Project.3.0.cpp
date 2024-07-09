/******************************************************************
 **                         DUZCE UNIVERSİTY                     **
 **                        ENGINERRING FACULTY                   **
 **                  COMPUTER ENGINEERING DEPARTMENT             **
 **              PROGRAMMING AND ALGORITHMS LESSON'S PROJECT     **
 **                                                              **
 **                             GROUP-4                          **
 *****************************************************************/


#include <iostream>
#include <fstream> // I used this for reading and writing files
#include <string>
#include <iomanip>
#include <thread>


using namespace std;

// LESSON CHOOSİNG PART
struct Course {
    string code{};
    string name{};
    int credits{};
};

void displayCourse(const Course& course) {
    cout << course.code << " - " << course.name << " (" << course.credits << " credits)" << endl;
}

bool confirmSelection() {
    cout << "Do you confirm your course selection? (Yes or No): ";
    string input;
    getline(cin, input);
    return (input == "y" || input == "Y" || input == "yes" || input == "YES");
}


void selectsem1() {
    cout << "WARNING: \n";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << " Please select all the compulsory courses. (Yes or No) \n";
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << " You can choose elective courses if you have enough credits." << endl << endl;

    cout << setw(60) << setfill('-') << "" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "COMPULSORY " << setw(35) << setfill(' ') << left << "COURSES" << "|" << setw(10) << setfill(' ') << left << "CREDIT" << "|" << endl;
    cout << setw(60) << setfill('-') << "" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "OOP" << "|" << setw(35) << setfill(' ') << left << "Object Oriented Programming" << "|" << setw(10) << setfill(' ') << left << "6" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "DMS" << "|" << setw(35) << setfill(' ') << left << "Discrete Mathematical Structures" << "|" << setw(10) << setfill(' ') << left << "6" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "CO" << "|" << setw(35) << setfill(' ') << left << "Computer Organization" << "|" << setw(10) << setfill(' ') << left << "5" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "DS" << "|" << setw(35) << setfill(' ') << left << "Data Structures" << "|" << setw(10) << setfill(' ') << left << "6" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "DE" << "|" << setw(35) << setfill(' ') << left << "Digital Electronics" << "|" << setw(10) << setfill(' ') << left << "5" << "|" << endl;
    cout << setw(60) << setfill('-') << "" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "ELECTIVE " << setw(35) << setfill(' ') << left << "COURSES" << "|" << setw(10) << setfill(' ') << left << "CREDIT" << "|" << endl;
    cout << setw(60) << setfill('-') << "" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "EE" << "|" << setw(35) << setfill(' ') << left << "Environment and Energy" << "|" << setw(10) << setfill(' ') << left << "3" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "E" << "|" << setw(35) << setfill(' ') << left << "Entrepreneurship" << "|" << setw(10) << setfill(' ') << left << "4" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "CD" << "|" << setw(35) << setfill(' ') << left << "Compiler Design" << "|" << setw(10) << setfill(' ') << left << "2" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "PE" << "|" << setw(35) << setfill(' ') << left << "Professional English" << "|" << setw(10) << setfill(' ') << left << "2" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "POP" << "|" << setw(35) << setfill(' ') << left << "The Principles Of Programming Lang." << "|" << setw(10) << setfill(' ') << left << "3" << "|" << endl;
    cout << setw(60) << setfill('-') << "" << endl;

    const int compulsoryCount = 5;
    const int electiveCount = 5;

    Course compulsoryCourses[compulsoryCount] = {
        {"OOP", "Object Oriented Programming", 6},
        {"DMS", "Discrete Mathematical Structures", 6},
        {"CO", "Computer Organization", 5},
        {"DS", "Data Structures", 6},
        {"DE", "Digital Electronics", 5}
    };

    Course electiveCourses[electiveCount] = {
        {"EE", "Environment and Energy", 3},
        {"EN", "Entrepreneurship", 4},
        {"CD", "Compiler Design", 2},
        {"PE", "Professional English", 2},
        {"POP", "The Principles Of Programming Languages", 3}
    };

    Course selectedCourses[compulsoryCount + electiveCount];
    int selectedCount = 0;

    // Zorunlu dersleri seç
    for (int i = 0; i < compulsoryCount; i++) {
        bool selected = false;
        do {
            cout << "Select " << compulsoryCourses[i].name << " [" << compulsoryCourses[i].code << "] (Credits: " << compulsoryCourses[i].credits << "): ";
            string input;
            cin>>input;
            cin.ignore();
            if (input == "y" || input == "Y" || input == "yes" || input == "YES") {
                selectedCourses[selectedCount++] = compulsoryCourses[i];
                selected = true;
            }
            else if (input == "n" || input == "N" || input == "no" || input == "NO") {
                selected = true;
            }
            else {
                cout << "Invalid input. Please enter y/n." << endl;
            }
        } while (!selected);
    }

    // Tüm zorunlu dersleri seçmediyse tekrar seçme işlemine devam et
    while (selectedCount < compulsoryCount) {
        cout << "You must select all compulsory courses. Please select again." << endl;
        selectedCount = 0;

        for (int i = 0; i < compulsoryCount; i++) {
            bool selected = false;
            do {
                cout << "Select " << compulsoryCourses[i].name << " [" << compulsoryCourses[i].code << "] (Credits: " << compulsoryCourses[i].credits << "): ";
                string input;
                getline(cin, input);
                if (input == "y" || input == "Y" || input == "yes" || input == "YES") {
                    selectedCourses[selectedCount++] = compulsoryCourses[i];
                    selected = true;
                }
                else if (input == "n" || input == "N" || input == "no" || input == "NO") {
                    selected = true;
                }
                else {
                    cout << "Invalid input. Please enter y/n." << endl;
                }
            } while (!selected);
        }
    }

    // Seçmeli dersleri seçme
    cout << endl << "Select elective courses if you have enough credits:" << endl;

    int selectedCredits = 0;
    int MAX_CREDITS = 10;
    for (int i = 0; i < electiveCount; i++) {
        bool selected = false;
        do {
            cout << "Select " << electiveCourses[i].name << " [" << electiveCourses[i].code << "] (Credits: " << electiveCourses[i].credits << "): ";
            string input;
            getline(cin, input);
            if (input == "y" || input == "Y" || input == "yes" || input == "YES") {
                if (selectedCredits + electiveCourses[i].credits > MAX_CREDITS) {
                    cout << "You have exceeded the maximum number of credits allowed." << endl;
                    continue;
                }
                selectedCourses[selectedCount++] = electiveCourses[i];
                selectedCredits += electiveCourses[i].credits;
                selected = true;
            }
            else if (input == "n" || input == "N" || input == "no" || input == "NO") {
                selected = true;
            }
            else {
                cout << "Invalid input. Please enter y/n." << endl;
            }
        } while (!selected);
    }

    // Seçilen derslerin listesini gösterme
    cout << endl << "Selected courses (Elective Courses (" << selectedCredits << " / 10 credits)):" << endl;
    for (int i = 0; i < selectedCount; i++) {
        cout << selectedCourses[i].code << " - " << selectedCourses[i].name << " (" << selectedCourses[i].credits << " credits)" << endl;
    }

    // Ders seçimini onaylama
    if (confirmSelection()) {
        // Seçim onaylandı, devam et
        cout << "Course selection confirmed. Proceeding..." << endl;
        // Burada devam eden kodları ekleyebilirsiniz
    }
    else {
        // Seçim onaylanmadı, başka bir işlem yapmak isteyip istemediğini sor
        cout << "Course selection cancelled." << endl;
        cout << "What would you like to do next?" << endl;
        cout << "1. Select courses again" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            system("cls");
            selectsem1(); // Başa dönmek için main fonksiyonunu tekrar çağır
            // Dikkat: Bu noktaya asla ulaşmayacak
        }
        else if (choice == "2") {
            cout << "Exiting program. Goodbye!" << endl;

        }
    }

}


bool login() {

    string Username, Password;
    string user, passw; //Comparison strings

    cout << "Enter Username: "; cin >> Username;
    cout << "Enter Password: "; cin >> Password;

    ifstream read(Username + ".txt"); // input file stream
    getline(read, user);
    getline(read, passw);

    if (user == Username && passw == Password)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main() {

    int choice;

    cout << "_________________________________________________________________________________________________\n";
    cout << "                                       WELCOME TO LOGIN PAGE                                     \n\n";
    cout << "______________________                        MENU                      _________________________\n\n\n";

    cout << "     || Please press 1 to LOGIN          ||\n";
    cout << "     || Please press 2 to REGISTER       ||\n";
    cout << "     || Please press 3 to EXIT           ||\n\n";
    cout << "\t   Enter your choice: ";
    cin >> choice;
    cout << "\n\n\n";

    if (choice == 1) {

        bool situation = login();
        if (!situation)
        {
            system("cls"); // to clear page
            cout << endl;
            cout << "Passsword or username is incorrect, Try again! " << endl;
            main();
            return 0;
        }
        else
        {
            int choiceTwo = 0;
            cout << "Congrats,Login successful!" << endl;
            cout << endl;
            system("cls");
            cout << "Welcome back !" << endl;
            cout << endl;
            system("cls");
            cout << "\t_______________________________________" << endl;
            cout << "\t______________*DASHBOARD*______________" << endl;
            cout << endl;
            cout << "      || Please press 1 to  SEE LESSON PLAN    ||\n";
            cout << "      || Please press 2 for CHOOSING COURSES   ||\n";
            cout << "      || Please press 3 to  BACK TO LOGIN MENU ||\n";
            cout << "      || please press 4 to  QUIT               ||\n";
            cin >> choiceTwo;
            cout << "\n\n\n";

            if (choiceTwo == 1)
            {


            }
            else if (choiceTwo == 2)
            {
                int choicethree;

                cout << "\t hangi yılsın krdşm ?\n";
                cin >> choicethree;

                if (choicethree == 2) {

                    system("cls");
                    selectsem1();
                }

            }
            else if (choiceTwo == 3)
            {
                system("cls"); // to clear page
                main();
            }
            else if (choiceTwo == 4)
            {
                return 0;
            }
        }

    }

    else if (choice == 2) {

        string Username, Password;

        cout << "*Registration: *" << endl;
        cout << "Select a username: "; cin >> Username;
        cout << "Select a password: "; cin >> Password;

        ofstream file; // open file stream, creates a file
        file.open(Username + ".txt");
        file << Username << endl << Password;
        file.close();
        cout << "Welcome  " << Username << "  !" << endl;
        system("cls");
        main();


    }
    else if (choice == 3) {

        cout << "You have logged of the system \n\n\n";
    }


}