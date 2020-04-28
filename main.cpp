/*
 Name: Alec Garza
 Program Status: Complete
 
 This program utilizes pointer notation and dynamic memory allocation to
 calculate the average test score from data stored in an array. The user inputs the
 number of students in the class, then an array is declared by dynamic memory allocation.
 The individual scores and final class average are then displayed in table format.
 
 */

#include <iostream>
#include <string>
using namespace std;


//function that prompts user for student grades
//input: array pointer, size of array
//processing: prompt user for grades and assign to array using pointer notation
//output: return array containing floating point values for student grades
float inputStudentGrades(int *grades, int size){
    int num = 1;
    //store student grades in array using pointer notation and count-controlled loop
    for(int i = 0; i < size; i++){
        cout << "Enter grade for student number " << num << ": " << endl;
        cin >> *(grades+i);
        num++;
    }
    
    return *grades;
}

//function that uses bubble sort method to sort array in ascending order
//input: grades array pointer, array size
//processing: swap values if value1 is greater than value2 to sort array in ascending order
//output: none
void sortArray(int *grades, int size){
    float temp;
    bool swap;
    
    
    do{
        swap = false;
        for(int i = 0; i<size-1; i++){
            if(*(grades+i) > *(grades+(i+1))){
                temp = *(grades+i);
                *(grades+i) = *(grades+(i+1));
                *(grades+i+1) = temp;
                swap = true;
            }
        }
    }while(swap);
    
    cout << "\n";
    
    
}

float classAvg(int *grades, int size){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += *(grades+i);
    }
    return total/size;
}

void displayOutput(int *grades, int size, float avg){
    cout << "Grade" << endl;
    cout << "-----" << endl;
    
    for(int i = 0; i < size; i++){
        cout << *(grades+i) << endl;
    }
    
    cout << "-----" << endl;
    cout << avg;
}

int main() {
    int numStudents; //variable to represent number of students
    int *studentGrades; //array to hold student grades
    float avg; //floating point variable to represent class averages
    
    //prompt user for number of students
    cout << "How many students are in the class?" << endl;
    cin >> numStudents;
    
    cout << "\n";
    
    //use dynamic allocation to declare array
    studentGrades = new int[numStudents];
    
    //function call to get student grades and store in array
    inputStudentGrades(studentGrades, numStudents);
    
    //function call to sort array
    sortArray(studentGrades, numStudents);
    
    cout << "\n";

    //function to call to calculate class average
    avg = classAvg(studentGrades, numStudents);
    
    //function call to display output
    displayOutput(studentGrades, numStudents, avg);
    cout << "\n";
    

}
