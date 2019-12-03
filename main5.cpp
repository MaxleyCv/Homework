#include <iostream>
#include <math.h>

class Vector{
private:
    int containedArray[5];
public:
    void setNextVectorElement(int element){    //A method implements setting the next or the first element of the array
        static int position = 0;
        this -> containedArray[position] = element;
        if (position == 4) position = -1;
        position++;
    }

    int multiplyAllElements(){
        int result = 1;
        for (int i = 0; i< 5; i++){
            result *= containedArray[i];
        }
        return result;
    }

    int* getContainedArray(){
        return containedArray;
    }
    void setArrayElementAtPosition(int position){

        std::cin >> this -> containedArray[position];

    }
    friend void printArray(Vector* array, int numberOfElements);

    void merge(int startFlag, int middlePosition, int endFlag) {
        int currentArray[5];
        int leftPosition = startFlag, rightPosition = middlePosition + 1, iteration = 0;

        while(leftPosition <= middlePosition && rightPosition <= endFlag) {
            if(this -> containedArray[leftPosition] <= this -> containedArray[rightPosition]) {
                currentArray[iteration] = this -> containedArray[leftPosition];
                iteration += 1; leftPosition += 1;
            }
            else {
                currentArray[iteration] = this -> containedArray[rightPosition];
                iteration += 1; rightPosition += 1;
            }
        }

        while(leftPosition <= middlePosition) {
            currentArray[iteration] = this -> containedArray[leftPosition];
            iteration += 1; leftPosition += 1;
        }

        while(rightPosition <= endFlag) {
            currentArray[iteration] = this -> containedArray[rightPosition];
            iteration += 1; rightPosition += 1;
        }

        // copy temp to original interval
        for(leftPosition = startFlag; leftPosition <= endFlag; leftPosition += 1) {
            this -> containedArray[leftPosition] = currentArray[leftPosition - startFlag];
        }
    }

    void mergeSort(int startPosition, int endPosition) {

        if(startPosition < endPosition) {
            int middleFlag = (startPosition + endPosition) / 2;
            mergeSort(startPosition, middleFlag);
            mergeSort(middleFlag + 1, endPosition);
            merge(startPosition, middleFlag, endPosition);
        }

    }
};

void printArray(Vector* array, int numberOfElements){
    for(int position = 0; position < numberOfElements; ++position)
    {
        std::cout << array -> containedArray[position];
    }
    std::cout << std::endl;
}




int main() {
    Vector matrixRows[5];
    for (int rowNumber = 0; rowNumber < 5; rowNumber++)
        for (int columnNumber = 0; columnNumber < 5; columnNumber++){
            matrixRows[columnNumber].setArrayElementAtPosition(rowNumber);
        }
    Vector matrixColumns;
    Vector functionResultsOfMultipliedElements;
    for (int rowNumber = 0; rowNumber < 5; rowNumber++)
        matrixRows[rowNumber].mergeSort(0, 4);
    for (int columnNumber = 0; columnNumber < 5; columnNumber++){
        for (int rowNumber = 0; rowNumber < 5; rowNumber++) {
            std::cout << matrixRows[rowNumber].getContainedArray()[columnNumber] << "\t ";
            matrixColumns.setNextVectorElement(matrixRows[rowNumber].getContainedArray()[columnNumber]);
        }
        functionResultsOfMultipliedElements.setNextVectorElement(matrixColumns.multiplyAllElements());
        std::cout << std::endl;
    }
    std::cout << "f[i]" << std::endl;
    double summOfTheFunctionResults = 0;
    for (int rowNumber = 0; rowNumber < 5; rowNumber++) {
        summOfTheFunctionResults += pow(abs(functionResultsOfMultipliedElements.getContainedArray()[rowNumber]), 0.2);
        std::cout << pow(abs(functionResultsOfMultipliedElements.getContainedArray()[rowNumber]), 0.2) << " ";
    }
    std::cout << std::endl;
    std::cout << "F(f[i]): \n" << summOfTheFunctionResults / 5 << std::endl;
    return 0;
}


