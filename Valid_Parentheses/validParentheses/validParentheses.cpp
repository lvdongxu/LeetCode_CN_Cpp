#include <iostream>
#include <string>

using namespace std;

int converter(char s) {
	int s_value = 0;
	switch (s)
	{
		case '{': { 
			s_value = 1; 
			break; 
		}
		case '(': { 
			s_value = 2; 
			break; 
		}
		case '[': { 
			s_value = 3; 
			break; 
		}
		case '}': { 
			s_value = 4; 
			break; 
		}
		case ')': { 
			s_value = 5; 
			break; 
		}
		case ']': { 
			s_value = 6; 
			break; 
		}
		default:
			break;
	}
	return s_value;
}

bool isValid(string s) {
	int str_len = s.length();
	//char str_stack[str_len];
	int* str_stack = new int[str_len];
	int stack_hat = 0, converted_int = 0;
	// str_stack[0] = s[0];
	// int left_right_pre, left_right_cur; // 0: "{","(""["; 1: "}",")","]".
	bool return_value=true;

	if (str_len == 0) {
		return true;
	}
	else if (str_len == 1) {
		return false;
	}
	else {
		for (int i = 0; i < str_len; i++) {
			converted_int = converter(s[i]);
			if (stack_hat == 0) {
				if (converted_int > 3) {
					return_value = false;
					break;
				}
				else {
					str_stack[stack_hat] = converted_int;
					stack_hat++;
				}
			}
			else {
				if (converted_int > 3) {
					if (converted_int - str_stack[stack_hat-1] != 3) {
						return_value = false;
						break;
					}
					else {
						stack_hat --;
					}
				}
				else {
					str_stack[stack_hat] = converted_int;
					stack_hat++;
				}
			}
		}
	}
	return (stack_hat == 0)&(return_value);

}

int main()
{
	string test_string;
	bool test_value;
	test_string = "()";

	test_value = isValid(test_string);

	cout << test_string[0] << endl;
	cout << test_string[1] << endl;
	cout << test_string.length() << endl;
	cout << "The string is " << test_value << endl;
	
	cout << "Hello World!\n";
	//string s;
	////bool test_value;
	//s = "[]";

	//int str_len = s.length();
	////char str_stack[str_len];
	//int* str_stack = new int[str_len];
	//int stack_hat = 0, converted_int = 0;
	//// str_stack[0] = s[0];
	//// int left_right_pre, left_right_cur; // 0: "{","(""["; 1: "}",")","]".
	//bool return_value = false;


	//if ((str_len == 0) || (str_len == 1)) {
	//	// return false;
	//	return_value == false;
	//}
	//else {
	//	for (int i = 0; i < str_len; i++) {
	//		converted_int = converter(s[i]);
	//		if (stack_hat == 0) {
	//			if (converted_int > 3) {
	//				return_value = false;
	//				break;
	//			}
	//			else {
	//				str_stack[stack_hat] = converted_int;
	//				stack_hat++;
	//			}
	//		}
	//		else {
	//			if (converted_int > 3) {
	//				if (converted_int - str_stack[stack_hat-1] != 3) {
	//					return_value = false;
	//					break;
	//				}
	//				else {
	//					--stack_hat;
	//				}
	//			}
	//		}
	//	}
	//	if (stack_hat == 0) {
	//		return_value = true;
	//	}
	//	else
	//	{
	//		return_value = false;
	//	}
	//}

	//cout << stack_hat << endl;
	//cout << return_value << endl;
}


