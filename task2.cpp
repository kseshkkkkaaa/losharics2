#include <iostream>
#include <string>

int main(){
    setlocale(LC_ALL,"RUS");

    int day, month, year;

    std::cout << "¬ведите день, мес€ц и год: ";
    std::cin >> day >> month >> year;

    if (month < 1 || month > 12){
        std::cout << "Ќеправильный мес€ц" << std::endl;
        return 0;
    }
    
    if (year < 1){
        std::cout << "Ќеправильный год" << std::endl;
        return 0;
    }

    int d_in_m;

    if (month == 2){
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
            d_in_m = 29;
        } else{
            d_in_m = 28;
        }
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        d_in_m = 31;
    } else {
        d_in_m = 30;
    }

    if (day < 1 || day > d_in_m){
        std::cout << "Ќеправильный день" << std::endl;
        return 0;
    }

    std::string months[] = {"€нвар€","феврал€","марта","апрел€","ма€","июн€","июл€","августа","сент€бр€","окт€бр€","но€бр€","декабр€"};

    std::cout << day << " " << months[month-1] << " " << year << " года" << std::endl;

    int d_ost = d_in_m - day;
    std::cout << d_ost << std::endl;

    return 0;
}