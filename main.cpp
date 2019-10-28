 #include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;
 
bool CheckNum(int secretNumber, int userNumber);

bool validNumber(int number);
 
int main()

{
    srand((int)time(NULL));
    int secretNumber = rand() % 9999 + 1024;
    int userNumber;
    int count = 0;
 
    do
    {
        printf ("Введите четырёхзначное числоа: ");
        scanf ("%d", &userNumber);
        count++;   
    } 
	while (!CheckNum(secretNumber, userNumber) && userNumber != 0);
    cout << "Число попыток: " << count << endl;
}
 
bool CheckNum(int secretNumber, int userNumber)
{
    if (!validNumber(userNumber))
    {
        return false;
    }
    if (secretNumber == userNumber)
    {
        printf ("Вы выиграли");
        return true;
    }
 
    int user1000 = userNumber / 1000;
    int user100 = userNumber / 100 % 10;
    int user10 = userNumber / 10 % 10;
    int user1 = userNumber % 10;
    int secret1000 = secretNumber / 1000;
    int secret100 = secretNumber / 100 % 10;
    int secret10 = secretNumber / 10 % 10;
    int secret1 = secretNumber % 10;
    int rightNumbers = 0;
    int absolutNumbers = 0;
 
    if (secret1000 == user1 || secret1000 == user10 || secret1000 == user100 || secret1000 == user1000)
        rightNumbers++;
    if (secret100 == user1 || secret100 == user10 || secret100 == user100 || secret100 == user1000)
        rightNumbers++;
    if (secret10 == user1 || secret10 == user10 || secret10 == user100 || secret10 == user1000)
        rightNumbers++;
    if (secret1 == user1 || secret1 == user10 || secret1 == user100 || secret1 == user1000)
        rightNumbers++;
    if (user1 == secret1)
        absolutNumbers++;
    if (user10 == secret10)
        absolutNumbers++;
    if (user100 == secret100)
        absolutNumbers++;
    if (user1000 == secret1000)
        absolutNumbers++;
 
    cout << "Количество верно угаданных чисел: " << rightNumbers << endl <<
 "Количество чисел, которые находятся на своих местах: " << absolutNumbers << endl;
    return false;
}

bool validNumber(int number)
{
    if (number < 0 || (number > 0 && number < 1000) || number > 9999)
    {
        cout << "В числе НЕ 4 знака" << endl;
        return false;
    }
    return true;
}

