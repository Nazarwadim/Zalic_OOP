/*
* Створити базовий класс «Рахунок» (поля: номер, прізвище власника, залишок коштів).
* Створити похідні класи «кредитний рахунок»
* (додаткові поля: відсоток за користування кредитом, сума кредиту; метод для розрахунку залишку коштів після сплати відсотків)
* та «депозитний рахунок» (додаткові поля: відсоток за депозитом, сума депозиту;
* метод для розрахунку залишку коштів після нарахування відсотків).
*/
#pragma once
#include <iostream>
using namespace std;

class Rahunok
{
public:
    Rahunok()
    {
        number = 0;
        money_left = 0;
    }

    long int number;
    string surname;
    float money_left;
};
class CreditRahunor : public Rahunok
{
public:
    CreditRahunor()
    {
        percent_for_using_credit = 0;
        credit_sum = 0;
    }
    float calculateRemainingBalance() const
    {
        float interestAmount = credit_sum * (percent_for_using_credit / 100.0);
        return money_left - (credit_sum + interestAmount);
    }

    float percent_for_using_credit;
    float credit_sum;
};

class DepoRah : public Rahunok
{
public:
    DepoRah()
    {
        percent_for_using_depo = 0;
        depo_sum = 0;
    }
    float calculateRemainingBalance() const
    {
        float interestAmount = depo_sum * (percent_for_using_depo / 100.0);
        return money_left + (depo_sum + interestAmount);
    }

    float percent_for_using_depo;
    float depo_sum;
};
int main()
{
    std::cout << "Hello World!\n";
}