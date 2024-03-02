/******************************************************************
 **                         DUZCE UNIVERSITY                     **
 **                        ENGINEERING FACULTY                   **
 **                  COMPUTER ENGINEERING DEPARTMENT             **
 **              PROGRAMMING AND ALGORITHMS LESSON'S PROJECT     **
 **                                                              **
 **                             GROUP-4                          **
 *****************************************************************/


#include <iostream>
#include <fstream> // I used this for reading and writing files
#include <string>
#include <iomanip>
#include <algorithm>


using namespace std;



// lesson choosing part for year 2
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

void dashboard();

// Year 1 
void year1() { 

    cout << "You have 30 Credits in this semester." << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "These are your compulsory subjects:" << endl;
    cout << "*   Physics(4 Credits)" << endl;
    cout << "*   Algorithms and Programming(3 Credits)" << endl;
    cout << "*   Information Technologies(2 Credits)" << endl;
    cout << "*   Electrical Circuit Fundamentals(3 Credits)" << endl;
    cout << "*   Mathematics(4 Credits)" << endl;
    cout << "*   Web Technologies(3 Credits)" << endl;
    cout << "*   Probability and Statistics(3 Credits)" << endl;
    cout << "*   Introducton to Computer Engineering(2 Credits)" << endl;

    cout << "NOTE: You do not have to choose these subjects." << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "These are your elective courses:" << endl;
    cout << "1   ATATURK's History(2 Credits)" << endl;
    cout << "2   Career Planning(2 Credits)" << endl;
    cout << "3   Academic English(2 Credits)" << endl;
    cout << "4   Turkish Language(2 Credits)" << endl << endl;
    cout << "NOTE: You have to choose 3 of them." << endl;
    cout << "----------------------------------------------------" << endl << endl;

    int selectedCourses[3];
    int courseCount = 0;

    while (courseCount < 3) {
        cout << "Please select an elective course by entering its number (1-4): ";
        cin >> selectedCourses[courseCount];

        if (cin.fail()) {
            cout << "Error! Invalid input. Please enter a numeric course number." << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (selectedCourses[courseCount] >= 1 && selectedCourses[courseCount] <= 4) {
            bool alreadySelected = false;
            for (int j = 0; j < courseCount; j++) {
                if (selectedCourses[j] == selectedCourses[courseCount]) {
                    alreadySelected = true;
                    break;
                }
            }
            if (!alreadySelected) {
                courseCount++;
            }
            else {
                cout << "Error! You have already selected that course. Please select a different course." << endl << endl;
            }
        }
        else {
            cout << "Error! Invalid course number. Please try again." << endl << endl;
        }
    }
    system("cls");

    cout << endl << "Registration completed. Here are your courses:" << endl << endl;
    for (int j = 0; j < 3; j++) {
        if (selectedCourses[j] == 1) {
            cout << "ATATURK's Principles and History of Turkish Revolution(2 Credits)" << endl;
        }
        else if (selectedCourses[j] == 2) {
            cout << "Career Planning(2 Credits)" << endl;
        }
        else if (selectedCourses[j] == 3) {
            cout << "Academic English(2 Credits)" << endl;
        }
        else if (selectedCourses[j] == 4) {
            cout << "Turkish Language(2 Credits)" << endl;
        }
    }
    cout << "Physics(4 Credits)" << endl << "Algorithms and Programming(3 Credits)" << endl
        << "Information Technologies(2 Credits)" << endl
        << "Electrical Circuit Fundamentals(3 Credits)" << endl << "Mathematics(4 Credits)" << endl << "Web Technologies(3 Credits)" << endl
        << "Probability and Statistics(3 Credits)" << endl << "Introducton to Computer Engineering(2 Credits)" << endl << endl;

    // Confirm your selection 
    string confirm;
    cout << "Do you confirm your selection? [yes/no]: ";
    cin >> confirm;
    if (confirm == "y" || confirm == "Y" || confirm == "yes" || confirm == "YES" || confirm == "Yes") {
        // Your selection is confirmed.
        cout << "Course selection confirmed." << endl << endl;
        int go;
        cout << "What would you like to do next\n";
        cout << "Please press 1 to go back to dashbord\n";
        cout << "Please press 2 to exit\n";
        cout << "Enter your choice: ";
        cin >> go;
        if (go == 1) {
            system("cls");
            dashboard();
        }
        else if (go == 2) {

            cout << "You have logged of the system\n\n\n\n";
        }
    }
    else if (confirm == "n" || confirm == "N" || confirm == "no" || confirm == "NO" || confirm == "No" || confirm == "nO") {
        // Your selection is not confirmed.
        cout << "Course selection cancelled." << endl << endl;
        string go;
        cout << "What would you like to do next?" << endl;
        cout << "1. Select courses again" << endl;
        cout << "2. Dashboard" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> go;

        if (go == "1") {
            system("cls");
            year1(); // go back to selection 
        }
        else if (go == "2") {
            system("cls");
            dashboard();
        }
        else if (go == "3") {
            cout << "Exiting program. Goodbye!\n\n" << endl;
        }
    }
}

// Choosinh year 2 lessons part
void year2() {
    cout << "WARNING: \n";

    cout << " Please select all the compulsory courses. [Yes or No] \n";
    cout << " You have 38 credits.\n";
    cout << " You can choose elective courses if you have enough credits[10 Credits]." << endl << endl;

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

    Course compulsoryCourses[compulsoryCount] =
    {
        {"OOP", "Object Oriented Programming", 6},
        {"DMS", "Discrete Mathematical Structures", 6},
        {"CO", "Computer Organization", 5},
        {"DS", "Data Structures", 6},
        {"DE", "Digital Electronics", 5}
    };

    Course electiveCourses[electiveCount] =
    {
        {"EE", "Environment and Energy", 3},
        {"EN", "Entrepreneurship", 4},
        {"CD", "Compiler Design", 2},
        {"PE", "Professional English", 2},
        {"POP", "The Principles Of Programming Languages", 3}
    };

    Course selectedCourses[compulsoryCount + electiveCount];
    int selectedCount = 0;

    // Choose compulsory courses for year 4
    for (int i = 0; i < compulsoryCount; i++) {
        bool selected = false;
        do {
            cout << "Select " << compulsoryCourses[i].name << " [" << compulsoryCourses[i].code << "] (Credits: " << compulsoryCourses[i].credits << "): ";
            string input;
            cin >> input;
            cin.ignore();
            if (input == "y" || input == "Y" || input == "yes" || input == "YES") {
                selectedCourses[selectedCount++] = compulsoryCourses[i];
                selected = true;
            }
            else if (input == "n" || input == "N" || input == "no" || input == "NO") {
                selected = true;
            }
            else {
                cout << "Invalid input. Please enter [y/n]." << endl;
            }
        } while (!selected);
    }

    // Return back , if all compulsory courses are not selected 
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
                    cout << "Invalid input. Please enter [y/n]." << endl;
                }
            } while (!selected);
        }
    }

    // Choosing elective courses for year 2
    cout << endl << "Select elective courses if you have enough credits [10 Credits] " << endl;

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
                cout << "Invalid input. Please enter [y/n]." << endl;
            }
        } while (!selected);
    }

    // Show selected courses
    system("cls");
    cout << endl << "Selected courses (Elective Courses (" << selectedCredits << " / 10 credits)):" << endl;
    for (int i = 0; i < selectedCount; i++) {
        cout << selectedCourses[i].code << " - " << selectedCourses[i].name << " (" << selectedCourses[i].credits << " credits)" << endl;
    }
    cout << endl;
    // Confirm your selection 
    if (confirmSelection()) {
        // Your selection is confirmed.
        cout << "Course selection confirmed." << endl << endl;
        int go;
        cout << "What would you like to do next\n";
        cout << "Please press 1 to go back to dashbord\n";
        cout << "Please press 2 to exit\n";
        cout << "Enter your choice: ";
        cin >> go;
        if (go == 1) {
            system("cls");
            dashboard();
        }
        else if (go == 2) {

            cout << "You have logged of the system\n\n\n\n";
        }
    }
    else {
        // Your selection is not confirmed.
        cout << "Course selection cancelled." << endl << endl;
        cout << "What would you like to do next?" << endl;
        cout << "1. Select courses again" << endl;
        cout << "2. Dashboard" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            system("cls");
            year2(); // go back to selection 

        }
        else if (choice == "2") {
            system("cls");
            dashboard();
        }
        else if (choice == "3") {
            cout << "Exiting program. Goodbye!\n\n" << endl;
        }
    }
}
// Lesson choosing for year 3 part
void year3() {

    cout << "You have 30 Credits in this semester." << endl << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "These are your compulsory subjects:" << endl;
    cout << "*   Artificial Intelligence(5 Credits)" << endl;
    cout << "*   Computer Architectures(3 Credits)" << endl;
    cout << "*   Java Programming(6 credits)" << endl;
    cout << "*   Data Analysis and Estimation Methods(5 credits)" << endl;
    cout << "*   Systems Biology(2 credits)" << endl << endl;
    cout << "NOTE: You do not have to choose these subjects." << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "These are your elective courses:" << endl;
    cout << "1   Robotics(3 credits)" << endl;
    cout << "2   Introduction to Data Science with Python(3 Credits)" << endl;
    cout << "3   Network Programming(3 Credits)" << endl;
    cout << "4   Digital Image Processing(3 Credits)" << endl;
    cout << "5   Software Requirements Engineering(3 Credits)" << endl << endl;
    cout << "NOTE: You have to choose 3 of them." << endl;
    cout << "----------------------------------------------------" << endl;

    int selectedCourses[3];
    int courseCount = 0;

    while (courseCount < 3) {
        cout << "Please select an elective course by entering its number (1-5): ";
        cin >> selectedCourses[courseCount];

        if (cin.fail()) {
            cout << "Error! Invalid input. Please enter a numeric course number." << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else if (selectedCourses[courseCount] >= 1 && selectedCourses[courseCount] <= 5) {
            bool alreadySelected = false;
            for (int j = 0; j < courseCount; j++) {
                if (selectedCourses[j] == selectedCourses[courseCount]) {
                    alreadySelected = true;
                    break;
                }
            }
            if (!alreadySelected) {
                courseCount++;
            }
            else {
                cout << "Error! You have already selected that course. Please select a different course." << endl << endl;
            }
        }
        else {
            cout << "Error! Invalid course number. Please try again." << endl << endl;
        }
    }
    system("cls");

    cout << endl << "Registration completed. Here are your courses:" << endl << endl;
    for (int j = 0; j < 3; j++) {
        if (selectedCourses[j] == 1) {
            cout << "Robotics(3 credits)" << endl;
        }
        else if (selectedCourses[j] == 2) {
            cout << "Introduction to Data Science with Python(3 Credits)" << endl;
        }
        else if (selectedCourses[j] == 3) {
            cout << "Network Programming(3 Credits)" << endl;
        }
        else if (selectedCourses[j] == 4) {
            cout << "Digital Image Processing(3 Credits)" << endl;
        }
        else if (selectedCourses[j] == 5) {
            cout << "Software Requirements Engineering(3 Credits)" << endl << endl;
        }
    }


    cout << "Artificial Intelligence(5 Credits)" << endl
        << "Computer Architectures(3 Credits)" << endl << "Java Programming(6 credits)"
        << endl << "Data Analysis and Estimation Methods(5 credits)" << endl
        << "Systems Biology(2 credits)" << endl << endl;

    // Confirm your selection 
    string confirm;
    cout << "Do you confirm your selection ? [yes/no]: ";
    cin >> confirm;
    if (confirm == "y" || confirm == "Y" || confirm == "yes" || confirm == "YES" || confirm == "Yes") {
        // Your selection is confirmed.
        cout << "Course selection confirmed." << endl << endl;
        int go;
        cout << "What would you like to do next\n";
        cout << "Please press 1 to go back to dashbord\n";
        cout << "Please press 2 to exit\n";
        cout << "Enter your choice: ";
        cin >> go;
        if (go == 1) {
            system("cls");
            dashboard();
        }
        else if (go == 2) {

            cout << "You have logged of the system\n\n\n\n";
        }
    }
    else if (confirm == "n" || confirm == "N" || confirm == "no" || confirm == "NO" || confirm == "No" || confirm == "nO") {
        // Your selection is not confirmed.
        cout << "Course selection cancelled." << endl << endl;
        string go;
        cout << "What would you like to do next?" << endl;
        cout << "1. Select courses again" << endl;
        cout << "2. Dashboard" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> go;

        if (go == "1") {
            system("cls");
            year3(); // go back to selection 
        }
        else if (go == "2") {
            system("cls");
            dashboard();
        }
        else if (go == "3") {
            cout << "Exiting program. Goodbye!\n\n" << endl;
        }
    }
}



// Year 4 part
void year4() {

    cout << "WARNING:" << endl;
    cout << " Please select the courses. [Yes or No]" << endl;
    cout << " If you have enough credits.[30 Credits]" << endl << endl;

    //Course table

    cout << setw(60) << setfill('-') << "" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "ALL " << setw(35) << setfill(' ') << left << "COURSES" << "|" << setw(10) << setfill(' ') << left << "CREDIT" << "|" << endl;
    cout << setw(60) << setfill('-') << "" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "IFA" << "|" << setw(35) << setfill(' ') << left << "Introduction to Fuzzy Logic" << "|" << setw(10) << setfill(' ') << left << "6" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "ES" << "|" << setw(35) << setfill(' ') << left << "Erp Systems" << "|" << setw(10) << setfill(' ') << left << "6" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "CNA" << "|" << setw(35) << setfill(' ') << left << "Complex Network Analysis" << "|" << setw(10) << setfill(' ') << left << "8" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "VT" << "|" << setw(35) << setfill(' ') << left << "Virualization Technologies" << "|" << setw(10) << setfill(' ') << left << "6" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "AN" << "|" << setw(35) << setfill(' ') << left << "Artificial Neural Networks" << "|" << setw(10) << setfill(' ') << left << "3" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "IGP" << "|" << setw(35) << setfill(' ') << left << "Introduction to Game Programming" << "|" << setw(10) << setfill(' ') << left << "3" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "DDA" << "|" << setw(35) << setfill(' ') << left << "Database Design and Applications" << "|" << setw(10) << setfill(' ') << left << "4" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "CYP" << "|" << setw(35) << setfill(' ') << left << "Cryptography" << "|" << setw(10) << setfill(' ') << left << "2" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "IE" << "|" << setw(35) << setfill(' ') << left << "Internet Engineering" << "|" << setw(10) << setfill(' ') << left << "2" << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << left << "ML" << "|" << setw(35) << setfill(' ') << left << "Machine Learning" << "|" << setw(10) << setfill(' ') << left << "3" << "|" << endl;
    cout << setw(60) << setfill('-') << "" << endl;

    const int coursesCount = 10;

    Course allCourses[coursesCount] = {
        {"IFA", "Introduction to Fuzzy Logic", 6},
        {"ES", "Erp Systems", 4},
        {"CNA", "Complex Network Analysis", 8},
        {"VT", "Virualization Technologies", 6},
        {"AN", "Artificial Neural Networks", 3},
        {"IGP", "Introduction to Game Programming", 3 },
        {"DDA", "Database Design and Applications", 4},
        {"CYP", "Cryptography", 2},
        {"IE", "Internet Engineering", 2},
        {"ML", "Machine Learning", 3}
    };

    Course selectedCourses[coursesCount];
    int selectedCount = 0;


    //Choosing lesson part

    int selectedCredits = 0;
    int MAX_CREDITS = 30;
    for (int i = 0; i < coursesCount; i++) {
        bool selected = false;
        do {
            cout << "Select " << allCourses[i].name << " [" << allCourses[i].code << "] (Credits: " << allCourses[i].credits << "): ";
            string input;
            cin >> input;
            cin.ignore();
            if (input == "y" || input == "Y" || input == "yes" || input == "YES") {
                if (selectedCredits + allCourses[i].credits > MAX_CREDITS) {
                    cout << "You have exceeded the maximum number of credits allowed." << endl;
                    continue;
                }
                selectedCourses[selectedCount++] = allCourses[i];
                selectedCredits += allCourses[i].credits;
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



    system("cls");
    // Show selected ones.
    cout << endl << "Selected courses (" << selectedCredits << " / 30 credits):" << endl;
    for (int i = 0; i < selectedCount; i++) {
        cout << selectedCourses[i].code << " - " << selectedCourses[i].name << " (" << selectedCourses[i].credits << " credits)" << endl;
    }

    cout << endl;
    // Confirm your selection 
    if (confirmSelection()) {
        // Your selection is confirmed.
        cout << "Course selection confirmed." << endl << endl;
        int go;
        cout << "What would you like to do next\n";
        cout << "Please press 1 to go back to dashbord\n";
        cout << "Please press 2 to exit\n";
        cout << "Enter your choice: ";
        cin >> go;
        if (go == 1) {
            system("cls");
            dashboard();
        }
        else if (go == 2) {

            cout << "You have logged of the system\n\n\n\n";
        }
    }
    else {
        // Your selection is not confirmed.
        cout << "Course selection cancelled." << endl << endl;
        cout << "What would you like to do next?" << endl;
        cout << "1. Select courses again" << endl;
        cout << "2. Dashboard" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        string choice;
        getline(cin, choice);

        if (choice == "1") {
            system("cls");
            year4(); // go back to selection 

        }
        else if (choice == "2") {
            system("cls");
            dashboard();
        }
        else if (choice == "3") {
            cout << "Exiting program. Goodbye!\n\n" << endl;
        }
    }
}

// Login Part
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

void dashboard();

void AllYearsInfo() {

    system("cls");
    int yearNum;
    cout << "Which year's lessons would you like to see ? [1-4]:  ";
    cin >> yearNum;

    switch (yearNum) {
    case 1:

        cout << "\n" << "YEAR " << yearNum << "\n\n";
        cout << "-----------------------------------------------------------------------------------\n";
        cout << "|   AP    " << "   Algorithms and Programming                              " << " Credits " << " 3  |\n";
        cout << "|   IT    " << "   Information Technologies                                " << " Credits " << " 2  |\n";
        cout << "|   ECF   " << "   Electrical Circuit Fundamentals                         " << " Credits " << " 3  |\n";
        cout << "|   MTH   " << "   Mathematics                                             " << " Credits " << " 4  |\n";
        cout << "|   PHY   " << "   Physics                                                 " << " Credits " << " 4  |\n";
        cout << "|   WT    " << "   Web Technologies                                        " << " Credits " << " 3  |\n";
        cout << "|   PS    " << "   Probability and Statistics                              " << " Credits " << " 3  |\n";
        cout << "|   CE    " << "   Introducton to Computer Engineering                     " << " Credits " << " 2  |\n";
        cout << "|   AI    " << "   Academic English  [Selected]                            " << " Credits " << " 2  |\n";
        cout << "|   CP    " << "   Career Planning   [Selected]                            " << " Credits " << " 2  |\n";
        cout << "|   TL    " << "   Turkish Language  [Selected]                            " << " Credits " << " 2  |\n";
        cout << "|   AHT   " << "   ATATURK's History [Selected]                            " << " Credits " << " 2  |\n";
        cout << "-----------------------------------------------------------------------------------\n\n";

        break;

    case 2:
        cout << "\n" << "YEAR " << yearNum << "\n\n";

        cout << "-----------------------------------------------------------------------------------\n";
        cout << "|  OPP  " << "  Object Oriented Programming                                " << " Credits " << " 6  |\n";
        cout << "|  DMS  " << "  Discrete Mathematical Structures                           " << " Credits " << " 6  |\n";
        cout << "|  CO   " << "  Computer Organization                                      " << " Credits " << " 5  |\n";
        cout << "|  DS   " << "  Data Structures                                            " << " Credits " << " 6  |\n";
        cout << "|  DE   " << "  Digital Electronics                                        " << " Credits " << " 5  |\n";
        cout << "|  EE   " << "  Environment And Energy                    [Selected]       " << " Credits " << " 3  |\n";
        cout << "|  E    " << "  Entrepreneurship                          [Selected]       " << " Credits " << " 4  |\n";
        cout << "|  CD   " << "  Compiler Design                           [Selected]       " << " Credits " << " 2  |\n";
        cout << "|  PE   " << "  Professional English                      [Selected]       " << " Credits " << " 2  |\n";
        cout << "|  POP  " << "  The Principles of Programming Languages   [Selected]       " << " Credits " << " 3  |\n";
        cout << "-----------------------------------------------------------------------------------\n\n";

        break;

    case 3:
        cout << "\n" << "YEAR " << yearNum << "\n\n";

        cout << "-----------------------------------------------------------------------------------\n";
        cout << "|  AI   " << "  Artificial Intelligence                                     " << " Credits " << " 5  |\n";
        cout << "|  CA   " << "  Computer Architectures                                      " << " Credits " << " 3  | \n";
        cout << "|  JP   " << "  Java Programming                                            " << " Credits " << " 6  |\n";
        cout << "|  DA   " << "  Data anlysis And Estimation methods                         " << " Credits " << " 5  |\n";
        cout << "|  SB   " << "  System biology                                              " << " Credits " << " 2  |\n";
        cout << "|  RT   " << "  Robotics                                  [Selected]        " << " Credits " << " 3  |\n";
        cout << "|  IDP  " << "  Introduction to Data Science With Python  [Selected]        " << " Credits " << " 3  |\n";
        cout << "|  NP   " << "  Network Programming                       [Selected]        " << " Credits " << " 3  |\n";
        cout << "|  DIP  " << "  Digital Image Processing                  [Selected]        " << " Credits " << " 3  |\n";
        cout << "|  SRE  " << "  Software Requirements Engineering         [Selected]        " << " Credits " << " 3  |\n";
        cout << "-----------------------------------------------------------------------------------\n\n";


        break;

    case 4:
        cout << "\n" << "YEAR " << yearNum << "\n\n";

        cout << "-----------------------------------------------------------------------------------\n";
        cout << "|  IGP  " << "  Introduction to Game Programming                           " << " Credits " << " 3  |\n";
        cout << "|  IFA  " << "  Introduction to Fuzzy Logic                                " << " Credits " << " 6  |\n";
        cout << "|  ANN  " << "  Artificial Neural Networks                                 " << " Credits " << " 3  |\n";
        cout << "|  ES   " << "  Erp Systems                                                " << " Credits " << " 4  |\n";
        cout << "|  CNA  " << "  Complex Network Analysis                                   " << " Credits " << " 8  |\n";
        cout << "|  VT   " << "  Virualization Technologies                                 " << " Credits " << " 6  |\n";
        cout << "|  DDA  " << "  Database Design and Applications                           " << " Credits " << " 4  |\n";
        cout << "|  CYP  " << "  Cryptography                                               " << " Credits " << " 2  |\n";
        cout << "|  IE   " << "  Internet Engineering                                       " << " Credits " << " 2  |\n";
        cout << "|  ML   " << "  Machine Learning                                           " << " Credits " << " 3  |\n";
        cout << "-----------------------------------------------------------------------------------\n\n";

        break;

    default:

        system("cls");

        cout << "\n***Invalid semester number.***\n" << endl;

        AllYearsInfo();
        break;
    }

}

void loginpage();

void choosing() {
    string choicethree;

    cout << "Which year do you want to take courses? [1-4]\n";
    cout << "Year: ";
    cin >> choicethree;
    if (choicethree == "1") {
        system("cls");
        year1();
    }
    else if (choicethree == "2") {
        system("cls");
        year2();
    }
    else if (choicethree == "3") {
        system("cls");
        year3();
    }
    else if (choicethree == "4") {
        system("cls");
        year4();
    }
    else {
        system("cls");
        cout << " Invalid input. Please enter valid input.\n\n ";
        choosing();
    }
}

// Dashboard part 
void dashboard() {

    string choiceTwo;
    cout << "\t_______________________________________" << endl;
    cout << "\t______________*DASHBOARD*______________" << endl;
    cout << endl;
    cout << "      || Please press 1 to  SEE LESSON PLAN    ||\n";
    cout << "      || Please press 2 for CHOOSING COURSES   ||\n";
    cout << "      || Please press 3 to  BACK TO LOGIN MENU ||\n";
    cout << "      || please press 4 to  QUIT               ||\n\n";
    cout << "      Enter your choice: ";
    cin >> choiceTwo;
    cout << "\n\n\n";

    if (choiceTwo == "1")
    {
        AllYearsInfo();

        cout << "|Press 1 to go back to Dashboard| \n";
        cout << "|Press 2 to Exit| \n";
        cout << "Enter your choice: ";

        string godash;
        cin >> godash;
        if (godash == "1") {
            system("cls");
            dashboard();
        }
        else if (godash == "2") {

            cout << "\n" << "You have logged out the system.  \n\n";
        }
    }
    else if (choiceTwo == "2")
    {
        choosing();
    }
    else if (choiceTwo == "3")
    {
        system("cls");
        loginpage();
    }
    else if (choiceTwo == "4")
    {
        cout << "you have logged of the system";
    }
    else {
        system("cls");
        cout << " WARNING!!!\n\n";
        cout << " Invalid input. Please enter valid input.\n ";
        dashboard();
    }
}


void loginpage() {  //LOGIN PAGE FUNCTÄ°ON 

    string choice;
    cout << endl;
    cout << "\t_________________________________________________________________________________________________\n";
    cout << "\t                                       WELCOME TO LOGIN PAGE                                     \n\n";
    cout << "\t______________________                        MENU                      _________________________\n\n\n";

    cout << "       || Please press 1 to LOGIN          ||\n";
    cout << "       || Please press 2 to REGISTER       ||\n";
    cout << "       || Please press 3 to EXIT           ||\n\n";
    cout << "\t     Enter your choice: ";
    cin >> choice;
    cout << "\n\n\n";

    if (choice == "1") {

        bool situation = login();
        if (!situation)
        {
            system("cls"); // TO CLEAR PAGE 
            cout << endl;
            cout << "Passsword or username is incorrect, Try again! " << endl;
            loginpage();
        }
        else
        {
            system("cls");
            dashboard();
        }
    }

    else if (choice == "2") {

        string Username, Password;

        cout << "*Registration: *" << endl;
        cout << "Select a username: "; cin >> Username;
        cout << "Select a password: "; cin >> Password;

        ofstream file; // OPEN FILE STREAM, CREATES A FILE 
        file.open(Username + ".txt");
        file << Username << endl << Password;
        file.close();
        cout << "Welcome  " << Username << "  !" << endl;
        system("cls");
        loginpage();

    }
    else if (choice == "3") {

        cout << "You have logged of the system \n\n\n";
    }

    else {
        system("cls");
        cout << "\t -----WARNING----- \n\n";
        cout << " Invalid input. Please enter valid input. ";

        loginpage();
    }
}

int main() {

    loginpage();
}