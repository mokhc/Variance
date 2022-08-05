// @mokhc
// Variance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// program demonstrates the calculation of variance
// headers
#include <iostream>
#include <valarray>

//std namespace needed for valarray
using namespace std;

//class to get input and calculate variance
class CalVarVal {
//access modifier
public:
    //variables
    valarray<double> inputval;
    valarray<double> coninput;
    valarray<double> meansub;
    valarray<double> sqmeansub;
    int sizeofarray;
    double totalval, meanval, conmeanval, totalconval, totalmeansub, varval;
    
    //constructor
    CalVarVal() {

    }

    //constructor with parameter
    //calculation of variance is determined
    CalVarVal(valarray<double> input) {
        //assignment
        this->inputval = input;
        this->sizeofarray = input.size();
        //initialization
        totalval = meanval = conmeanval = totalconval = totalmeansub = varval = 0.0;
        coninput.resize(sizeofarray);
        meansub.resize(sizeofarray);
        sqmeansub.resize(sizeofarray);
        //calculating the variance
        for (int a = 0; a < inputval.size(); a++) {
            totalval = totalval + inputval[a];
        }
        meanval = totalval / sizeofarray;
        for (int a = 0; a < inputval.size(); a++) {
            coninput[a] = inputval[a] * meanval;
        }
        for (int a = 0; a < inputval.size(); a++) {
            totalconval = totalconval + coninput[a];
        }
        conmeanval = totalconval / sizeofarray;
        for (int a = 0; a < inputval.size(); a++) {
            meansub[a] = conmeanval - coninput[a];
        }
        for (int a = 0; a < inputval.size(); a++) {
            sqmeansub[a] = pow(meansub[a], 2);
        }
        for (int a = 0; a < inputval.size(); a++) {
            totalmeansub = totalmeansub + sqmeansub[a];
        }
        varval = totalmeansub / totalconval;
    }

    //method to get input and calculate variance
    void CalVarValueMethod(valarray<double> input) {
        //assignment
        this->inputval = input;
        this->sizeofarray = input.size();
        //initialization
        totalval = meanval = conmeanval = totalconval = totalmeansub = varval = 0.0;
        coninput.resize(sizeofarray);
        meansub.resize(sizeofarray);
        sqmeansub.resize(sizeofarray);
        //calculating the variance
        for (int a = 0; a < inputval.size(); a++) {
            totalval = totalval + input[a];
        }
        this->meanval = totalval / sizeofarray;
        for (int a = 0; a < inputval.size(); a++) {
            coninput[a] = input[a] * meanval;
        }
        for (int a = 0; a < inputval.size(); a++) {
            totalconval = totalconval + coninput[a];
        }
        conmeanval = totalconval / sizeofarray;
        for (int a = 0; a < inputval.size(); a++) {
            meansub[a] = conmeanval - coninput[a];
        }
        for (int a = 0; a < inputval.size(); a++) {
            sqmeansub[a] = pow(meansub[a], 2);
        }
        for (int a = 0; a < inputval.size(); a++) {
            totalmeansub = totalmeansub + sqmeansub[a];
        }
        this->varval = totalmeansub / totalconval;
    }

    //method to get calculated variance
    void GetVarValue() {
        cout << "The variance is : " << varval << endl;;
    }

    //method to get input value
    void GetInputVal() {
        for (int a = 0; a < sizeofarray; a++) {
            cout << "Input " << a << " : " << inputval[a] << endl;
        }
    }

};

int main()
{
    //input values
    valarray<double> input = { 2,3,4,6 };
    //declaration
    CalVarVal c1;
    //assignment
    c1 = CalVarVal(input);
    //calling method(s)
    c1.GetInputVal();
    c1.GetVarValue();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
