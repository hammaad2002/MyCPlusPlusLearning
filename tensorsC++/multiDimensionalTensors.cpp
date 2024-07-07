#include <iostream>
#include <vector>
#include <random>

int main ()
{
    // of shape (5,) with all elements = 2
    std::vector<int> OneDimTensor (5, 2); 
    
    // of shape (2, 3) with all elements = 0
    std::vector<std::vector<int>> TwoDimTensor (2, std::vector<int> (3, 0));
    
    // of shape (2, 2, 2) with all elements = 0
    std::vector<std::vector<std::vector <int>>> ThreeDimTensor (2, std::vector<std::vector <int>> (2, std::vector <int> (2, 0)));
    
    std::cout << "Printing 1 dimensional tensor \n\n";
    
    for (auto i: OneDimTensor)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n' << '\n';
    
    std::cout << "Printing 2 dimensional tensor \n\n";
    
    for (std::vector<int> i: TwoDimTensor)
    {
        for (int j: i)
        {
            std::cout << j << ' ';
        }
        
        std::cout << '\n';
    }
    
    std::cout << "\nPrinting 3 dimensional tensor \n\n";
    
    for (auto i: ThreeDimTensor)
    {
        for (auto j: i)
        {
            for (auto k: j)
            {
                std::cout << k << ' ';
            }
            
            std::cout << '\n';
        }
        std::cout << "-\n";
    }

  return 0;
}