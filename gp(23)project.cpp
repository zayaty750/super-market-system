/*
Create an application for a supermarket owner. The owner would like to store up to 50 items. Each item is represented by an ID and a price.
The program should ask the user if he/she wants to do one of the following
tasks:-
1. Enter an item ID and price
2. Retrieve the price of a specific item
3. Display all items within a specific range of prices
4. Delete an item
5. Display all items
6. Delete all items
*/

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

int itemID[50];
double itemPrice[50];
bool itemIsEmpty[50];//check if the array is empty or not 

void deletesameidnumbers(int id) {
   
    for (int i = 0; i < 50; i++) {
        if ( id == itemID[i+1] ) {

            itemIsEmpty[i+1] = true;
        }
    }
}
//rearange the data
void swap_by_ascendingorder()
{
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 49; j++)
        {
            bool swap_itemisempty;
            int swap_itemid;
            double swap_itemprice;
            if (itemPrice[j] > itemPrice[j + 1] && itemID[j] > itemID[j + 1])//if the item price greater than the item price after it 
            {
                swap_itemisempty = itemIsEmpty[j];//save the smaller value in the new array called "swap_itemisempty" and then save the bigger value in the smaller value array then save the array called"swap_itemisempty" in the large array  
                itemIsEmpty[j] = itemIsEmpty[j + 1];
                itemIsEmpty[j + 1] = swap_itemisempty;

                swap_itemid = itemID[j];//save the smaller value in the new array called "swap_itemid" and then save the bigger value in the smaller value array then save the array called"swap_itemid" in the large array  
                itemID[j] = itemID[j + 1];
                itemID[j + 1] = swap_itemid;

                swap_itemprice = itemPrice[j];//save the smaller value in the new array called "swap_itemprice" and then save the bigger value in the smaller value array then save the array called"swap_itemprice" in the large array  
                itemPrice[j] = itemPrice[j + 1];
                itemPrice[j + 1] = swap_itemprice;
            }
        }
}

//menu
void showMenu()
{
    string menuItems[] = { "1- Enter", "2- Find by id", "3- Find range", "4- Del Item", "5- Display all", "6- Del All","7- enter {e} to exit the program "};//open array with unlimited number of arrays and saved in it the data
    cout <<endl <<"********************************" << endl;
    cout << "NOTE:- dont enter same id numbers, it will be deleted!!"<<endl;
    for (int i = 0; i < 7; i++) {
        cout << menuItems[i] << endl;//display the data in menuitems
    }
    cout <<"********************************" << endl;
}  

//step (1) :- Enter an item ID and price
void enterItem()
{
    bool condition;
    int ndx = 0;
    int id;
    double price;
    while (ndx < 50 && itemIsEmpty[ndx] == false) ndx++;// the loop continue if the number of arrays is less than 50 and the item id and price isnt empty
    if (ndx < 50)
    {
        cout << "# item ID: ";
        cin >> id;
        cout << "# item price: ";
        cin >> price;
        itemPrice[ndx] = price;
        itemID[ndx] = id;
        itemIsEmpty[ndx] = false;
        deletesameidnumbers(id);
        cout << "<items are saved.>" << endl;
        swap_by_ascendingorder();// sort the items by ascending order for "item id","item price" ,and "item is empty" arrays
        
    }
     else cout << "<No More Positions.>" << endl;// if the ndx>50 print that is there is no more postion to save in it
   
}

//step (2) :- Retrieve the price of a specific item
void findItemById()
{
    int ndx = 0, id;
    cout << "item ID: ";
    cin >> id;//user enter the id that he wants to find the price of the item
    while (ndx < 50 && itemID[ndx] != id) ndx++;// loop continue if the numbers of arrays is less than 50 and the itemid is equal to the id that the user enterd 
    if (ndx < 50)
    {
        cout << "Price : " << itemPrice[ndx] << endl;
    }
    else cout << "<Item is not found.>" << endl;//print item is not found if the id that the user enterd is not saved in the array
}

//step (3) :- Display all items within a specific range of prices                       
void findItemsByRange()
{
    bool condition;
    int ndx = 0;
    double lowPrice, highPrice;
    cout << "# Lower Price: ";
    cin >> lowPrice;
    cout << "# Higher Price: ";
    cin >> highPrice;
    while (ndx < 50)//continue if the numbers of array is less than 50
    {
        if (!itemIsEmpty[ndx] && (itemPrice[ndx] >= lowPrice) && (itemPrice[ndx] <= highPrice))// if the item isnt empty and the item price>=lowprice and itemprice<= highprice
        {
            cout << "# ID : " << itemID[ndx] << endl;
            cout << "# Price : " << itemPrice[ndx] << endl << endl;
            condition = true;
        }
        else {
            condition = false;
        }
        ndx++;
    }if (condition == false) {
        cout << "<no prices between these range.>"<<endl;
    }

}

//step (4) :- Delete an item
void deleteItem()
{
    int ndx = 0, id;

    cout << "# item ID: ";
    cin >> id;
    while (ndx < 50 && itemID[ndx] != id) ndx++;// the loop continue if the number of arrays is less than 50 and the "id" that the user entered is the same in the "itemid"
    if (ndx < 50)
    {
        itemIsEmpty[ndx] = true;//the item is deleted
        cout << "<Item is deleted.>"<<endl;
    }
    else cout << "<Item is not found.>" << endl;//if the id isnot found so print item isnot found
}

//step (5) :- Display all items
void displayAllItems()
{
    bool condition;
    for (int i = 0; i < 50; i++)//run from 0 to 49 to check the arrays between 
    {

        if (!itemIsEmpty[i]) {// check if the item is not empty and print the arrays that contain values only  
            cout << "# ID : " << itemID[i] << endl;// print all the item id from 0 to 49
            cout << "# Price : " << itemPrice[i] << endl << endl;//print all the item price from 0 to 49
            condition = true;
        }
        else {
            condition = false;
        }
    }if (condition == false) {
        cout << "<No items to display!!>" << endl;
    }
}

//step (6) :- Delete all items
void deleteall()
{
    for (int i = 0; i < 50; i++) {   //run the array from 0 to 49 
        itemIsEmpty[i] = true; //make the values in the array called "itemisempty" is all empty and can save in it a new values
    }

}

int main()
{
    bool done = false;
    char option;
    deleteall();
    do {
        showMenu();
        cout << "# enter your choice :- ";
        cin >> option;
        switch (option)
        {
        case '1': enterItem(); // if the user entered 1 so he is able to enter new item id and new item price
            break;
        case '2': findItemById(); //if the user entered 2 so he is able to find item prices by entering its id  
            break;
        case '3': findItemsByRange(); //if the user entered 3 so he is able to to see the range of the prices by ascending order
            break;
        case '4': deleteItem(); //if the user entered 4 so he is able to enter item id then deletes it after
            break;
        case '5': displayAllItems(); //if the user entered 5 so he is able to see all item id and items price that he entered
            break;
        case '6': deleteall();
            cout << "<all items is deleted.>"<<endl;//if the user entered 6 so all data will be deleted
            break;
        case 'e': done = true; //if the user entered e so he will exit the program
            break;
        default:cout << endl << "the option you choosed isn't found!!" << endl << "SO Please Enter 1-6 or e to exit." << endl;
            break;
        }

    } while (!done);//the loop will continue if done array is equal to false 
    return 0;
}