/* Program name: jbtictactoe.cpp
* Author: Chad Carmickle
* Date last updated: 9/15/2026
* Purpose: Product list by Desc, Price, Rating, 
*/


#include <iostream>
#include <fstream>
#include "unorderedLinkedList.h"
#include "product.h"
#include <string> 
#include <limits>

int compareDesc(product &item1, product &item2); 
int comparePrice(product &item1, product &item2);
int compareRating(product &item1, product &item2);

// Compares the first item to the second. 
int compareDesc(product &item1, product &item2)
{
    if (item1.getDescription() < item2.getDescription())
    {
        return -1;
    }
    else if (item1.getDescription() == item2.getDescription())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


// Compares the first item to the second. 
int comparePrice(product &item1, product &item2)
{
    if (item1.getPrice() < item2.getPrice())
    {
        return -1;
    }
    else if (item1.getPrice() == item2.getPrice())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Compares the first item to the second.
int compareRating(product &item1, product &item2)
{
        if (item1.getRating() < item2.getRating())
    {
        return -1;
    }
    else if (item1.getRating() == item2.getRating())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
        // Creates the three objects. 
        UnorderedLinkedList<product> listByPrice;
        UnorderedLinkedList<product> listByDescription;
        UnorderedLinkedList<product> listByRating;

        // Loads the file. 
        std::ifstream inputFile("products.txt");

        
        // Attempts to open the file. 
        if (!inputFile)
        {
            std::cout << "Error opening products.txt." << std::endl;
            return 1;
        }

        // temp variables to hold the data of the file. 
        double price;
        std::string description;
        std::string productNumber;
        double rating;

        while (inputFile >> price)
    {
        inputFile.ignore();
     
        // Clears out the rest of the line line of the input file before getline. 
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        // get the line of the input. 
        getline(inputFile, description);

        // Places the info into variables. 
        inputFile >> productNumber;
        inputFile >> rating;
        
        // Creates the product Oject. 
        product newProduct(price, description, productNumber, rating);


        // Inserts each of the data into the list. 
        listByDescription.insert(newProduct);
        listByPrice.insert(newProduct);
        listByRating.insert(newProduct);

    }
    // Now we add the objects into the mergeSort calling each of the other functions inside. 
    listByDescription.MergeSort(compareDesc);
    listByPrice.MergeSort(comparePrice);
    listByRating.MergeSort(compareRating);



    std::cout << std::endl;
    std::cout << "original list for ordering by description: " << std::endl;
    listByDescription.print(std::cout, "\n"); // prints all of the items in the list and uses \n as the separator character.
    std::cout << std::endl
              << std::endl;
    std::cout << "original list for ordering by Price: " << std::endl;
    listByPrice.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;
    std::cout << "original list for ordering by rating" << std::endl;
    listByRating.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;
/* 
    merge sort the 3 lists
    Don't forget to modify UnorderedLinkedList.h to add the merge sort functionality.
*/ 

    std::cout << "mergeSorted by description product list: " << std::endl;
    listByDescription.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;
    std::cout << "mergeSorted by price product list: " << std::endl;
    listByPrice.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;

    std::cout << "mergeSorted by rating product list: " << std::endl;
    listByRating.print(std::cout, "\n");
    std::cout << std::endl
              << std::endl;

    return 0;
}
