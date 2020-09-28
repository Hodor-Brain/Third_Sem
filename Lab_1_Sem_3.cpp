#include "Header.h"
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_IMPLEMENT
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
	auto DLL = new Doubly_Linked_List <Dice>;

	std::vector <double> probs;

	probs.push_back(0.25);
	probs.push_back(0.25);
	probs.push_back(0.3);
	probs.push_back(0.2);

	Dice temp(4, probs);

	DLL->addLast(temp);



	probs.assign(0, 0);

	probs.push_back(0.4);
	probs.push_back(0.6);

	Dice temp1(2, probs);

	DLL->addLast(temp1);



	probs.assign(0, 0);

	probs.push_back(0.15);
	probs.push_back(0.3);
	probs.push_back(0.15);
	probs.push_back(0.1);
	probs.push_back(0.2);
	probs.push_back(0.1);

	Dice temp2(6, probs);

	DLL->addLast(temp2);



	//std::cout << *DLL << std::endl;
	
	SUBCASE("Test on correctness of adding")
	{
		std::stringstream ss;
		ss << *DLL;
		CHECK("[(1 = 0.25, 2 = 0.25, 3 = 0.3, 4 = 0.2) (1 = 0.4, 2 = 0.6) (1 = 0.15, 2 = 0.3, 3 = 0.15, 4 = 0.1, 5 = 0.2, 6 = 0.1)]" == ss.str());
	}

	SUBCASE("Test on correctness of degressive Shell sort")
	{
		ShellSort(DLL, DLL->size(), true);

		std::stringstream ss;
		ss << *DLL;

		CHECK("[(1 = 0.15, 2 = 0.3, 3 = 0.15, 4 = 0.1, 5 = 0.2, 6 = 0.1) (1 = 0.25, 2 = 0.25, 3 = 0.3, 4 = 0.2) (1 = 0.4, 2 = 0.6)]" == ss.str());
	}

	SUBCASE("Test on correctness of increasing Merge sort")
	{
		MergeSort(0, DLL->size() - 1, DLL->size(), DLL, false);

		std::stringstream ss;
		ss << *DLL;

		CHECK("[(1 = 0.4, 2 = 0.6) (1 = 0.25, 2 = 0.25, 3 = 0.3, 4 = 0.2) (1 = 0.15, 2 = 0.3, 3 = 0.15, 4 = 0.1, 5 = 0.2, 6 = 0.1)]" == ss.str());
	}
}



/*int main()
{
	std::vector <float> b;

	b.push_back(0.25);
	b.push_back(0.25);
	b.push_back(0.3);
	b.push_back(0.2);

	Dice a(4, b);

	std::cout << a;

	return 0;
}*/

int main(int argc, char** argv) 
{
	//doctest stuff
	doctest::Context context;
	context.applyCommandLine(argc, argv);
	int res = context.run();
	if (context.shouldExit())
		return res;







	//my return code
	int client_stuff_return_code = 0;

	return res + client_stuff_return_code;
}
