////////////////////////////////////////////////////////////////////
//                          _ooOoo_                               //
//                         o8888888o                              //
//                         88" . "88                              //
//                         (| ^_^ |)                              //
//                         O\  =  /O                              //
//                      ____/`---'\____                           //
//                    .'  \\|     |//  `.                         //
//                   /  \\|||  :  |||//  \                        //
//                  /  _||||| -:- |||||-  \                       //
//                  |   | \\\  -  /// |   |                       //
//                  | \_|  ''\---/''  |   |                       //
//                  \  .-\__  `-`  ___/-. /                       //
//                ___`. .'  /--.--\  `. . ___                     //
//              ."" '<  `.___\_<|>_/___.'  >'"".                  //
//            | | :  `- \`.;`\ _ /`;.`/ - ` : | |                 //
//            \  \ `-.   \_ __\ /__ _/   .-` /  /                 //
//      ========`-.____`-.___\_____/___.-`____.-'========         //
//                           `=---='                              //
//      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        //
//            ���汣��       ����BUG     �����޸�                 //
////////////////////////////////////////////////////////////////////

//Ŀǰ��û��sin,cos,tan

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//const char legal_opt[] = { '+', '-', '*', '/', '(', ')', '^', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //����������Ķ��ǷǷ��� 
//const int len = sizeof(legal_opt) / sizeof(legal_opt[0]); //�ַ�������
//����2�б�������

//bool is_legal(const string* user_input, int* len_input); //����ַ�Խ�Լ�ڴ棬constΪ��ֹ�ּ��޸�����  ////�ú����ѱ�����
//bool is_in_list(const char * user_input);    //�ú����ѱ�����
bool is_number(const char* user_input);
bool is_alpha(const char* user_input);
bool is_opt(const char* user_input);
bool is_same_opt(const char* user_input_1, const char* user_input_2);
int my_length(string common[], int common_long);
void trim(string& s);
string format_string(string* user_input, int* len_input);
string calculate(string expression);

int main() {

	string user_input;

restart:
	printf("��������ѧ���ʽ��");

	//cin >> user_input;
	//cin ���ܶ��ո�

	getline(cin, user_input);

	int user_input_length = size(user_input);

	//if (!is_legal(&user_input,&user_input_length)){
	//	printf("�﷨����\n");
	//	goto restart;
	//}
	//else {
	//�ⲿ�ֱ� ������
	//printf("�﷨��ȷ\n");

	string new_string = format_string(&user_input, &user_input_length);
	string answer = calculate(new_string);
	int answer_length = size(answer);
	string formate_answer = format_string(&calculate(new_string), &answer_length);
	cout << formate_answer << endl;

	//}

	goto restart;

	return 0;
}

//bool is_legal(const string * user_input,int * len_input) {
//	
//
//	for (int i = 0; i < *len_input; i++) {
//		
//		if (!is_in_list(&((*user_input)[i]))) { return true; } //�Ȳ��������һ��Ļ�false  /*false���﷨������*/ 
//	}
//	return true;
//}
////�ú����ѱ�����

//bool is_in_list(const char* user_input) {
//	
//	for (int i = 0; i < len; i++) {
//		if (*user_input == legal_opt[i])
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//�ú����ѱ�����

bool is_number(const char* user_input) {
	if ((*user_input >= '0') && (*user_input <= '9')) { return true; }
	return false;
}

bool is_alpha(const char* user_input) {
	if ((*user_input >= 'a') && (*user_input <= 'z') || (*user_input >= 'A') && (*user_input <= 'Z')) { return true; }
	return false;
}

bool is_opt(const char* user_input) {
	if (*user_input == '+' || *user_input == '-' || *user_input == '*' || *user_input == '/' || *user_input == '^') { return true; }
	return false;
}

bool is_same_opt(const char* user_input_1, const char* user_input_2) {
	if (is_number(user_input_1) && is_number(user_input_2)) { return true; }
	if (is_alpha(user_input_1) && is_alpha(user_input_2)) { return true; }
	if (is_opt(user_input_1) && is_opt(user_input_2)) { return true; }

	//С���������չ�
	if (*user_input_1 == '.' || *user_input_2 == '.') { return true; }

	return false;
}

int my_length(string common[], int common_long) {
	for (int length = 0; length < common_long; length++) {
		if (common[length] == "") {
			return length;
		}
	}
	return 0;
}

void trim(string& s)
{
	if (s.empty())
	{
		return;
	}
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
}


string format_string(string* user_input, int* len_input) {
	string format_user_input_1 = "";
	string format_user_input_2 = "";
	for (int i = 0; i < *len_input; i++) {
		//ȥ�ո�
		if ((*user_input)[i] != ' ') { format_user_input_1 += (*user_input)[i]; }
	}

	format_user_input_2 += format_user_input_1[0];

	int len_format_user_input_1 = size(format_user_input_1);
	for (int i = 0; i < len_format_user_input_1 - 1; i++) {
		//�ӿո�
		if (is_same_opt(&format_user_input_1[i], &format_user_input_1[i + 1]))
		{
			format_user_input_2 += format_user_input_1[i + 1];
		}
		else
		{
			format_user_input_2 = format_user_input_2 + ' ' + format_user_input_1[i + 1];
		}
	}
	//here have bug



	return format_user_input_2;
}

string calculate(string expression) {
	//�ݹ�

	/*
	��������ȼ�
	0.sin() cos() tan() ln() log() .... //log()����2Ϊ�׵�
	1.Բ ()
	2.�� ** ^
	3.�˳� * /
	4.�Ӽ� + -
	*/

	int len_expression = size(expression);

	//�ȼ�����������
	for (int i = 0; i < len_expression; i++) {
		if (expression[i] == '(') {
			int u = i;
			for (; i < len_expression; i++) {
				if (expression[i] == '(') {
					u = i;
					continue;
				}
				if (expression[i] == ')') {
					string slice_expression = expression.substr(u + 1, i - u - 1);
					string new_expression = calculate(slice_expression);
					string temp = expression.substr(0, u) + new_expression + expression.substr(i + 1, len_expression - i);
					int len_temp = temp.size();
					string temp_2 = format_string(&temp, &len_temp);
					return calculate(temp_2);
				}
			}
		}
	}

	string command[100]; //�ڴ治����̫�࣬��Ȼ��ջ�Ų���

	int o = 0;
	int u = 0;
	//��ָ��ո�Ϊ�ָ���
	for (int i = 0; i < len_expression; i++) {

		if (expression[i] == ' ' || i == len_expression - 1) {
			if (u < i) {
				string slice_expression = expression.substr(u, (i == len_expression - 1) ? (i - u + 1) : (i - u));
				trim(slice_expression);
				if (slice_expression != "") {
					if (slice_expression == "pi") {
						command[o++] = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
					}
					else if (slice_expression == "e") {
						command[o++] = "2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274";
					}
					else {
						command[o++] = slice_expression;
					}
				}
				u = i;
			}
			continue;
		}
	}

	int len_command = my_length(command, sizeof(command) / sizeof(command[0]));

	if (len_command == 1) {
		string new_new_command = command[0];
		return new_new_command;
	}

	string new_command[100];

	o = 0;

	bool S_1 = (expression.find('^') < len_expression) ? true : false;
	bool S_2 = (expression.find("**") < len_expression) ? true : false;
	bool S_3 = (expression.find('*') < len_expression) ? true : false;
	bool S_4 = (expression.find('/') < len_expression) ? true : false;
	bool S_5 = (expression.find('+') < len_expression) ? true : false;
	//bool S_6 = (expression.find('-') < len_expression) ? true : false; //û��Ҫ��


	if (command[0] == "-" && len_command == 2) {
		return expression;
	}
	//�и���Ҫ�����ٶ�һ��
	for (int i = 0; i < len_command - 1; i++) {

		if (i == 0) {
			if (!(command[i] == "sin" ||
				command[i] == "cos" ||
				command[i] == "tan" ||
				command[i] == "arcsin" ||
				command[i] == "arccos" ||
				command[i] == "arctan" ||
				command[i] == "ln"))
			{
				continue;
			}
		}

		if (command[i] == "sin") {
			if (i > 0) {
				for (int u = 0; u < i; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			if (command[i + 1] == "-") {
				temp = to_string(sin(-stod(command[i + 2])));
				new_command[o++] = temp;
				i++;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;

			}
			else {
				temp = to_string(sin(stod(command[i + 1])));
				new_command[o++] = temp;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;
			}
		}

		if (command[i] == "cos") {
			if (i > 0) {
				for (int u = 0; u < i; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			if (command[i + 1] == "-") {
				temp = to_string(cos(-stod(command[i + 2])));
				new_command[o++] = temp;
				i++;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;

			}
			else {
				temp = to_string(cos(stod(command[i + 1])));
				new_command[o++] = temp;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;
			}
		}


		if (command[i] == "tan") {
			if (i > 0) {
				for (int u = 0; u < i; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			if (command[i + 1] == "-") {
				temp = to_string(tan(-stod(command[i + 2])));
				new_command[o++] = temp;
				i++;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;

			}
			else {
				temp = to_string(tan(stod(command[i + 1])));
				new_command[o++] = temp;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;
			}
		}

		if (command[i] == "arcsin") {
			if (i > 0) {
				for (int u = 0; u < i; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			if (command[i + 1] == "-") {
				if (stod(command[i + 2]) > 1) {
					printf("����arcsin��������������������\n");
					main();
				}
				temp = to_string(asin(-stod(command[i + 2])));
				new_command[o++] = temp;
				i++;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;

			}
			else {
				if (stod(command[i + 1]) > 1) {
					printf("����arcsin��������������������\n");
					main();
				}
				temp = to_string(asin(stod(command[i + 1])));
				new_command[o++] = temp;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;
			}
		}

		if (command[i] == "arccos") {
			if (i > 0) {
				for (int u = 0; u < i; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			if (command[i + 1] == "-") {
				if (stod(command[i + 2]) > 1) {
					printf("����arccos��������������������\n");
					main();
				}
				temp = to_string(acos(-stod(command[i + 2])));
				new_command[o++] = temp;
				i++;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;

			}
			else {
				if (stod(command[i + 1]) > 1) {
					printf("����arccos��������������������\n");
					main();
				}
				temp = to_string(acos(stod(command[i + 1])));
				new_command[o++] = temp;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;
			}
		}


		if (command[i] == "arctan") {
			if (i > 0) {
				for (int u = 0; u < i; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			if (command[i + 1] == "-") {
				temp = to_string(atan(-stod(command[i + 2])));
				new_command[o++] = temp;
				i++;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;

			}
			else {
				temp = to_string(atan(stod(command[i + 1])));
				new_command[o++] = temp;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;
			}
		}

		if (command[i] == "ln") {
			if (i > 0) {
				for (int u = 0; u < i; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			if (command[i + 1] == "-") {
				temp = to_string(log(-stod(command[i + 2])));
				new_command[o++] = temp;
				i++;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;

			}
			else {
				temp = to_string(log(stod(command[i + 1])));
				new_command[o++] = temp;
				i++;
				i++;
				for (; i < len_command; i++) { new_command[o++] = (command[i]); }
				break;
			}
		}



		if (command[i] == "^") {
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string(pow(stod(command[i - 1]), stod(command[i + 1])));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}

		if (command[i] == "^-") {
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string(1 / (pow(stod(command[i - 1]), stod(command[i + 1]))));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}


		if (S_1) { continue; };

		if (command[i] == "**") {
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string(pow(stod(command[i - 1]), stod(command[i + 1])));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}

		if (command[i] == "**-") {
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string(1 / (pow(stod(command[i - 1]), stod(command[i + 1]))));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}



		if (S_2) { continue; };

		if (command[i] == "*") {

			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}

			string temp;
			temp = to_string((stod(command[i - 1])) * (stod(command[i + 1])));
			new_command[o++] = temp;

			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}

		if (command[i] == "*-") {

			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}

			string temp;
			temp = to_string(-(stod(command[i - 1])) * (stod(command[i + 1])));
			new_command[o++] = temp;

			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}


		if (S_3) { continue; };

		if (command[i] == "/") {
			if (stod(command[i + 1]) == 0.0) {
				printf("error, ��ĸ����Ϊ0\n");
				main();
			}

			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;

			temp = to_string((stod(command[i - 1])) / (stod(command[i + 1])));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}

		if (command[i] == "/-") {
			if (stod(command[i + 1]) == 0.0) {
				printf("error, ��ĸ����Ϊ0\n");
				main();
			}
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string(-((stod(command[i - 1])) / (stod(command[i + 1]))));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}

		if (S_4) { continue; };

		if (command[i] == "+") {
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string((stod(command[i - 1])) + (stod(command[i + 1])));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}
		if (command[i] == "+-") {
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string((stod(command[i - 1])) - (stod(command[i + 1])));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;

		}

		if (S_5) { continue; };

		if (command[i] == "-") {
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string((stod(command[i - 1])) - (stod(command[i + 1])));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}

		if (command[i] == "--") {
			if (i - 1 > 0) {
				for (int u = 0; u < i - 1; u++) {
					new_command[o++] = (command[u]);
				}
			}
			string temp;
			temp = to_string((stod(command[i - 1])) + (stod(command[i + 1])));
			new_command[o++] = temp;
			i++;
			i++;
			for (; i < len_command; i++) { new_command[o++] = (command[i]); }
			break;
		}
	}



	string new_new_command;
	int len_new_command = my_length(new_command, sizeof(new_command) / sizeof(new_command[0]));
	for (int i = 0; i < len_new_command; i++) {
		new_new_command += new_command[i];
	}


	int len_new_new_command = size(new_new_command);
	//������������������
	for (int i = 0; i < len_new_new_command; i++) {
		if (is_opt(&new_new_command[i])) {
			if (i == 0 && new_new_command[i] == '-') {
				break;
			}
			string new_new_new_command = format_string(&new_new_command, &len_new_new_command);
			return calculate(new_new_new_command);
		}
	}


	return new_new_command;
}
