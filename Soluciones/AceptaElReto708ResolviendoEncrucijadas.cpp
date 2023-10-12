#include <iostream>
#include <vector>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
    // Convert the input numbers from strings to vectors of integers
    vector<int> vec1(num1.size());
    for (int i = 0; i < num1.size(); i++) {
        vec1[i] = num1[num1.size() - i - 1] - '0';
    }
    vector<int> vec2(num2.size());
    for (int i = 0; i < num2.size(); i++) {
        vec2[i] = num2[num2.size() - i - 1] - '0';
    }

    // Initialize the result vector with zeros
    vector<int> result(vec1.size() + vec2.size());

    // Multiply each digit in vec2 with vec1 and add the result to the appropriate position in the result vector
    for (int i = 0; i < vec2.size(); i++) {
        int carry = 0;
        for (int j = 0; j < vec1.size(); j++) {
            int product = vec1[j] * vec2[i] + carry + result[i + j];
            carry = product / 10;
            result[i + j] = product % 10;
        }
        result[i + vec1.size()] = carry;
    }

    // Remove leading zeros from the result vector and convert it back to a string
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    string str(result.size(), '0');
    for (int i = 0; i < result.size(); i++) {
        str[result.size() - i - 1] = result[i] + '0';
    }
    return str;
}


std::string divideByTwo(const std::string& numStr) {
    std::string result;
    int carry = 0;

    for (char digit : numStr) {
        int currentDigit = digit - '0'; // Convertir el carácter a número
        int newValue = carry * 10 + currentDigit;

        result.push_back((newValue / 2) + '0'); // Convertir el número a carácter y añadirlo al resultado
        carry = newValue % 2;
    }

    // Eliminar ceros no significativos al principio
    size_t pos = result.find_first_not_of('0');
    if (pos != std::string::npos) {
        result.erase(0, pos);
    }

    return result;
}

int main() {
	long long int a, b;
	cin >> a >> b;
	while (a != 0 || b != 0) {
		long long int n = b / 3 - (a-1) / 3;
		long long int a_n = (b / 3) * 3;
		long long int a_1 = (a / 3) * 3;
		if (a % 3 != 0) {
			a_1 += 3;
		}
		cout << divideByTwo(multiply(to_string(n), to_string(a_n + a_1))) << '\n';


		cin >> a >> b;
	}





	return 0;
}