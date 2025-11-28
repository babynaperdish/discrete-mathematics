#include "mySet.h"

using namespace std;

mySet::mySet() {
	int n = 0;
	srand(time(NULL));
	cout << "Enter the digit capacity of the universe of multisets (not more then 11): ";
	while (true) {
		n = correctInput();
		if (n < 0) {
			std::cout << "Digit capasity can't be less than zero. Please try again: " << endl;
		}
		else if (n > 11) {
			std::cout << "Digit capasity can't be more than 30. Please try again: " << endl;
		}
		else if (n >= 0) {
			cout << "Multiplicity whas chosen: " << n << endl;
			clearBuffer();
			setsMultiplicity = pow(2, n);
			break;
		}
	}
	if (setsMultiplicity == 1) {
		setsMultiplicity = 0;
		cout << "\nUniversum is an empty set. \nA is an empty set. \nB is an empty set.";
		cout << "\n\t All sets operations.";
		cout << "\n1. Union is an empty set. \n";
		cout << "\n2. Intersection is an empty set. \n";
		cout << "\n3. a) Complement À is an empty set. \n";
		cout << "\n3. á) Complement Â is an empty set. \n";
		cout << "\n4. a) Difference À \\ B is an empty set. \n";
		cout << "\n4. á) Difference Â \\ A is an empty set. \n";
		cout << "\n5. Symmetric difference is an empty set. \n";
		cout << "\n6. à) Arithmetic difference A - B is an empty set. \n";
		cout << "\n6. á) Arithmetic difference B - A - is an empty set. \n";
		cout << "\n7. Arithmetic sum is an empty set. \n";
		cout << "\n8. à) Division A : B is an empty set. \n";
		cout << "\n8. á) Division B : A is an empty set. \n";
		cout << "\n9. Multiplication A * B is an empty set. \n";

		return;
	}
	grayUniversum = grayAlgoritm(n);
	for (int i = 0; i < 1 << n; i++)
	{
		universum.push_back(1 + rand() % 10);
		universumPower += universum[i];
	}
	std::cout << "Your universum: " << endl;
	setOut(universum);
	std::cout << "Universums power: " << universumPower << endl << endl;
	std::cout << "For random sets input enter \"1\", for manual - \"2\":" << endl;
	while (true) {
		int inputType = correctInput();
		if (inputType == 1) {
			std::cout << "You have chosen random input." << endl;
			std::cout << "Set A:" << endl;
			setRandomInput(firstSet, universum, firstSetPower);
			std::cout << "Set B:" << endl;
			setRandomInput(secondSet, universum, secondSetPower);
			break;
		}
		if (inputType == 2) {
			std::cout << "You have chosen manual input." << endl;
			std::cout << "Set A:" << endl;
			setManualInput(firstSet, firstSetPower);
			std::cout << "Set B:" << endl;
			setManualInput(secondSet, secondSetPower);
			break;
		}
		else {
			std::cout << "Wrong input, try again: " << endl;
			clearBuffer();
		}
	}

}

int mySet::correctInput() {
	int num;

	while (scanf("%d", &num) != 1)
	{ 
		std::cout << "Incorrect input. Try again: ";
		clearBuffer();
	}
	return num;
}

void mySet::clearBuffer()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void mySet::setOut(const vector<int>& set) {
	for (int i = 0; i < setsMultiplicity; i++) {
		std::cout << i << "(" << set[i] << "), ";
	}
	std::cout << endl;
}

vector<vector<int>> mySet::grayAlgoritm(int n) {
	int size = 1 << n;
	vector<vector<int>> grayCode(size, vector<int>(n, 0));

	grayCode[0][n - 1] = 0;
	grayCode[1][n - 1] = 1;
	int p = 2;
	for (int i = 2; i < n + 1; i++) {
		int t = p - 1;
		p *= 2;
		for (int k = p / 2; k < p; k++) {
			grayCode[k] = grayCode[t];
			grayCode[t][n - i] = 0;
			grayCode[k][n - i] = 1;
			t--;
		}
	}
	return grayCode;
}

void mySet::setRandomInput(vector<int>& set1, vector<int>& univ, int& power){
	
	for (int i = 0; i < setsMultiplicity; i++) {
		set1.push_back(rand() % universum[i]);
		power += set1[i];
	}
	setOut(set1);
}

void mySet::setManualInput(vector<int>& set1, int& power) {
	for (int i = 0; i < setsMultiplicity; i++) {
		std::cout << "Enter " << i + 1 << " element (not bigger than " << universum[i] << "): " << endl;
		int element;
		while (true) {
			element = correctInput();
			if (element < 0 || element > universum[i]) {
				std::cout << "Invalid value. Try again: " << endl;
			}
			else {
				break;
			}
		}
		set1.push_back(element);
		power += element;
	}
	cout << endl;
	setOut(set1);
}

void mySet::setsUnion(vector<int>& resultSet, const vector<int>& set1, const vector<int>& set2) {
	for (int i = 0; i < setsMultiplicity; i++) {
		resultSet.push_back(max(set1[i], set2[i]));
	}
}

void mySet::setsIntersection(vector<int>& resultSet, const vector<int>& set1, const vector<int>& set2) {
	for (int i = 0; i < setsMultiplicity; i++) {
		resultSet.push_back(min(set1[i], set2[i]));
	}
}

void mySet::setsComplement(vector<int>& res, const vector<int> set) {
	for (int i = 0; i < setsMultiplicity; i++) {
		res.push_back(universum[i] - set[i]);
	}
}

void mySet::setsSubtraction(vector<int>& res, const vector<int> set1, const vector<int> set2) {
	vector<int> compSet;
	setsComplement(compSet, set2);
	setsIntersection(res, set1, compSet);
}

void mySet::setsSymmetricSubtraction(vector<int>& res, const vector<int> set1, const vector<int> set2) {
	vector<int>unionS;
	vector<int>interS;
	setsUnion(unionS, firstSet, secondSet);
	setsIntersection(interS, firstSet, secondSet);
	setsSubtraction(res, unionS, interS);
}

void mySet::setsArithmeticSubtraction(vector<int>& res, const vector<int> set1, const vector<int> set2) {
	for (int i = 0; i < setsMultiplicity; i++) {
		int dif = set1[i] - set2[i];
		if (dif < 0) dif = 0;
		res.push_back(dif);
	}
}

void mySet::setsArithmeticSum(vector<int>& res, const vector<int> set1, const vector<int> set2) {
	for (int i = 0; i < setsMultiplicity; i++) {
		int sum = set1[i] + set2[i];
		if (sum >= universum[i]) sum = universum[i];
		res.push_back(sum);
	}
}

void mySet::setsArithmeticMultiplication(vector<int>& res, const vector<int> set1, const vector<int> set2) {
	for (int i = 0; i < setsMultiplicity; i++) {
		int sum = set1[i] * set2[i];
		if (sum > universum[i]) sum = universum[i];
		res.push_back(sum);
	}
}

void mySet::setsArithmeticDivision(vector<int>& res, const vector<int> set1, const vector<int> set2) {
	int div;
	for (int i = 0; i < setsMultiplicity; i++) {
		if (set2[i] == 0) { div = 0; }
		else { div = set1[i] / set2[i]; }
		res.push_back(div);
	}
}

void mySet::printOperations() {
	std::cout << "Print all sets operations" << endl;

	std::cout << "1) Union of sets:" << endl;
	vector<int> resUnion;
	setsUnion(resUnion, firstSet, secondSet);
	setOut(resUnion);

	std::cout << "2) Intersection of sets:" << endl;
	vector<int> resInter;
	setsIntersection(resInter, firstSet, secondSet);
	setOut(resInter);

	std::cout << "3a) A \\ B:" << endl;
	vector<int> ressub1;
	setsSubtraction(ressub1, firstSet, secondSet);
	setOut(ressub1);

	std::cout << "3b) B \\ A:" << endl;
	vector<int> ressub2;
	setsSubtraction(ressub2, secondSet, firstSet);
	setOut(ressub2);

	std::cout << "4) Symmetric subtraction of sets:" << endl;
	vector<int> ressymsub;
	setsSymmetricSubtraction(ressymsub, firstSet, secondSet);
	setOut(ressymsub);

	std::cout << "5a) Complement of A:" << endl;
	vector<int> rescomp1;
	setsComplement(rescomp1, firstSet);
	setOut(rescomp1);

	std::cout << "5b) Complement of B:" << endl;
	vector<int> rescomp2;
	setsComplement(rescomp2, secondSet);
	setOut(rescomp2);

	std::cout << "6) Arithmetic sum of sets:" << endl;
	vector<int> resarsum;
	setsArithmeticSum(resarsum, firstSet, secondSet);
	setOut(resarsum);

	std::cout << "7) Arithmetic subtraction of sets:" << endl;
	vector<int> resarsub;
	setsArithmeticSubtraction(resarsub, firstSet, secondSet);
	setOut(resarsub);

	std::cout << "8) Arithmetic multiplication of sets:" << endl;
	vector<int> resarmult;
	setsArithmeticMultiplication(resarmult, firstSet, secondSet);
	setOut(resarmult);

	std::cout << "9) Arithmetic division of sets:" << endl;
	vector<int> resardiv;
	setsArithmeticDivision(resardiv, firstSet, secondSet);
	setOut(resardiv);
}