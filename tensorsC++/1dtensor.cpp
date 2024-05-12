#include <iostream>
#include <vector>

void elementPrinter(std::vector<auto> tensor) {
    for (auto i : tensor) {
        std::cout << "Element: " << i << std::endl;
    }
}

int main (void){

	// One method by forcefully filling value
	std::vector<int> OneDimTensor = {1, 2, 3, 4, 5};
	elementPrinter(OneDimTensor);
	std::cout << "Size of our 1-d tensor is: " << OneDimTensor.size()<< std::endl;
	
	// Second method using new keyword
	std::vector<double> OneDimTensor2(9);
	int iter = 0;
	for (auto i: OneDimTensor2){
		OneDimTensor2[iter] = iter * 10;
		iter += 1;
	}
	elementPrinter(OneDimTensor2);
	std::cout << "Size of our 1-d tensor is " << OneDimTensor2.size() << std::endl;
	
	return 0;
}	
