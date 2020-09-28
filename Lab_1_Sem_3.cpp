#include "Header.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"



TEST_CASE("Test on integers")
{
	auto DLL = new Doubly_Linked_List <int>;

	DLL->addLast(15);
	DLL->addLast(6);
	DLL->addLast(5);
	DLL->addLast(12);
	DLL->addLast(21);

	SUBCASE("Test on correctness of adding")
	{
		std::stringstream ss;
		ss << *DLL;
		CHECK("[15 6 5 12 21]" == ss.str());
	}

	SUBCASE("Test on correctness of increasing Insert sort")
	{
		InsertSort(DLL, DLL->size(), false);

		std::stringstream ss;
		ss << *DLL;

		CHECK("[5 6 12 15 21]" == ss.str());
	}

	SUBCASE("Test on correctness of degressive Insert sort")
	{
		InsertSort(DLL, DLL->size(), true);

		std::stringstream ss;
		ss << *DLL;

		CHECK("[21 15 12 6 5]" == ss.str());
	}

	delete DLL;
}



TEST_CASE("Test on doubles")
{
	auto DLL = new Doubly_Linked_List <double>;

	DLL->addLast(15.6);
	DLL->addLast(6.2);
	DLL->addLast(5.78);
	DLL->addLast(12.5);
	DLL->addLast(21.8);
	DLL->addLast(14.3);

	SUBCASE("Test on correctness of adding")
	{
		std::stringstream ss;
		ss << *DLL;
		CHECK("[15.6 6.2 5.78 12.5 21.8 14.3]" == ss.str());
	}

	SUBCASE("Test on correctness of increasing Quick sort")
	{
		QuickSort(DLL, DLL->size(), 0, DLL->size() - 1, false);

		std::stringstream ss;
		ss << *DLL;

		CHECK("[5.78 6.2 12.5 14.3 15.6 21.8]" == ss.str());
	}

	SUBCASE("Test on correctness of degressive Merge sort")
	{
		MergeSort(0, DLL->size() - 1, DLL->size(), DLL, true);

		std::stringstream ss;
		ss << *DLL;

		CHECK("[21.8 15.6 14.3 12.5 6.2 5.78]" == ss.str());
	}

	delete DLL;
}




TEST_CASE("Test on strings")
{
	auto DLL = new Doubly_Linked_List <std::string>;

	DLL->addLast("abc");
	DLL->addLast("abb");
	DLL->addLast("bca");
	DLL->addLast("aaa");
	DLL->addLast("bcaa");

	SUBCASE("Test on correctness of adding")
	{
		std::stringstream ss;
		ss << *DLL;
		CHECK("[abc abb bca aaa bcaa]" == ss.str());
	}

	SUBCASE("Test on correctness of degressive Bubble sort")
	{
		BubbleSort(DLL, DLL->size(), true);

		std::stringstream ss;
		ss << *DLL;

		CHECK("[bcaa bca abc abb aaa]" == ss.str());
	}

	SUBCASE("Test on correctness of increasing Shell sort")
	{
		ShellSort(DLL, DLL->size(), false);

		std::stringstream ss;
		ss << *DLL;

		CHECK("[aaa abb abc bca bcaa]" == ss.str());
	}
	
	delete DLL;
}




TEST_CASE("Test on classes")
{

}



/*int main()
{
	int ans = 0;

	while (ans != 4)
	{
		ans = menu();

		switch (ans)
		{
		case 0: 
			IntMain();

			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			std::cout << "CYA!" << std::endl;
			break;
		default:
			break;
		}
	}

	system("pause");

	return 0;
}*/
