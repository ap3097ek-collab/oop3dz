//Создайте класс PasswordGenerator, который генерирует случайные пароли с настраиваемыми параметрами :
//-Длина пароля
//- Включение цифр 
//- Включение специальных символов 
//- Статический счетчик сгенерированных паролей


#include <iostream>
#include <string>
#include <random>

class PasswordGenerator {
private:
	int len;
	int useD;
	int useS;

	static int coun;

public:
	PasswordGenerator(int len, bool dig, bool spec) : len(len), useD(dig), useS(spec) {}


	std:: string generate() {
		std::string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		std::string digits = "0123456789";
		std::string special = "!@#$%^&*()-_=+[]{}|;:',.<>?/`~";

		std::string poll = letters;

		if (useD) poll += digits;
		if (useS) poll += special;

		if (poll.empty()) {
			return " errrrrrororororo"; 
		};
		
		std::string pass = "";

		for(int i =1; i <= len; i++) {
			int index = rand() % poll.size();
			pass += poll[index];
		}
	
		coun++;
		return pass;
		
	}
	


	static int getC() {
		return coun;
	}

};



int PasswordGenerator::coun = 0;

int main() {
	srand(time(0));

	PasswordGenerator g1(12, true, true);
	std::cout << "parol 1: " << g1.generate() << std::endl;


	PasswordGenerator g2(8, false, true);
	std::cout << "parol 2: " << g2.generate() << std::endl;


	std::cout << "Vsego: " << PasswordGenerator::getC() << std::endl;

	return 0;
}
