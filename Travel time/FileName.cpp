#include <iostream>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int FirstHour, FirstMinutes, SecondHour, SecondMinutes, TravelHour, TravelMinutes;
	std::string first;
	std::string second;
	std::cout << "Введите время отправления поезда: " << "\n";
	std::cin >> first;
	std::cout << "Введите время прибытия поезда: " << "\n";
	std::cin >> second;

	if (first.length() != 5 || first[0] < '0' || first[0] > '9' || first[1] < '0' || first[1] > '9' || first[2] != ':' || first[3] < '0' || first[3] > '9' || first[4] < '0' || first[4] > '9') {
		std::cout << "Error\n";
		return 1;
	}
	if (second.length() != 5 || second[0] < '0' || second[0] > '9' || second[1] < '0' || second[1] > '9' || second[2] != ':' || second[3] < '0' || second[3] > '9' || second[4] < '0' || second[4] > '9') {
		std::cout << "Error\n";
		return 2;
	}
	FirstHour = 10 * (first[0] - '0') + (first[1] - '0');
	FirstMinutes = 10 * (first[3] - '0') + (first[4] - '0');
	SecondHour = 10 * (second[0] - '0') + (second[1] - '0');
	SecondMinutes = 10 * (second[3] - '0') + (second[4] - '0');
	if (FirstHour > 24 || SecondHour > 24 || FirstMinutes > 60 || SecondMinutes > 60) {
		std::cout << "Error\n";
		return 3;
	}

	if (FirstHour > SecondHour) {
		TravelHour = 24 + (SecondHour - FirstHour);
	}
	else TravelHour = SecondHour - FirstHour;

	if (FirstMinutes > SecondMinutes) {
		TravelMinutes = 60 + (SecondMinutes - FirstMinutes);
		TravelHour = TravelHour - 1;
	}
	else TravelMinutes = (SecondMinutes - FirstMinutes);
	std::cout << "Поездка составила: " << TravelHour << "ч. " << TravelMinutes << "м.";
}
