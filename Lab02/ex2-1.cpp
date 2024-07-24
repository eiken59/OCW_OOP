#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

const int MAX = 10000;

class student {
    private:
        string ID;
        string name;
        int problemsScore[9];
        int score;
        int requiredTime;
    public:
        friend void swap(student&, student&);
        student();
        student(string, string, int [9], int);
        string getName();
        string getID();
        int getScore();
        int getRequiredTime();
        void operator=(const student&);
};

bool isNotLessThan(student, student);
void PrintList(student[], int);

int main() { //int argc, char ** argv
    student listOfStudents[MAX];
    int n = 0;
    string tempID, tempName;
    int tempScores[9], tempRequiredTime;

    ifstream fin;
    fin.open("score.txt");
    while (fin >> tempID) {
        fin >> tempName;
        for (int i = 0; i < 9; i++) {
            fin >> tempScores[i];
        }
        fin >> tempRequiredTime;
        listOfStudents[n] = student(tempID, tempName, tempScores, tempRequiredTime);
        n++;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!isNotLessThan(listOfStudents[i], listOfStudents[j])) swap(listOfStudents[i], listOfStudents[j]);
        }
    }
    PrintList(listOfStudents, n);
}

student::student() {
    ID = "00";
    name = "Unknown";
    score = 0;
    for (int i = 0; i < 9; i++) {
        problemsScore[i] = 0;
    }
    requiredTime = 0;
}

student::student(string newID, string newName, int newScores[9], int newTime) {
    ID = newID;
    name = newName;
    for (int i = 0; i < 9; i++) {
        problemsScore[i] = newScores[i];
    }
    score = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            score += (i + 1) * newScores[3 * i + j] * 10;
        }
    }
    score = min(100, score);
    requiredTime = newTime;
}

string student::getName() {
    return name;
}

string student::getID() {
    return ID;
}

int student::getScore() {
    return score;
}

int student::getRequiredTime() {
    return requiredTime;
}

void student::operator=(const student &rightObj) {
    ID = rightObj.ID;
    name = rightObj.name;
    for (int i = 0; i < 9; i++) {
        problemsScore[i] = rightObj.problemsScore[i];
    }
    score = rightObj.score;
    requiredTime = rightObj.requiredTime;
}

void PrintList(student stdtList[], int numberOfStudents) {
    for (int i = 0; i < numberOfStudents; i++) {
        cout << stdtList[i].getID() << " " << stdtList[i].getName()
             << " " << stdtList[i].getScore() << " "
             << stdtList[i].getRequiredTime() << endl;
    }
}

void swap(student &stdt1, student &stdt2) {
    student tempStdt = stdt1;
    stdt1 = stdt2;
    stdt2 = tempStdt;
}

//Returns true if `stdt1` is not less than `stdt2`.
bool isNotLessThan(student stdt1, student stdt2) {
    if (stdt1.getScore() > stdt2.getScore()) {
        return true;
    }
    else if (stdt1.getScore() == stdt2.getScore()) {
        if (stdt1.getRequiredTime() <= stdt2.getRequiredTime()) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}