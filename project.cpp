#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
enum OS { OS_0 = 0, iOS = 1, Android = 2, Windows_phone = 3 };
enum Ram { R_0 = 0, R_2GB = 2, R_4GB = 4, R_6GB = 6, R_8GB = 8, R_12GB = 12, R_16GB = 16, R_32GB = 32, R_64GB = 64 };
enum Storage { S_0 = 0, S_16GB = 16, S_32GB = 32, S_64GB = 64, S_128GB = 128, S_256GB = 256, S_512GB = 512, S_1TB = 1000, S_2TB = 2000 };
enum Color { color_0 = 0, white = 1, blue = 2, black = 3, red = 4, yellow = 5, green = 6, purple = 7, others = 8 };
struct phone
{
	char name[10] = "Null";
	char company[10] = "Null";
	OS phone_OS = OS::OS_0;
	Ram phone_Ram = Ram::R_0;
	Storage phone_Storage = Storage::S_0;
	Color phone_Color = Color::color_0;
	long long int price = 0;
	int stock = 0;
	int sold = 0;
};
void my_menu();
phone* add_phone(phone*, int&);
phone* add_phone(phone*, int, int);
phone* remove_phone(phone*, int&, int);
void sort_by_price(phone*, int);
int search(phone*, int, char[10], char[10]);
void change_mobile_info(phone*, int, char[10], char[10]);
void sell_a_phone(phone*, int, char[10], char[10]);
void print_phones(phone*, int);
void most_sold_item(phone*, int);
phone* load_from_a_file(phone*, int&);
void save_into_a_file(phone*, int);
int main()
{
	my_menu();
	system("pause");
	return 0;
}
void my_menu()
{
	int mysize = 1;
	phone* my_phone;
	my_phone = new phone[mysize];
	my_phone = load_from_a_file(my_phone, mysize);
	char switch_menu;
	bool keepgoing = true;
	while (keepgoing)
	{
		cout << "\n-------------------";
		cout << "\n\n1- Add a phone";
		cout << "\n2- Remove a phone";
		cout << "\n3- Sort phones by price";
		cout << "\n4- Search a phone";
		cout << "\n5- Change mobile info";
		cout << "\n6- Sell a phone";
		cout << "\n7- Print phones";
		cout << "\n8- Print phones sorted by the most sold to the least";
		cout << "\n9- Quit" << endl;
		cout << "Which ?? (1/2/3/4/5/6/7/8/9) ";
		cin >> switch_menu;
		if (switch_menu == '1')
		{
			my_phone = add_phone(my_phone, mysize);
		}
		else if (switch_menu == '2')
		{
			if (mysize > 2)
			{
				char t_name[10], t_company[10];
				bool check = true;
				cout << "\nEnter name of phone that you want to remove :";
				cin >> t_name;
				cout << "\nEnter company of phone that you want to remove :";
				cin >> t_company;
				for (int i = 0; i < mysize; i++)
				{
					if (!(strcmp(my_phone[i].name, t_name)) && !(strcmp(my_phone[i].company, t_company)))
					{
						check = false;
						my_phone = remove_phone(my_phone, mysize, i);
						break;
					}
				}
				if (check)
				{
					cout << "\nPhone not found";
				}
			}
			else
			{
				cout << "\nYou must at least have 2 phones in the stock to delete";
			}
		}
		else if (switch_menu == '3')
		{
			sort_by_price(my_phone, mysize);
		}
		else if (switch_menu == '4')
		{
			char t_name[10], t_company[10];
			cout << "\nEnter name of phone that you want to search :";
			cin >> t_name;
			cout << "\nEnter company of phone that you want to search :";
			cin >> t_company;
			if (search(my_phone, mysize, t_name, t_company) == 1)
			{
				cout << "\nPhone found\n";
			}
			else if (search(my_phone, mysize, t_name, t_company) == -1)
			{
				cout << "\nPhone not found\n";
			}
		}
		else if (switch_menu == '5')
		{
			char t_name[10], t_company[10];
			cout << "\nEnter name of phone that you want to change :";
			cin >> t_name;
			cout << "\nEnter company of phone that you want to change :";
			cin >> t_company;
			change_mobile_info(my_phone, mysize, t_name, t_company);
		}
		else if (switch_menu == '6')
		{
			char t_name[10], t_company[10];
			cout << "\nEnter name of phone that you want to sell :";
			cin >> t_name;
			cout << "\nEnter company of phone that you want to sell :";
			cin >> t_company;
			sell_a_phone(my_phone, mysize, t_name, t_company);
		}
		else if (switch_menu == '7')
		{
			print_phones(my_phone, mysize);
		}
		else if (switch_menu == '8')
		{
			most_sold_item(my_phone, mysize);
		}
		else if (switch_menu == '9')
		{
			save_into_a_file(my_phone, mysize);
			keepgoing = false;
		}
		else
		{
			cout << "\nInvalid input . Try Again";
		}
	}
	delete[] my_phone;
}
phone* add_phone(phone* my_phone, int& mysize)
{
	if (mysize == 1)
	{
		int temp;
		cout << "\nName : ";
		cin >> my_phone[mysize - 1].name;
		cout << "Company : ";
		cin >> my_phone[mysize - 1].company;
		cout << "OS (Enter 1 for iOS , 2 for Android , 3 for Windows phone) : ";
		cin >> temp;
		switch (temp)
		{
		case 1:
			my_phone[mysize - 1].phone_OS = iOS;
			break;
		case 2:
			my_phone[mysize - 1].phone_OS = Android;
			break;
		case 3:
			my_phone[mysize - 1].phone_OS = Windows_phone;
			break;
		default:
			cout << "\nInvalid Input" << endl;
		}
		cout << "RAM (GB) : ";
		cin >> temp;
		switch (temp)
		{
		case 2:
			my_phone[mysize - 1].phone_Ram = R_2GB;
			break;
		case 4:
			my_phone[mysize - 1].phone_Ram = R_4GB;
			break;
		case 6:
			my_phone[mysize - 1].phone_Ram = R_6GB;
			break;
		case 8:
			my_phone[mysize - 1].phone_Ram = R_8GB;
			break;
		case 12:
			my_phone[mysize - 1].phone_Ram = R_12GB;
			break;
		case 16:
			my_phone[mysize - 1].phone_Ram = R_16GB;
			break;
		case 32:
			my_phone[mysize - 1].phone_Ram = R_32GB;
			break;
		case 64:
			my_phone[mysize - 1].phone_Ram = R_64GB;
			break;
		default:
			cout << "\nInvalid Input" << endl;
		}
		cout << "Storage (GB) : ";
		cin >> temp;
		switch (temp)
		{
		case 16:
			my_phone[mysize - 1].phone_Storage = S_16GB;
			break;
		case 32:
			my_phone[mysize - 1].phone_Storage = S_32GB;
			break;
		case 64:
			my_phone[mysize - 1].phone_Storage = S_64GB;
			break;
		case 128:
			my_phone[mysize - 1].phone_Storage = S_128GB;
			break;
		case 256:
			my_phone[mysize - 1].phone_Storage = S_256GB;
			break;
		case 512:
			my_phone[mysize - 1].phone_Storage = S_512GB;
			break;
		case 1000:
			my_phone[mysize - 1].phone_Storage = S_1TB;
			break;
		case 2000:
			my_phone[mysize - 1].phone_Storage = S_2TB;
			break;
		default:
			cout << "\nInvalid Input" << endl;
		}
		cout << "Color (Enter 1 for white, 2 for blue, 3 for black, 4 for red, 5 for yellow, 6 for green, 7 for purple, 8 for others) : ";
		cin >> temp;
		switch (temp)
		{
		case 1:
			my_phone[mysize - 1].phone_Color = white;
			break;
		case 2:
			my_phone[mysize - 1].phone_Color = blue;
			break;
		case 3:
			my_phone[mysize - 1].phone_Color = black;
			break;
		case 4:
			my_phone[mysize - 1].phone_Color = red;
			break;
		case 5:
			my_phone[mysize - 1].phone_Color = yellow;
			break;
		case 6:
			my_phone[mysize - 1].phone_Color = green;
			break;
		case 7:
			my_phone[mysize - 1].phone_Color = purple;
			break;
		case 8:
			my_phone[mysize - 1].phone_Color = others;
			break;
		default:
			cout << "\nInvalid Input" << endl;
		}
		cout << "Price (Toman) : ";
		cin >> my_phone[mysize - 1].price;
		cout << "Stock : ";
		cin >> my_phone[mysize - 1].stock;
		//make a new array:
		phone* new_my_phone;
		new_my_phone = new phone[mysize + 1];
		for (int i = 0; i < mysize; i++)
		{
			new_my_phone[i] = my_phone[i];
		}
		mysize += 1;
		strcpy(new_my_phone[mysize - 1].name, "Null");
		strcpy(new_my_phone[mysize - 1].company, "Null");
		new_my_phone[mysize - 1].price = 0;
		new_my_phone[mysize - 1].stock = 0;
		new_my_phone[mysize - 1].sold = 0;
		return new_my_phone;
		delete[] new_my_phone;
	}
	else
	{
		char t_name[10], t_company[10];
		bool check = true;
		cout << "\nName : ";
		cin >> t_name;
		cout << "Company : ";
		cin >> t_company;
		for (int i = 0; i < mysize; i++)
		{
			if (!(strcmp(my_phone[i].name, t_name)))
			{
				check = false;
				int temp;
				cout << "\nThere is a phone with this name in the stock";
				cout << "\nEnter a number to add in stock: ";
				cin >> temp;
				my_phone = add_phone(my_phone, temp, i);
				return my_phone;
			}
		}
		if (check)
		{
			int temp;
			strcpy(my_phone[mysize - 1].name, t_name);
			strcpy(my_phone[mysize - 1].company, t_company);
			cout << "OS (Enter 1 for iOS , 2 for Android , 3 for Windows phone) : ";
			cin >> temp;
			switch (temp)
			{
			case 1:
				my_phone[mysize - 1].phone_OS = iOS;
				break;
			case 2:
				my_phone[mysize - 1].phone_OS = Android;
				break;
			case 3:
				my_phone[mysize - 1].phone_OS = Windows_phone;
				break;
			default:
				cout << "\nInvalid Input" << endl;
			}
			cout << "RAM (GB) : ";
			cin >> temp;
			switch (temp)
			{
			case 2:
				my_phone[mysize - 1].phone_Ram = R_2GB;
				break;
			case 4:
				my_phone[mysize - 1].phone_Ram = R_4GB;
				break;
			case 6:
				my_phone[mysize - 1].phone_Ram = R_6GB;
				break;
			case 8:
				my_phone[mysize - 1].phone_Ram = R_8GB;
				break;
			case 12:
				my_phone[mysize - 1].phone_Ram = R_12GB;
				break;
			case 16:
				my_phone[mysize - 1].phone_Ram = R_16GB;
				break;
			case 32:
				my_phone[mysize - 1].phone_Ram = R_32GB;
				break;
			case 64:
				my_phone[mysize - 1].phone_Ram = R_64GB;
				break;
			default:
				cout << "\nInvalid Input" << endl;
			}
			cout << "Storage (GB) : ";
			cin >> temp;
			switch (temp)
			{
			case 16:
				my_phone[mysize - 1].phone_Storage = S_16GB;
				break;
			case 32:
				my_phone[mysize - 1].phone_Storage = S_32GB;
				break;
			case 64:
				my_phone[mysize - 1].phone_Storage = S_64GB;
				break;
			case 128:
				my_phone[mysize - 1].phone_Storage = S_128GB;
				break;
			case 256:
				my_phone[mysize - 1].phone_Storage = S_256GB;
				break;
			case 512:
				my_phone[mysize - 1].phone_Storage = S_512GB;
				break;
			case 1000:
				my_phone[mysize - 1].phone_Storage = S_1TB;
				break;
			case 2000:
				my_phone[mysize - 1].phone_Storage = S_2TB;
				break;
			default:
				cout << "\nInvalid Input" << endl;
			}
			cout << "Color (Enter 1 for white, 2 for blue, 3 for black, 4 for red, 5 for yellow, 6 for green, 7 for purple, 8 for others) : ";
			cin >> temp;
			switch (temp)
			{
			case 1:
				my_phone[mysize - 1].phone_Color = white;
				break;
			case 2:
				my_phone[mysize - 1].phone_Color = blue;
				break;
			case 3:
				my_phone[mysize - 1].phone_Color = black;
				break;
			case 4:
				my_phone[mysize - 1].phone_Color = red;
				break;
			case 5:
				my_phone[mysize - 1].phone_Color = yellow;
				break;
			case 6:
				my_phone[mysize - 1].phone_Color = green;
				break;
			case 7:
				my_phone[mysize - 1].phone_Color = purple;
				break;
			case 8:
				my_phone[mysize - 1].phone_Color = others;
				break;
			default:
				cout << "\nInvalid Input" << endl;
			}
			cout << "Price (Toman) : ";
			cin >> my_phone[mysize - 1].price;
			cout << "Stock : ";
			cin >> my_phone[mysize - 1].stock;
			//make a new array:
			phone* new_my_phone;
			new_my_phone = new phone[mysize + 1];
			for (int i = 0; i < mysize; i++)
			{
				new_my_phone[i] = my_phone[i];
			}
			mysize += 1;
			strcpy(new_my_phone[mysize - 1].name, "Null");
			strcpy(new_my_phone[mysize - 1].company, "Null");
			new_my_phone[mysize - 1].price = 0;
			new_my_phone[mysize - 1].stock = 0;
			new_my_phone[mysize - 1].sold = 0;
			return new_my_phone;
			delete[] new_my_phone;
		}
	}
	return my_phone;
}
phone* add_phone(phone * my_phone, int add_stock, int i)
{
	my_phone[i].stock += add_stock;
	cout << "\nStock updated successfully";
	return my_phone;
}
phone* remove_phone(phone * my_phone, int& mysize, int i)
{
	//shift array:
	for (int j = i; j < mysize; j++)
	{
		strcpy(my_phone[j].name, my_phone[j + 1].name);
		strcpy(my_phone[j].company, my_phone[j + 1].company);
		my_phone[j].phone_OS = my_phone[j + 1].phone_OS;
		my_phone[j].phone_Ram = my_phone[j + 1].phone_Ram;
		my_phone[j].phone_Storage = my_phone[j + 1].phone_Storage;
		my_phone[j].phone_Color = my_phone[j + 1].phone_Color;
		my_phone[j].price = my_phone[j + 1].price;
		my_phone[j].stock = my_phone[j + 1].stock;
		my_phone[j].sold = my_phone[j + 1].sold;
	}
	//delete the last element after shift:
	strcpy(my_phone[mysize - 1].name, "Null");
	strcpy(my_phone[mysize - 1].company, "Null");
	my_phone[mysize - 1].phone_OS = OS_0;
	my_phone[mysize - 1].phone_Ram = R_0;
	my_phone[mysize - 1].phone_Storage = S_0;
	my_phone[mysize - 1].phone_Color = color_0;
	my_phone[mysize - 1].price = 0;
	my_phone[mysize - 1].stock = 0;
	my_phone[mysize - 1].sold = 0;
	//decrease size of array:
	mysize--;
	cout << "\nPhone deleted successfully";
	return my_phone;
}
void sort_by_price(phone * my_phone, int mysize)
{
	phone temp;
	for (int i = 0; i < mysize - 1; i++)
	{
		for (int j = 0; j < mysize - 1 - i; j++)
		{
			if (my_phone[j].price < my_phone[j + 1].price)
			{
				temp = my_phone[j + 1];
				my_phone[j + 1] = my_phone[j];
				my_phone[j] = temp;
			}
		}
	}
	cout << "\nList sorted successfully";
}
int search(phone * my_phone, int mysize, char t_name[10], char t_company[10])
{
	for (int i = 0; i < mysize; i++)
	{
		if (!(strcmp(my_phone[i].name, t_name)) && !(strcmp(my_phone[i].company, t_company)))
		{
			cout << endl << i + 1 << "th :" << endl;
			cout << " Name : " << my_phone[i].name << endl;
			cout << " Company : " << my_phone[i].company << endl;
			cout << " OS : ";
			switch (my_phone[i].phone_OS)
			{
			case 0:
				cout << my_phone[i].phone_OS << endl;
				break;
			case 1:
				cout << "iOS" << endl;
				break;
			case 2:
				cout << "Android" << endl;
				break;
			case 3:
				cout << "Windows Phone" << endl;
				break;
			default:
				cout << "Null" << endl;
			}
			cout << " RAM : " << my_phone[i].phone_Ram << " GB" << endl;
			cout << " Storage : " << my_phone[i].phone_Storage << " GB" << endl;
			cout << " Color : ";
			switch (my_phone[i].phone_Color)
			{
			case 0:
				cout << my_phone[i].phone_Color << endl;
				break;
			case 1:
				cout << "White" << endl;
				break;
			case 2:
				cout << "Blue" << endl;
				break;
			case 3:
				cout << "Black" << endl;
				break;
			case 4:
				cout << "Red" << endl;
				break;
			case 5:
				cout << "Yellow" << endl;
				break;
			case 6:
				cout << "Green" << endl;
				break;
			case 7:
				cout << "Purple" << endl;
				break;
			case 8:
				cout << "Others" << endl;
			default:
				cout << "Null" << endl;
			}
			cout << " Price : " << my_phone[i].price << endl;
			cout << " Stock : " << my_phone[i].stock << endl;
			cout << " Sold : " << my_phone[i].sold << endl;
			return 1;
		}
	}
	return -1;
}
void change_mobile_info(phone * my_phone, int mysize, char t_name[10], char t_company[10])
{
	bool check = true;
	for (int i = 0; i < mysize; i++)
	{
		if (!(strcmp(my_phone[i].name, t_name)) && !(strcmp(my_phone[i].company, t_company)))
		{
			check = false;
			//print mobile info:
			cout << endl << i + 1 << "th :" << endl;
			cout << " Name : " << my_phone[i].name << endl;
			cout << " Company : " << my_phone[i].company << endl;
			cout << " OS : ";
			switch (my_phone[i].phone_OS)
			{
			case 0:
				cout << my_phone[i].phone_OS << endl;
				break;
			case 1:
				cout << "iOS" << endl;
				break;
			case 2:
				cout << "Android" << endl;
				break;
			case 3:
				cout << "Windows Phone" << endl;
				break;
			default:
				cout << "Null" << endl;
			}
			cout << " RAM : " << my_phone[i].phone_Ram << " GB" << endl;
			cout << " Storage : " << my_phone[i].phone_Storage << " GB" << endl;
			cout << " Color : ";
			switch (my_phone[i].phone_Color)
			{
			case 0:
				cout << my_phone[i].phone_Color << endl;
				break;
			case 1:
				cout << "White" << endl;
				break;
			case 2:
				cout << "Blue" << endl;
				break;
			case 3:
				cout << "Black" << endl;
				break;
			case 4:
				cout << "Red" << endl;
				break;
			case 5:
				cout << "Yellow" << endl;
				break;
			case 6:
				cout << "Green" << endl;
				break;
			case 7:
				cout << "Purple" << endl;
				break;
			case 8:
				cout << "Others" << endl;
			default:
				cout << "Null" << endl;
			}
			cout << " Price : " << my_phone[i].price << endl;
			cout << " Stock : " << my_phone[i].stock << endl;
			cout << " Sold : " << my_phone[i].sold << endl;
			//change mobile info:
			while (1)
			{
				int switch_menu;
				cout << "\n\n---------------";
				cout << "\n\n1- change OS";
				cout << "\n2- change RAM";
				cout << "\n3- change storage";
				cout << "\n4- change color";
				cout << "\n5- change stock";
				cout << "\n6- change price";
				cout << "\n7- return to main menu";
				cout << "\n\nWhich ?? (1/2/3/4/5/6/7) ";
				cin >> switch_menu;
				if (switch_menu == 1)
				{
					int temp;
					cout << "OS (Enter 1 for iOS , 2 for Android , 3 for Windows phone) : ";
					cin >> temp;
					switch (temp)
					{
					case 1:
						my_phone[i].phone_OS = iOS;
						cout << "\nOS Updated";
						break;
					case 2:
						my_phone[i].phone_OS = Android;
						cout << "\nOS Updated";
						break;
					case 3:
						my_phone[i].phone_OS = Windows_phone;
						cout << "\nOS Updated";
						break;
					default:
						cout << "\nInvalid Input" << endl;
					}
				}
				else if (switch_menu == 2)
				{
					int temp;
					cout << "RAM (GB) : ";
					cin >> temp;
					switch (temp)
					{
					case 2:
						my_phone[i].phone_Ram = R_2GB;
						cout << "\nRAM Updated";
						break;
					case 4:
						my_phone[i].phone_Ram = R_4GB;
						cout << "\nRAM Updated";
						break;
					case 6:
						my_phone[i].phone_Ram = R_6GB;
						cout << "\nRAM Updated";
						break;
					case 8:
						my_phone[i].phone_Ram = R_8GB;
						cout << "\nRAM Updated";
						break;
					case 12:
						my_phone[i].phone_Ram = R_12GB;
						cout << "\nRAM Updated";
						break;
					case 16:
						my_phone[i].phone_Ram = R_16GB;
						cout << "\nRAM Updated";
						break;
					case 32:
						my_phone[i].phone_Ram = R_32GB;
						cout << "\nRAM Updated";
						break;
					case 64:
						my_phone[i].phone_Ram = R_64GB;
						cout << "\nRAM Updated";
						break;
					default:
						cout << "\nInvalid Input" << endl;
					}
				}
				else if (switch_menu == 3)
				{
					int temp;
					cout << "Storage (GB) : ";
					cin >> temp;
					switch (temp)
					{
					case 16:
						my_phone[i].phone_Storage = S_16GB;
						cout << "\nStorage Updated";
						break;
					case 32:
						my_phone[i].phone_Storage = S_32GB;
						cout << "\nStorage Updated";
						break;
					case 64:
						my_phone[i].phone_Storage = S_64GB;
						cout << "\nStorage Updated";
						break;
					case 128:
						my_phone[i].phone_Storage = S_128GB;
						cout << "\nStorage Updated";
						break;
					case 256:
						my_phone[i].phone_Storage = S_256GB;
						cout << "\nStorage Updated";
						break;
					case 512:
						my_phone[i].phone_Storage = S_512GB;
						cout << "\nStorage Updated";
						break;
					case 1000:
						my_phone[i].phone_Storage = S_1TB;
						cout << "\nStorage Updated";
						break;
					case 2000:
						my_phone[i].phone_Storage = S_2TB;
						cout << "\nStorage Updated";
						break;
					default:
						cout << "\nInvalid Input" << endl;
					}
				}
				else if (switch_menu == 4)
				{
					int temp;
					cout << "Color (Enter 1 for white, 2 for blue, 3 for black, 4 for red, 5 for yellow, 6 for green, 7 for purple, 8 for others) : ";
					cin >> temp;
					switch (temp)
					{
					case 1:
						my_phone[i].phone_Color = white;
						cout << "\nColor Updated";
						break;
					case 2:
						my_phone[i].phone_Color = blue;
						cout << "\nColor Updated";
						break;
					case 3:
						my_phone[i].phone_Color = black;
						cout << "\nColor Updated";
						break;
					case 4:
						my_phone[i].phone_Color = red;
						cout << "\nColor Updated";
						break;
					case 5:
						my_phone[i].phone_Color = yellow;
						cout << "\nColor Updated";
						break;
					case 6:
						my_phone[i].phone_Color = green;
						cout << "\nColor Updated";
						break;
					case 7:
						my_phone[i].phone_Color = purple;
						cout << "\nColor Updated";
						break;
					case 8:
						my_phone[i].phone_Color = others;
						cout << "\nColor Updated";
						break;
					default:
						cout << "\nInvalid Input" << endl;
					}
				}
				else if (switch_menu == 5)
				{
					cout << "Stock : ";
					cin >> my_phone[i].stock;
					cout << "\nStock Updated";
				}
				else if (switch_menu == 6)
				{
					cout << "Price : ";
					cin >> my_phone[i].price;
					cout << "\nPrice Updated";
				}
				else if (switch_menu == 7)
				{
					break;
				}
				else
				{
					cout << "\n\nInvalid input, try again";
				}
			}
			break;
		}
	}
	if (check)
	{
		cout << "\nPhone not found";
	}
}
void sell_a_phone(phone * my_phone, int mysize, char t_name[10], char t_company[10])
{
	bool check = true;
	for (int i = 0; i < mysize; i++)
	{
		if (!(strcmp(my_phone[i].name, t_name)) && !(strcmp(my_phone[i].company, t_company)))
		{
			check = false;
			if (my_phone[i].stock > 0)
			{
				my_phone[i].stock--;
				my_phone[i].sold++;
				cout << "\nIndex updated successfully";
				break;
			}
			else
			{
				cout << "\nStock of phone is empty";
			}
		}
	}
	if (check)
	{
		cout << "\nPhone not found";
	}
}
void print_phones(phone * my_phone, int mysize)
{
	for (int i = 0; i < mysize; i++)
	{
		cout << endl << i + 1 << "th :" << endl;
		cout << " Name : " << my_phone[i].name << endl;
		cout << " Company : " << my_phone[i].company << endl;
		cout << " OS : ";
		switch (my_phone[i].phone_OS)
		{
		case 0:
			cout << my_phone[i].phone_OS << endl;
			break;
		case 1:
			cout << "iOS" << endl;
			break;
		case 2:
			cout << "Android" << endl;
			break;
		case 3:
			cout << "Windows Phone" << endl;
			break;
		default:
			cout << "Null" << endl;
		}
		cout << " RAM : " << my_phone[i].phone_Ram << " GB" << endl;
		cout << " Storage : " << my_phone[i].phone_Storage << " GB" << endl;
		cout << " Color : ";
		switch (my_phone[i].phone_Color)
		{
		case 0:
			cout << my_phone[i].phone_Color << endl;
			break;
		case 1:
			cout << "White" << endl;
			break;
		case 2:
			cout << "Blue" << endl;
			break;
		case 3:
			cout << "Black" << endl;
			break;
		case 4:
			cout << "Red" << endl;
			break;
		case 5:
			cout << "Yellow" << endl;
			break;
		case 6:
			cout << "Green" << endl;
			break;
		case 7:
			cout << "Purple" << endl;
			break;
		case 8:
			cout << "Others" << endl;
			break;
		default:
			cout << "Null" << endl;
		}
		cout << " Price : " << my_phone[i].price << endl;
		cout << " Stock : " << my_phone[i].stock << endl;
		cout << " Sold : " << my_phone[i].sold << endl;
	}
}
void most_sold_item(phone * my_phone, int mysize)
{
	phone temp;
	phone* new_my_phone;
	new_my_phone = new phone[mysize];
	for (int i = 0; i < mysize; i++)
	{
		new_my_phone[i] = my_phone[i];
	}
	for (int i = 0; i < mysize - 1; i++)
	{
		for (int j = 0; j < mysize - 1 - i; j++)
		{
			if (new_my_phone[j].sold < new_my_phone[j + 1].sold)
			{
				temp = new_my_phone[j + 1];
				new_my_phone[j + 1] = new_my_phone[j];
				new_my_phone[j] = temp;
			}
		}
	}
	print_phones(new_my_phone, mysize);
	delete[] new_my_phone;
}
phone* load_from_a_file(phone * my_phone, int& mysize)
{
	ifstream fin("phone.txt", ios::in);
	phone* new_my_phone;
	int temp;
	if (fin)
	{
		fin >> mysize;
		new_my_phone = new phone[mysize];
		for (int i = 0; i < mysize; i++)
		{
			fin >> new_my_phone[i].name;
			fin >> new_my_phone[i].company;
			fin >> temp;
			switch (temp)
			{
			case 1:
				new_my_phone[i].phone_OS = iOS;
				break;
			case 2:
				new_my_phone[i].phone_OS = Android;
				break;
			case 3:
				new_my_phone[i].phone_OS = Windows_phone;
				break;
			}
			fin >> temp;
			switch (temp)
			{
			case 2:
				new_my_phone[i].phone_Ram = R_2GB;
				break;
			case 4:
				new_my_phone[i].phone_Ram = R_4GB;
				break;
			case 6:
				new_my_phone[i].phone_Ram = R_6GB;
				break;
			case 8:
				new_my_phone[i].phone_Ram = R_8GB;
				break;
			case 12:
				new_my_phone[i].phone_Ram = R_12GB;
				break;
			case 16:
				new_my_phone[i].phone_Ram = R_16GB;
				break;
			case 32:
				new_my_phone[i].phone_Ram = R_32GB;
				break;
			case 64:
				new_my_phone[i].phone_Ram = R_64GB;
				break;
			}
			fin >> temp;
			switch (temp)
			{
			case 16:
				new_my_phone[i].phone_Storage = S_16GB;
				break;
			case 32:
				new_my_phone[i].phone_Storage = S_32GB;
				break;
			case 64:
				new_my_phone[i].phone_Storage = S_64GB;
				break;
			case 128:
				new_my_phone[i].phone_Storage = S_128GB;
				break;
			case 256:
				new_my_phone[i].phone_Storage = S_256GB;
				break;
			case 512:
				new_my_phone[i].phone_Storage = S_512GB;
				break;
			case 1000:
				new_my_phone[i].phone_Storage = S_1TB;
				break;
			case 2000:
				new_my_phone[i].phone_Storage = S_2TB;
				break;
			}
			fin >> temp;
			switch (temp)
			{
			case 1:
				new_my_phone[i].phone_Color = white;
				break;
			case 2:
				new_my_phone[i].phone_Color = blue;
				break;
			case 3:
				new_my_phone[i].phone_Color = black;
				break;
			case 4:
				new_my_phone[i].phone_Color = red;
				break;
			case 5:
				new_my_phone[i].phone_Color = yellow;
				break;
			case 6:
				new_my_phone[i].phone_Color = green;
				break;
			case 7:
				new_my_phone[i].phone_Color = purple;
				break;
			case 8:
				new_my_phone[i].phone_Color = others;
				break;
			}
			fin >> new_my_phone[i].price;
			fin >> new_my_phone[i].stock;
			fin >> new_my_phone[i].sold;
		}
		strcpy(new_my_phone[mysize - 1].name, "Null");
		strcpy(new_my_phone[mysize - 1].company, "Null");
		new_my_phone[mysize - 1].price = 0;
		new_my_phone[mysize - 1].stock = 0;
		new_my_phone[mysize - 1].sold = 0;
		fin.close();
		return new_my_phone;
		delete[] new_my_phone;
	}
	else
	{
		cout << "\nThere is an error in the file\n";
	}
	return my_phone;
}
void save_into_a_file(phone * my_phone, int mysize)
{
	ofstream fout("phone.txt", ios::trunc);
	if (fout)
	{
		fout << mysize << endl;
		for (int i = 0; i < mysize; i++)
		{
			fout << my_phone[i].name;
			fout << '\t';
			fout << my_phone[i].company << '\t';
			fout << my_phone[i].phone_OS << '\t';
			fout << my_phone[i].phone_Ram << '\t';
			fout << my_phone[i].phone_Storage << '\t';
			fout << my_phone[i].phone_Color << '\t';
			fout << my_phone[i].price << '\t';
			fout << my_phone[i].stock << '\t';
			fout << my_phone[i].sold << '\t';
			fout << '\n';
		}
		fout.close();
	}
	else
	{
		cout << "\nThere is an error in the file\n";
	}
}
